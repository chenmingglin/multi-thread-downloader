#pragma once
#include "TaskInfo.h"
#include <QObject>
#include <QNetworkAccessManager>
#include <QScopedPointer>
#include <QMutex>
static QMutex mtx{};
class DownWorker : public QObject
{
    Q_OBJECT
public:
    DownWorker(uchar* fmap,task_info info, QObject *parent = nullptr);
    ~DownWorker();
signals:
    void down_error_sig();
    void error_sig(int error_code, const QString& error_string);
    void finished_sig(int order);
    void down_progress_sig(int order, double progress);
    void stop_down_sig();
    void stop_position_sig(int order, quint64 stop_pos);
public slots:
    void slot_stop();
    void start_down();
private:
    task_info m_task_info {};
    qint64 m_currPos{};
    uchar* m_data {};
};

