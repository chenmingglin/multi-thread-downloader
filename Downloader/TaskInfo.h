#pragma once
#include <QUrl>
class Info {
public:
    Info() = default;
    Info(QUrl url, QString path) : url(url), path(path) {};
    Info(const Info& other) : url(other.url), path(other.path) {};
    Info& operator= (const Info& other) = default;

    Info(Info&& other) noexcept : url(std::move(other.url)), path(std::move(other.path)){};
    Info& operator= (Info&& other) noexcept = default;
    QUrl url{};
    QString path{};
};
class task_info {
public:
    task_info() = default;
    task_info(int order, quint64 start, quint64 end, Info info) : order(order), start_pos(start), end_pos(end), info(std::move(info)){};
    task_info(int order, quint64 start, quint64 end, QUrl url, QString path) : order(order), start_pos(start), end_pos(end){
        info.url = std::move(url);
        info.path = std::move(path);
    };
    int order {-1};
    quint64 start_pos {};
    quint64 end_pos {};
    Info info{};
};


