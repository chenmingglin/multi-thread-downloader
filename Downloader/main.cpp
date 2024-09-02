#include "downloadermanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DownloaderManager w;
    w.show();
    QObject::connect(&w, &DownloaderManager::manager_error, &a, &QApplication::quit);
    QObject::connect(&w, &DownloaderManager::down_over, &a, &QApplication::quit);
    return a.exec();
}
