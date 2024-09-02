#include "newtaskdialog.h"
#include "ui_newtaskdialog.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QFileInfo>
#include <QStandardPaths>
#include <QFileDialog>
#include <QScopedPointer>
#include <QMessageBox>
NewTaskDialog::NewTaskDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewTaskDialog)
{
    ui->setupUi(this);
    m_path = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation) + "/";
    ui->path->addItem(m_path);
    connect(ui->path, &QComboBox::currentTextChanged, this,[this](const QString& text){
        m_path= text + "/";
    });
}

NewTaskDialog::~NewTaskDialog()
{
    delete ui;
}

QUrl NewTaskDialog::get_url() const
{
    return m_url;
}

QString NewTaskDialog::get_path() const
{
    return m_path;
}

QString NewTaskDialog::get_file_name() const
{
    return m_file_name;
}

quint64 NewTaskDialog::get_file_size() const
{
    return m_file_size;
}

void NewTaskDialog::on_selectBtn_clicked()
{

    m_path = QFileDialog::getExistingDirectory(
        nullptr,
        tr("Save File Path"),
        QDir::homePath(),
        QFileDialog::ShowDirsOnly
    );
    ui->path->addItem(m_path);
    ui->path->setCurrentText(m_path);
}


void NewTaskDialog::on_buttonBox_accepted()
{
    set_file_name_and_size();
}

void NewTaskDialog::init()
{
    m_url = "";
    m_path = "";
    m_file_name = "";
    m_file_size = 0;
}

void NewTaskDialog::set_file_name_and_size()
{
    m_url = ui->url->text();
    if(m_url.isEmpty()) {
        QMessageBox::warning(nullptr, tr("错误"), tr("无效Url"), QMessageBox::Ok);
        init();
        return;
    }
    QScopedPointer<QNetworkAccessManager> net_manager {new QNetworkAccessManager()};
    QNetworkRequest request(m_url);
    QScopedPointer<QNetworkReply>net_reply {net_manager->head(request)};

    QEventLoop event_loop;

    connect(net_reply.get(), &QNetworkReply::finished, &event_loop, &QEventLoop::quit);
    event_loop.exec();

    if(net_reply->error() != QNetworkReply::NoError) {
        QMessageBox::warning(nullptr, tr("错误"), tr("连接服务器错误:") + net_reply->errorString(), QMessageBox::Ok);
        init();
        return;
    } else {
        QVariant var_content_type = net_reply->header(QNetworkRequest::ContentTypeHeader);
        QVariant var_content_length = net_reply->header(QNetworkRequest::ContentLengthHeader);
        if(var_content_type.isValid()) {
            QString type{var_content_type.toString()};
            QString new_type = get_file_extension_from_content_type(type);
            if(QFileInfo fileInfo(m_url.toString()); new_type.isEmpty()) {
                m_file_name = fileInfo.fileName();
            } else {
                m_file_name = fileInfo.baseName() + ".";
                m_file_name += new_type;
            }
            qDebug() << "name:" << m_file_name;
        }

        if(var_content_length.isValid()) {
            m_file_size = var_content_length.toULongLong();
            qDebug() << "size:" << m_file_size;
        }
    }
    m_path += m_file_name;
    qDebug () << "path:" << m_path;
}

QString &NewTaskDialog::get_file_extension_from_content_type(QString &type)
{
    static const QMap<QString, QString> type_to_extension_map = {
        {"text/plain", "txt"},
        {"application/pdf", "pdf"},
        {"image/jpeg", "jpg"},
        {"image/png", "png"},
        {"image/gif", "gif"},
        {"application/msword", "doc"},
        {"application/vnd.openxmlformats-officedocument.wordprocessingml.document", "docx"},
        {"application/vnd.ms-excel", "xls"},
        {"application/vnd.openxmlformats-officedocument.spreadsheetml.sheet", "xlsx"},
        {"application/vnd.ms-powerpoint", "ppt"},
        {"application/vnd.openxmlformats-officedocument.presentationml.presentation", "pptx"},
        {"application/x-zip-compressed", "zip"},
        {"application/zip", "zip"},
        //{"application/octet-stream", "bin"},
        {"audio/mpeg", "mp3"},
        {"video/mp4", "mp4"},
        {"audio/mpeg", "mp3"},
        {"audio/wav", "wav"},
        {"audio/aac", "aac"},
        {"audio/flac", "flac"},
        {"video/x-matroska", "mkv"},
        {"video/webm", "webm"},
        {"video/quicktime", "mov"},
        {"video/x-msvideo", "avi"},
        {"application/json", "json"},
        {"application/xml", "xml"},
        {"text/html", "html"},
        {"text/css", "css"},
        {"text/csv", "csv"},
        {"application/javascript", "js"},
        {"text/markdown", "md"}
    };

    auto it = type_to_extension_map.find(type);
    if(it != type_to_extension_map.end()) {
        type = it.value();
        return type;
    }
    else {
        type = "";
        return type;
    }
}

