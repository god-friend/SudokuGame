/********************************************************************************
** Form generated from reading UI file 'messages_dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGES_DIALOG_H
#define UI_MESSAGES_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_messages_dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *col10Label;
    QPushButton *cancelBtn;
    QPushButton *okBtn;
    QLabel *msgTitle;

    void setupUi(QDialog *messages_dialog)
    {
        if (messages_dialog->objectName().isEmpty())
            messages_dialog->setObjectName("messages_dialog");
        messages_dialog->setEnabled(true);
        messages_dialog->resize(430, 140);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(messages_dialog->sizePolicy().hasHeightForWidth());
        messages_dialog->setSizePolicy(sizePolicy);
        messages_dialog->setMaximumSize(QSize(600, 140));
        messages_dialog->setStyleSheet(QString::fromUtf8("background-color: rgb(228, 197, 197);"));
        gridLayout = new QGridLayout(messages_dialog);
        gridLayout->setObjectName("gridLayout");
        col10Label = new QLabel(messages_dialog);
        col10Label->setObjectName("col10Label");

        gridLayout->addWidget(col10Label, 1, 0, 2, 1);

        cancelBtn = new QPushButton(messages_dialog);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setMaximumSize(QSize(70, 20));
        cancelBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(153, 193, 241);\n"
"	border-radius: 10px;\n"
"	border-style: outset;\n"
"	border-width: 2px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(26, 95, 180);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(220, 138, 221);\n"
"}"));

        gridLayout->addWidget(cancelBtn, 2, 1, 1, 1);

        okBtn = new QPushButton(messages_dialog);
        okBtn->setObjectName("okBtn");
        okBtn->setMaximumSize(QSize(60, 20));
        okBtn->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgb(153, 193, 241);\n"
"	border-radius: 10px;\n"
"	border-style: outset;\n"
"	border-width: 2px;\n"
"}\n"
"QPushButton:hover {\n"
"	background-color: rgb(26, 95, 180);\n"
"}\n"
"QPushButton:pressed {\n"
"	background-color: rgb(220, 138, 221);\n"
"}"));

        gridLayout->addWidget(okBtn, 2, 2, 1, 1);

        msgTitle = new QLabel(messages_dialog);
        msgTitle->setObjectName("msgTitle");
        msgTitle->setMaximumSize(QSize(16777215, 30));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        msgTitle->setFont(font);
        msgTitle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(msgTitle, 0, 0, 1, 3);


        retranslateUi(messages_dialog);
        QObject::connect(cancelBtn, &QPushButton::clicked, messages_dialog, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(messages_dialog);
    } // setupUi

    void retranslateUi(QDialog *messages_dialog)
    {
        messages_dialog->setWindowTitle(QCoreApplication::translate("messages_dialog", "Dialog", nullptr));
        col10Label->setText(QCoreApplication::translate("messages_dialog", "TextLabel", nullptr));
        cancelBtn->setText(QCoreApplication::translate("messages_dialog", "Cancel", nullptr));
        okBtn->setText(QCoreApplication::translate("messages_dialog", "Ok", nullptr));
        msgTitle->setText(QCoreApplication::translate("messages_dialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class messages_dialog: public Ui_messages_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGES_DIALOG_H
