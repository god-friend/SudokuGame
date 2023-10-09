/********************************************************************************
** Form generated from reading UI file 'sudoku.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKU_H
#define UI_SUDOKU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Sudoku
{
public:
    QWidget *mainWidget;
    QGridLayout *gridLayout;
    QFrame *verticalFrame;
    QVBoxLayout *verticalLayout;
    QPushButton *startGameBtn;
    QPushButton *diffLevel;
    QPushButton *myScore;
    QPushButton *exitGame;
    QLabel *sTitle;
    QLabel *label_4;
    QLabel *label_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Sudoku)
    {
        if (Sudoku->objectName().isEmpty())
            Sudoku->setObjectName("Sudoku");
        Sudoku->resize(686, 413);
        Sudoku->setAutoFillBackground(false);
        Sudoku->setStyleSheet(QString::fromUtf8("background-color: rgb(154, 153, 150);"));
        mainWidget = new QWidget(Sudoku);
        mainWidget->setObjectName("mainWidget");
        gridLayout = new QGridLayout(mainWidget);
        gridLayout->setObjectName("gridLayout");
        verticalFrame = new QFrame(mainWidget);
        verticalFrame->setObjectName("verticalFrame");
        verticalFrame->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: rgb(0, 0, 0);\n"
"	background-color: rgba(187, 183, 183, 251);\n"
"	border-style: outset;\n"
"	border-width: 2px;\n"
"	border-radius: 20px;\n"
"	border-color: beige;\n"
"	padding: 6px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgb(134, 129, 116);     \n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: rgb(169, 189, 207);     \n"
"}"));
        verticalLayout = new QVBoxLayout(verticalFrame);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(-1, 14, -1, 13);
        startGameBtn = new QPushButton(verticalFrame);
        startGameBtn->setObjectName("startGameBtn");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startGameBtn->sizePolicy().hasHeightForWidth());
        startGameBtn->setSizePolicy(sizePolicy);
        startGameBtn->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        startGameBtn->setFont(font);
        startGameBtn->setAutoFillBackground(false);
        startGameBtn->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(startGameBtn);

        diffLevel = new QPushButton(verticalFrame);
        diffLevel->setObjectName("diffLevel");
        sizePolicy.setHeightForWidth(diffLevel->sizePolicy().hasHeightForWidth());
        diffLevel->setSizePolicy(sizePolicy);
        diffLevel->setMaximumSize(QSize(16777215, 16777215));
        diffLevel->setFont(font);
        diffLevel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(diffLevel);

        myScore = new QPushButton(verticalFrame);
        myScore->setObjectName("myScore");
        sizePolicy.setHeightForWidth(myScore->sizePolicy().hasHeightForWidth());
        myScore->setSizePolicy(sizePolicy);
        myScore->setMaximumSize(QSize(16777215, 16777215));
        myScore->setFont(font);

        verticalLayout->addWidget(myScore);

        exitGame = new QPushButton(verticalFrame);
        exitGame->setObjectName("exitGame");
        sizePolicy.setHeightForWidth(exitGame->sizePolicy().hasHeightForWidth());
        exitGame->setSizePolicy(sizePolicy);
        exitGame->setMaximumSize(QSize(16777215, 16777215));
        exitGame->setFont(font);
        exitGame->setFocusPolicy(Qt::StrongFocus);
        exitGame->setStyleSheet(QString::fromUtf8(""));
        exitGame->setAutoDefault(false);
        exitGame->setFlat(false);

        verticalLayout->addWidget(exitGame);


        gridLayout->addWidget(verticalFrame, 1, 1, 1, 1);

        sTitle = new QLabel(mainWidget);
        sTitle->setObjectName("sTitle");
        sTitle->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Chilanka")});
        font1.setPointSize(36);
        font1.setBold(true);
        sTitle->setFont(font1);
        sTitle->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        sTitle->setLineWidth(1);
        sTitle->setTextFormat(Qt::AutoText);
        sTitle->setScaledContents(false);
        sTitle->setAlignment(Qt::AlignCenter);
        sTitle->setMargin(0);
        sTitle->setIndent(-1);

        gridLayout->addWidget(sTitle, 0, 0, 1, 3);

        label_4 = new QLabel(mainWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 5, 2, 1, 1);

        label_3 = new QLabel(mainWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        Sudoku->setCentralWidget(mainWidget);
        statusBar = new QStatusBar(Sudoku);
        statusBar->setObjectName("statusBar");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Chilanka")});
        font2.setPointSize(18);
        font2.setBold(true);
        statusBar->setFont(font2);
        statusBar->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        Sudoku->setStatusBar(statusBar);

        retranslateUi(Sudoku);
        QObject::connect(exitGame, &QPushButton::clicked, Sudoku, qOverload<>(&QMainWindow::close));

        exitGame->setDefault(false);


        QMetaObject::connectSlotsByName(Sudoku);
    } // setupUi

    void retranslateUi(QMainWindow *Sudoku)
    {
        Sudoku->setWindowTitle(QCoreApplication::translate("Sudoku", "Sudoku", nullptr));
        startGameBtn->setText(QCoreApplication::translate("Sudoku", "Start Game", nullptr));
        diffLevel->setText(QCoreApplication::translate("Sudoku", "Difficulty Level", nullptr));
        myScore->setText(QCoreApplication::translate("Sudoku", "My Score", nullptr));
        exitGame->setText(QCoreApplication::translate("Sudoku", "Exit Game", nullptr));
        sTitle->setText(QCoreApplication::translate("Sudoku", "Sudoku", nullptr));
        label_4->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Sudoku: public Ui_Sudoku {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKU_H
