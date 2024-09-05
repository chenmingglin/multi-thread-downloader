/********************************************************************************
** Form generated from reading UI file 'downloadermanager.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADERMANAGER_H
#define UI_DOWNLOADERMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DownloaderManager
{
public:
    QAction *actionNew;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QProgressBar *progress;
    QWidget *widget_3;
    QPushButton *cancel;
    QPushButton *start;
    QPushButton *stop;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *speed;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_6;
    QLineEdit *file_name;
    QLineEdit *url;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *file_size;
    QLineEdit *save_path;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *status;
    QSpacerItem *horizontalSpacer;
    QLabel *recv_size;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_8;
    QComboBox *thread_num;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *DownloaderManager)
    {
        if (DownloaderManager->objectName().isEmpty())
            DownloaderManager->setObjectName("DownloaderManager");
        DownloaderManager->resize(800, 600);
        DownloaderManager->setDocumentMode(true);
        actionNew = new QAction(DownloaderManager);
        actionNew->setObjectName("actionNew");
        actionNew->setCheckable(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Img/\346\226\260\345\273\272\347\252\227\345\217\243.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionNew->setIcon(icon);
        actionNew->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(DownloaderManager);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        progress = new QProgressBar(centralwidget);
        progress->setObjectName("progress");
        progress->setValue(0);
        progress->setTextVisible(false);

        gridLayout_2->addWidget(progress, 2, 0, 1, 2);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setMinimumSize(QSize(215, 30));
        widget_3->setMaximumSize(QSize(215, 30));
        cancel = new QPushButton(widget_3);
        cancel->setObjectName("cancel");
        cancel->setGeometry(QRect(115, 0, 100, 30));
        cancel->setMinimumSize(QSize(100, 30));
        cancel->setMaximumSize(QSize(100, 30));
        start = new QPushButton(widget_3);
        start->setObjectName("start");
        start->setGeometry(QRect(0, 0, 100, 30));
        start->setMinimumSize(QSize(100, 30));
        start->setMaximumSize(QSize(100, 30));
        start->setStyleSheet(QString::fromUtf8(""));

        gridLayout_2->addWidget(widget_3, 4, 1, 1, 1);

        stop = new QPushButton(centralwidget);
        stop->setObjectName("stop");
        stop->setMinimumSize(QSize(100, 30));
        stop->setMaximumSize(QSize(100, 30));

        gridLayout_2->addWidget(stop, 1, 1, 1, 1);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        speed = new QLabel(widget);
        speed->setObjectName("speed");

        gridLayout->addWidget(speed, 10, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 7, 0, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 10, 0, 1, 1);

        file_name = new QLineEdit(widget);
        file_name->setObjectName("file_name");
        file_name->setReadOnly(true);

        gridLayout->addWidget(file_name, 1, 2, 1, 1);

        url = new QLineEdit(widget);
        url->setObjectName("url");
        url->setReadOnly(true);

        gridLayout->addWidget(url, 0, 2, 1, 2);

        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 9, 0, 1, 1);

        file_size = new QLabel(widget);
        file_size->setObjectName("file_size");

        gridLayout->addWidget(file_size, 6, 2, 1, 1);

        save_path = new QLineEdit(widget);
        save_path->setObjectName("save_path");
        save_path->setReadOnly(true);

        gridLayout->addWidget(save_path, 2, 2, 1, 2);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        status = new QLabel(widget);
        status->setObjectName("status");

        gridLayout->addWidget(status, 7, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 1, 1);

        recv_size = new QLabel(widget);
        recv_size->setObjectName("recv_size");

        gridLayout->addWidget(recv_size, 9, 2, 1, 1);

        widget_2 = new QWidget(widget);
        widget_2->setObjectName("widget_2");
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setObjectName("horizontalLayout");
        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");
        label_8->setMaximumSize(QSize(83, 19));

        horizontalLayout->addWidget(label_8);

        thread_num = new QComboBox(widget_2);
        thread_num->setObjectName("thread_num");

        horizontalLayout->addWidget(thread_num);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget_2, 5, 2, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 2, 1);

        DownloaderManager->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DownloaderManager);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        DownloaderManager->setMenuBar(menubar);
        statusbar = new QStatusBar(DownloaderManager);
        statusbar->setObjectName("statusbar");
        DownloaderManager->setStatusBar(statusbar);
        toolBar = new QToolBar(DownloaderManager);
        toolBar->setObjectName("toolBar");
        toolBar->setFloatable(true);
        DownloaderManager->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        toolBar->addAction(actionNew);
        toolBar->addSeparator();

        retranslateUi(DownloaderManager);

        QMetaObject::connectSlotsByName(DownloaderManager);
    } // setupUi

    void retranslateUi(QMainWindow *DownloaderManager)
    {
        DownloaderManager->setWindowTitle(QCoreApplication::translate("DownloaderManager", "DownloaderManager", nullptr));
        actionNew->setText(QCoreApplication::translate("DownloaderManager", "New", nullptr));
        cancel->setText(QCoreApplication::translate("DownloaderManager", "\345\217\226\346\266\210\344\270\213\350\275\275", nullptr));
        start->setText(QCoreApplication::translate("DownloaderManager", "\345\274\200\345\247\213\344\270\213\350\275\275", nullptr));
        stop->setText(QCoreApplication::translate("DownloaderManager", "\346\232\202\345\201\234", nullptr));
        speed->setText(QCoreApplication::translate("DownloaderManager", "0", nullptr));
        label->setText(QCoreApplication::translate("DownloaderManager", "\346\226\207\344\273\266\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("DownloaderManager", "\346\230\257\345\220\246\344\270\213\350\275\275", nullptr));
        label_6->setText(QCoreApplication::translate("DownloaderManager", "\344\270\213\350\275\275\351\200\237\345\272\246", nullptr));
        label_7->setText(QCoreApplication::translate("DownloaderManager", "url", nullptr));
        label_5->setText(QCoreApplication::translate("DownloaderManager", "\345\267\262\345\260\206\344\270\213\350\275\275", nullptr));
        file_size->setText(QCoreApplication::translate("DownloaderManager", "0", nullptr));
        label_4->setText(QCoreApplication::translate("DownloaderManager", "\346\226\207\344\273\266\345\244\247\345\260\217", nullptr));
        label_2->setText(QCoreApplication::translate("DownloaderManager", "\344\277\235\345\255\230\345\234\260\345\235\200", nullptr));
        status->setText(QCoreApplication::translate("DownloaderManager", "\346\232\202\345\201\234", nullptr));
        recv_size->setText(QCoreApplication::translate("DownloaderManager", "0", nullptr));
        label_8->setText(QCoreApplication::translate("DownloaderManager", "\346\234\200\345\244\247\347\272\277\347\250\213\346\225\260", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("DownloaderManager", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DownloaderManager: public Ui_DownloaderManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADERMANAGER_H
