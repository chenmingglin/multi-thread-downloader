#include "downloadermanager.h"
#include "./ui_downloadermanager.h"
#include "newtaskdialog.h"
#include "downworker.h"
#include <QThread>
#include <QMessageBox>
#include <QFile>
DownloaderManager::DownloaderManager(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DownloaderManager)
    , recv_size_list(max_thread_num, 0)
    , recv_size_weights(max_thread_num, 0)
    , m_start_positions(max_thread_num, 0)
    , m_end_positions(max_thread_num, 0)
    , is_sucess(max_thread_num, false)
{
    ui->setupUi(this);
    //设置线程数量
    for(int i{0}, j{1}; i < 9; ++i) {
        ui->thread_num->addItem(QString::number(j));
        j <<= 1;
    }
    ui->thread_num->setCurrentIndex(0);
    connect(ui->thread_num, &QComboBox::currentTextChanged, this,[this](const QString& text){
        max_thread_num = text.toUShort();
        recv_size_list.resize(max_thread_num);
        recv_size_weights.resize(max_thread_num);
        m_start_positions.resize(max_thread_num);
        m_end_positions.resize(max_thread_num);
        is_sucess.resize(max_thread_num, false);

        qDebug() << "list.length" << recv_size_list.length();
        qDebug() << "threadNum:max_thread_num:" << max_thread_num;
    });
    if(recv_size_list.length() != recv_size_weights.length()) {
        QMessageBox::warning(nullptr, tr("错误"), tr("程序错误"), QMessageBox::Ok);
        emit manager_error();
    }

}

DownloaderManager::~DownloaderManager()
{
    delete ui;
    for (const auto& thread : thread_list) {
        if(!thread.isNull()) {
            thread->quit();
            thread->wait();
        }
    }
}

void DownloaderManager::new_down()
{
    qDebug() << "主线程：" << QThread::currentThreadId();
    qDebug() << "start__pos" << m_recv_total;

    QFile *file = new QFile(m_info.path);
    m_file = file;
    if(!m_file->open(QIODevice::ReadWrite)) {
        qDebug() << "写入文件打开失败" << m_file->errorString();
        return;
    }

    m_file->resize(m_file_size);
    file_ptr = m_file->map(0, m_file->size());
    qDebug() << "m_file_size" << m_file_size;
    if(file_ptr == nullptr) {
        qDebug() << "文件映射打开失败";
        return;
    }
    qDebug() << "addr:" << file_ptr;
    quint64 bytesper_thread = m_file_size / max_thread_num;
    for(int i {}; i < max_thread_num; ++i) {
        quint64 start {i * bytesper_thread};
        quint64 end {(i + 1) * bytesper_thread - 1};

        if(i == max_thread_num - 1) {
            end = m_file_size - 1;
        }

        if(m_start_positions.at(i) > 0) {
            start = m_start_positions.at(i);
        }

        m_end_positions[i] = end;
        recv_size_weights[i] = static_cast<double>(end - start + 1) / static_cast<double>(m_file_size);

        QSharedPointer<QThread> thread {new QThread};
        task_info info(i, start, end, m_info);
        QSharedPointer<DownWorker> worker{new DownWorker(file_ptr, info)};

        worker->moveToThread(thread.data());
        connect(thread.data(), &QThread::started, worker.data(), &DownWorker::start_down);
        connect(worker.data(), &DownWorker::error_sig, this, [this](int code, const QString& errora_string){
            qDebug() << "code:" << code << "errorString:" << errora_string;
            quit_thread();
            init_ui();
        });
        connect(worker.data(), &DownWorker::down_progress_sig, this, &DownloaderManager::recv_progress);
        connect(this, &DownloaderManager::stop_sig, worker.data(), &DownWorker::slot_stop);
        connect(worker.data(), &DownWorker::stop_position_sig, this, [this](int order, quint64 pos){
            m_start_positions[order] = pos;
        });

        thread_list.append(thread);
        worker_list.append(worker);
    }
    qDebug() << "wight" << recv_size_weights;

    for (const auto& thread : thread_list) {
        thread->start();
    }
}

void DownloaderManager::quit_thread()
{
    for (const auto& thread : thread_list) {
        if(!thread.isNull()) {
            thread->quit();
            thread->wait();
        }
    }
    thread_list.clear();
    worker_list.clear();
    qDebug() << "thread:" << worker_list.length();
    qDebug() << "worker:" << worker_list.length();
}

void DownloaderManager::init_ui()
{
    ui->url->setText(nullptr);
    ui->file_name->setText(nullptr);
    ui->file_size->setText("0");
    ui->recv_size->setText("0");
    ui->save_path->setText(nullptr);
    ui->status->setText("暂停");
    ui->progress->setValue(0);
}

void DownloaderManager::down_ok()
{
    auto flag = [this]()->bool {
        bool flg = true;
        for(const auto& t : is_sucess) {
            flg = flg && t;
        }
        return flg;
    };

    if(flag()) {
        is_sucess.resize(max_thread_num, false);
        QMetaObject::invokeMethod(ui->recv_size, "setText", Qt::QueuedConnection, Q_ARG(QString, QString::number(static_cast<int>(m_file_size))));
        QMetaObject::invokeMethod(ui->progress, "setValue", Qt::QueuedConnection, Q_ARG(int, 100));
        QMetaObject::invokeMethod(ui->status, "setText", Qt::QueuedConnection, Q_ARG(QString, "下载完成"));
        QMessageBox::information(nullptr, tr("成功"), tr("下载完成!!!"), QMessageBox::Ok);
        emit down_over();
    }
}



void DownloaderManager::on_actionNew_triggered()
{
    NewTaskDialog dlg(this);
    if(dlg.exec() == QDialog::Accepted) {
        m_info.url = dlg.get_url();
        m_info.path = dlg.get_path();
        m_file_size = dlg.get_file_size();
        ui->url->setText(dlg.get_url().toString());
        ui->file_name->setText(dlg.get_file_name());
        ui->file_size->setText(QString::number(dlg.get_file_size()));
        ui->save_path->setText(dlg.get_path());
    } else {
        init_ui();
    }
}


void DownloaderManager::on_start_clicked()
{
    is_stop = false;
    if(ui->url->text().isEmpty()) {
        QMessageBox::warning(nullptr, tr("错误"), tr("无效Url"), QMessageBox::Ok);
        return;
    } else{
        new_down();
        ui->status->setText("正在下载");
    }
}

void DownloaderManager::recv_progress(int order, double progress)
{
    {
        QMutexLocker<QMutex> locker(&m_mtx);
        m_recv_ratio = 0;
        recv_size_list[order] = progress;
        for(int i = 0; i < recv_size_list.length(); ++i) {
            m_recv_ratio += recv_size_list.at(i) * recv_size_weights.at(i);
        }
        double recv_total = m_recv_total + m_recv_ratio;

        if(static_cast<int>(progress) == 100) {
            is_sucess[order] = true;
            down_ok();
        }
        QMetaObject::invokeMethod(ui->recv_size, "setText", Qt::QueuedConnection, Q_ARG(QString, QString::number(static_cast<int>(recv_total / 100 * m_file_size))));
        QMetaObject::invokeMethod(ui->progress, "setValue", Qt::QueuedConnection, Q_ARG(int, static_cast<int>(recv_total)));

        if(is_stop) {
            is_stop = false;
            m_recv_total = recv_total;
        }

    }
}


void DownloaderManager::on_cancel_clicked()
{
    quit_thread();
    QFile remove_file(m_info.path);
    if(remove_file.exists()) {
        if(!remove_file.remove()) {
            qDebug() << "文件删除失败!!" << remove_file.errorString();
        }
    }
    init_ui();
}


void DownloaderManager::on_stop_clicked()
{
    is_stop = true;
    quit_thread();
    emit stop_sig();
    ui->status->setText("暂停");
}

