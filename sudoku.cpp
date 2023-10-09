#include "ui_sudoku.h"
#include "selectlevel.h"
#include "maingame.h"
#include "sudoku.h"
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QIODevice>
#include "showscores.h"


// Public Members

Sudoku::Sudoku(QWidget *parent): QMainWindow(parent)
    , ui(new Ui::Sudoku)
{
    ui->setupUi(this);
    level = 1;
    ui->statusBar->showMessage("Difficulty Level :: Easy");

    connect(ui->myScore, SIGNAL(clicked(bool)), this, SLOT(myScoreBtn()));
    connect(ui->diffLevel, SIGNAL(clicked(bool)), this, SLOT(diffLevelClicked()));
    connect(ui->startGameBtn, SIGNAL(clicked(bool)), this, SLOT(startGameBtnClicked()));
    createFiles();
}

Sudoku::~Sudoku()
{
    delete ui;
}

void Sudoku::setVal(int n){
    level = n;
}
int Sudoku::getLevel(){
    return level;
}

// Private Slots

void Sudoku::diffLevelClicked()
{
    selectLevel *s = new selectLevel(this);
    s->setWindowFlags(Qt::FramelessWindowHint);
    s->setModal(true);
    s->setAttribute(Qt::WA_DeleteOnClose);
    connect(s, SIGNAL(destroyed(QObject*)), this ,SLOT(changeStatus()));
    s->show();
}

void Sudoku::changeStatus(){
    QString str = "";
    if(level == 1){
        str = "Easy";
    }else if(level == 2){
        str = "Medium";
    }else if(level == 3){
        str = "Hard";
    }

    ui->statusBar->showMessage("Difficulty Level :: "+str);
}

void Sudoku::startGameBtnClicked()
{
    mainGame *game = new mainGame(this);
    game->setAttribute(Qt::WA_DeleteOnClose);

    game->show();

}

void Sudoku::myScoreBtn(){

    showScores *scoresUI = new showScores(this);
    scoresUI->setAttribute(Qt::WA_DeleteOnClose);
    scoresUI->show();
}

// Private Members

void Sudoku::createFiles(){
    QString path = QDir::currentPath() + QDir::separator() + "gameData";
    QDir dir(path);

    if(!dir.exists()){
        dir.mkpath(".");
    }
    QString filenames[] = {"easy.dat", "medium.dat", "hard.dat"};

    for(int i=0; i<3; i++){
        QString p = path + QDir::separator() + filenames[i];
        QFile file(p);

        if(!file.exists()){
            if(file.open(QIODevice::WriteOnly)){
                file.close();
            }else{
                qDebug() << file.errorString();
            }
        }
    }
}
