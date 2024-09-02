/********************************************************************************
** Form generated from reading UI file 'newtaskdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTASKDIALOG_H
#define UI_NEWTASKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewTaskDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *url;
    QLabel *label_2;
    QComboBox *path;
    QToolButton *selectBtn;

    void setupUi(QDialog *NewTaskDialog)
    {
        if (NewTaskDialog->objectName().isEmpty())
            NewTaskDialog->setObjectName("NewTaskDialog");
        NewTaskDialog->resize(550, 207);
        buttonBox = new QDialogButtonBox(NewTaskDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(150, 160, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        widget = new QWidget(NewTaskDialog);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(60, 20, 431, 121));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        url = new QLineEdit(widget);
        url->setObjectName("url");

        gridLayout->addWidget(url, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        path = new QComboBox(widget);
        path->setObjectName("path");

        gridLayout->addWidget(path, 1, 1, 1, 1);

        selectBtn = new QToolButton(widget);
        selectBtn->setObjectName("selectBtn");

        gridLayout->addWidget(selectBtn, 1, 2, 1, 1);


        retranslateUi(NewTaskDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, NewTaskDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, NewTaskDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(NewTaskDialog);
    } // setupUi

    void retranslateUi(QDialog *NewTaskDialog)
    {
        NewTaskDialog->setWindowTitle(QCoreApplication::translate("NewTaskDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("NewTaskDialog", "url", nullptr));
        label_2->setText(QCoreApplication::translate("NewTaskDialog", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        selectBtn->setText(QCoreApplication::translate("NewTaskDialog", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewTaskDialog: public Ui_NewTaskDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTASKDIALOG_H
