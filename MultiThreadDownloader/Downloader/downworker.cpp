#include "downworker.h"
#include <QThread>
#include <QDebug>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QEventLoop>
#include <QFile>
#include <QMessageBox>
#include <QSharedPointer>
DownWorker::DownWorker(task_info info, QObject *parent)
    : QObject{parent}
    , m_task_info(std::move(info))
{}

DownWorker::~DownWorker()
{
    qDebug() << "工作函数析构";
}

void DownWorker::start_down()
{
    QScopedPointer<QNetworkAccessManager> m_manager{new QNetworkAccessManager};
    QNetworkRequest request(m_task_info.info.url);
    request.setRawHeader("Range",QString("bytes=%1-%2").arg(m_task_info.start_pos).arg(m_task_info.end_pos).toUtf8());
    qDebug() << "start:" << m_task_info.start_pos << "end:" <<m_task_info.end_pos;
    QSharedPointer<QNetworkReply> m_reply(m_manager->get(request));

    QEventLoop event_loop;
    connect(m_reply.get(), &QNetworkReply::finished, &event_loop, &QEventLoop::quit);
    connect(m_reply.get(), &QNetworkReply::downloadProgress,[this](qint64 bytes_recv, qint64 bytes_total){
        if(bytes_total > 0) {
            double progress = static_cast<double>(bytes_recv) / static_cast<double>(bytes_total) * 100;
            emit down_progress_sig(m_task_info.order, progress);
        }
    });
    connect(this, &DownWorker::stop_down_sig, this, [&m_reply, this]{
        m_reply->abort();
        m_reply.clear();
    });
    event_loop.exec();


    if(m_reply == nullptr) {
        return;
    }

    if(m_reply->error() != QNetworkReply::NoError) {
        emit error_sig(m_reply->error(), m_reply->errorString());
        return;
    }

    QFile file(m_task_info.info.path);

    {
        QMutexLocker<QMutex> locker(&mtx);
        if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
            emit error_sig(file.error(), file.errorString());
            return;
        } else {
            file.seek(m_task_info.start_pos);
            QByteArray data {};
            while (!m_reply->atEnd()) {
                QByteArray buffer = m_reply->read(1024);
                data.append(buffer);
                file.write(buffer);
            }
            file.close();
            m_currPos = m_task_info.start_pos + data.size();
            emit stop_position_sig(m_task_info.order, m_currPos);
            if(m_currPos >= m_task_info.end_pos) {
                emit finished_sig(m_task_info.order);
            }
        }
    }


}

void DownWorker::slot_stop()
{
    emit stop_down_sig();
}


