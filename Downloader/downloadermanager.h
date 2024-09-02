#pragma once
#include "TaskInfo.h"
#include "downworker.h"
#include <QMainWindow>
#include <QUrl>
#include <QSharedPointer>
#include <QList>
#include <QMutex>
#include <QVector>
#include <QFile>
#include <QScopedPointer>
QT_BEGIN_NAMESPACE
namespace Ui {
class DownloaderManager;
}
QT_END_NAMESPACE

class DownloaderManager : public QMainWindow
{
    Q_OBJECT

public:
    DownloaderManager(QWidget *parent = nullptr);
    ~DownloaderManager();

    void new_down();
    void quit_thread();
private:
    void init_ui();
    void down_ok();
signals:
    void manager_error();
    void down_over();
    void stop_sig();
private slots:
    void on_actionNew_triggered();
    void on_start_clicked();

    void recv_progress(int order, double progress);
    void on_cancel_clicked();

    void on_stop_clicked();

private:
    QMutex m_mtx{};
    Ui::DownloaderManager *ui;
    Info m_info {};
    unsigned short max_thread_num {1};
    quint64 m_file_size {};

    double m_recv_ratio{0};
    double m_recv_total {0};
    QList<QSharedPointer<DownWorker>> worker_list {};
    QList<QSharedPointer<QThread>> thread_list {};
    QVector<double> recv_size_list{};
    QVector<double> recv_size_weights{};
    QVector<quint64> m_start_positions {};
    QVector<quint64> m_end_positions {};


    bool is_stop{false};
    QVector<bool> is_sucess {false};

    QFile *m_file {};
    //QScopedPointer<uchar> m_file_map{};
    uchar* file_ptr{};
};
