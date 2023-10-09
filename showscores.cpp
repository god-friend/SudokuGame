#include "showscores.h"
#include "ui_showscores.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QDir>
#include <QFile>
#include <QIODevice>
#include "sudoku.h"

// Public Members

showScores::showScores(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showScores)
{
    ui->setupUi(this);
    Sudoku *p = (Sudoku*) parent;

    centralWid = p->centralWidget();
    centralWid->setParent(0);
    centralWid->setVisible(false);


    p->setCentralWidget(this);

    connect(ui->backBtn, SIGNAL(clicked(bool)), this, SLOT(goBack()));

    getAndPrintScores();
}

showScores::~showScores()
{
    delete ui;
}


// Private Slots

void showScores::goBack(){
    centralWid->setVisible(true);
    Sudoku *p = qobject_cast<Sudoku*>( parentWidget());
    p->setCentralWidget(centralWid);

    close();
}


// Private Members

void showScores::getAndPrintScores(){
    std::vector<GameData<QString>> easyScores = readFile("easy.dat");
    showFileContents("easyWid", easyScores);

    std::vector<GameData<QString>> mediumScores = readFile("medium.dat");
    showFileContents("mediumWid", mediumScores);

    std::vector<GameData<QString>> hardScores = readFile("hard.dat");
    showFileContents("hardWid", hardScores);

}

std::vector<GameData<QString>> showScores::readFile(QString filename){
    std::vector<GameData<QString>> allLines;
    GameData<QString> data;

    QString path = QDir::currentPath() + QDir::separator() + "gameData" + QDir::separator() + filename;
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly)){
        qDebug() << file.errorString();
        return {};
    }

    QDataStream readFile(&file);

    while(!readFile.atEnd()){
        readFile >> data;
        allLines.push_back(data);
    }
    file.close();

    return allLines;
}

void showScores::showFileContents(QString widgetName, std::vector<GameData<QString>> data){
    QVBoxLayout *widLayout = new QVBoxLayout();
    int n = data.size();
    int bestTime = INT32_MAX;
    if(n>=1){
        for(int i=0; i<n; i++){
            QTime *time = new QTime(0,0,0);
            QLabel *line = new QLabel();

            QString atDate = data[i].atDate;
            atDate.replace(".", "/");

            int timeTaken = data[i].timeTaken.toInt();
            QTime t = time->addSecs(timeTaken);
            QString timeSpent = t.toString("hh:mm:ss");

            line->setText(QString::number(i+1) + ". " + atDate + " <b>::</b> " + timeSpent);
            line->setStyleSheet("color: rgb(0,0,0); font-size: 20px; font-family: Ubuntu;");

            widLayout->addWidget(line);



            if( timeTaken < bestTime){
                bestTime = timeTaken;
            }
        }
    }else{
        QLabel *line = new QLabel();
        line->setText("You Have not Played any Game on This Level");
        line->setStyleSheet("color: rgb(0,0,0); font-size: 18px; font-family: Chilanka; font-weight: bold;");
        widLayout->addWidget(line);
    }

    widLayout->addStretch();

    if(bestTime == INT32_MAX){
        bestTime = 0;
    }

    QTime *time = new QTime(0,0,0);
    QTime t = time->addSecs(bestTime);
    QString bestTimeString = t.toString("hh:mm:ss");

    if (widgetName == "easyWid"){
        ui->bestEasyTime->setText(bestTimeString);
        ui->easyWid->setLayout(widLayout);
    }
    else if (widgetName == "mediumWid"){
        ui->bestMediumTime->setText(bestTimeString);
        ui->mediumWid->setLayout(widLayout);
    }
    else if (widgetName == "hardWid"){
        ui->bestHardTime->setText(bestTimeString);
        ui->hardWid->setLayout(widLayout);
    }else{
        widLayout->deleteLater();
    }
}
