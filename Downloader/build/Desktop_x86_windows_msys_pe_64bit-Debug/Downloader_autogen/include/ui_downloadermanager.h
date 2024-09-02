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
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *file_name;
    QLabel *file_size;
    QSpacerItem *horizontalSpacer;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *recv_size;
    QLineEdit *save_path;
    QLabel *label_3;
    QLabel *speed;
    QLabel *status;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_7;
    QLineEdit *url;
    QProgressBar *progress;
    QWidget *widget_2;
    QLabel *label_8;
    QComboBox *thread_num;
    QWidget *widget_3;
    QPushButton *cancel;
    QPushButton *start;
    QPushButton *stop;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *DownloaderManager)
    {
        if (DownloaderManager->objectName().isEmpty())
            DownloaderManager->setObjectName("DownloaderManager");
        DownloaderManager->resize(800, 600);
        actionNew = new QAction(DownloaderManager);
        actionNew->setObjectName("actionNew");
        actionNew->setCheckable(false);
        actionNew->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(DownloaderManager);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(150, 50, 461, 271));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        file_name = new QLineEdit(widget);
        file_name->setObjectName("file_name");
        file_name->setReadOnly(true);

        gridLayout->addWidget(file_name, 1, 2, 1, 1);

        file_size = new QLabel(widget);
        file_size->setObjectName("file_size");

        gridLayout->addWidget(file_size, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        recv_size = new QLabel(widget);
        recv_size->setObjectName("recv_size");

        gridLayout->addWidget(recv_size, 6, 2, 1, 1);

        save_path = new QLineEdit(widget);
        save_path->setObjectName("save_path");
        save_path->setReadOnly(true);

        gridLayout->addWidget(save_path, 2, 2, 1, 2);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        speed = new QLabel(widget);
        speed->setObjectName("speed");

        gridLayout->addWidget(speed, 7, 2, 1, 1);

        status = new QLabel(widget);
        status->setObjectName("status");

        gridLayout->addWidget(status, 4, 2, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 0, 0, 1, 1);

        url = new QLineEdit(widget);
        url->setObjectName("url");
        url->setReadOnly(true);

        gridLayout->addWidget(url, 0, 2, 1, 2);

        progress = new QProgressBar(centralwidget);
        progress->setObjectName("progress");
        progress->setGeometry(QRect(50, 340, 700, 25));
        progress->setValue(0);
        progress->setTextVisible(false);
        widget_2 = new QWidget(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(510, 0, 100, 50));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 0, 100, 25));
        thread_num = new QComboBox(widget_2);
        thread_num->setObjectName("thread_num");
        thread_num->setGeometry(QRect(0, 25, 100, 25));
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(540, 380, 215, 30));
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
        stop = new QPushButton(centralwidget);
        stop->setObjectName("stop");
        stop->setGeometry(QRect(660, 300, 100, 30));
        stop->setMinimumSize(QSize(100, 30));
        stop->setMaximumSize(QSize(100, 30));
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
        file_size->setText(QCoreApplication::translate("DownloaderManager", "0", nullptr));
        label_5->setText(QCoreApplication::translate("DownloaderManager", "\345\267\262\345\260\206\344\270\213\350\275\275", nullptr));
        label_2->setText(QCoreApplication::translate("DownloaderManager", "\344\277\235\345\255\230\345\234\260\345\235\200", nullptr));
        recv_size->setText(QCoreApplication::translate("DownloaderManager", "0", nullptr));
        label_3->setText(QCoreApplication::translate("DownloaderManager", "\346\230\257\345\220\246\344\270\213\350\275\275", nullptr));
        speed->setText(QCoreApplication::translate("DownloaderManager", "0", nullptr));
        status->setText(QCoreApplication::translate("DownloaderManager", "\346\232\202\345\201\234", nullptr));
        label->setText(QCoreApplication::translate("DownloaderManager", "\346\226\207\344\273\266\345\220\215", nullptr));
        label_6->setText(QCoreApplication::translate("DownloaderManager", "\344\270\213\350\275\275\351\200\237\345\272\246", nullptr));
        label_4->setText(QCoreApplication::translate("DownloaderManager", "\346\226\207\344\273\266\345\244\247\345\260\217", nullptr));
        label_7->setText(QCoreApplication::translate("DownloaderManager", "url", nullptr));
        label_8->setText(QCoreApplication::translate("DownloaderManager", "\346\234\200\345\244\247\347\272\277\347\250\213\346\225\260", nullptr));
        cancel->setText(QCoreApplication::translate("DownloaderManager", "\345\217\226\346\266\210\344\270\213\350\275\275", nullptr));
        start->setText(QCoreApplication::translate("DownloaderManager", "\345\274\200\345\247\213\344\270\213\350\275\275", nullptr));
        stop->setText(QCoreApplication::translate("DownloaderManager", "\346\232\202\345\201\234", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("DownloaderManager", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DownloaderManager: public Ui_DownloaderManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADERMANAGER_H
