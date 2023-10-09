#include "maingame.h"
#include "ui_maingame.h"
#include <QGridLayout>
#include "sudoku.h"
#include "sudokugenerator.h"
#include "messages_dialog.h"
#include <QFile>
#include <QIODevice>
#include <QDir>
#include <QDateTime>
#include "gameData.h"



mainGame::mainGame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainGame)
{
    ui->setupUi(this);

    selectedBtn = Q_NULLPTR;
    level = 0;
    currentHighlighted = EMPTY_VALUE;
    inputButtons = Q_NULLPTR;

    initializeStyles();
    createGrid();
    beginTimer();

    connect(ui->newGameBtn, SIGNAL(clicked(bool)), this, SLOT(createNewGame()) );
    connect(ui->backBtn, SIGNAL(clicked(bool)), this, SLOT(backBtnClicked()));


}

void mainGame::initializeStyles(){
    QString borderStyle = "border-radius: 25px;"
        "border-style: outset;"
                          "border-width: 2px;"
        "border-color: black;";

    normalStyle = "QPushButton{"
                  "color: rgb(0, 0, 0);"
                  "background-color: rgb(255,255,255);"
                  + borderStyle +
                "}"
                 "QPushButton:hover {"
                    "color: rgb(0, 0, 0);"
                    "background-color: rgb(176, 87, 217);"
                "}";

    emptyStyle = "QPushButton{"
                    "color: rgb(0, 0, 0);"
                    "background-color: rgb(96, 230, 225);"
                 + borderStyle +
                 "}"
                "QPushButton:hover {"
                    "color: rgb(0, 0, 0);"
                    "background-color: rgb(176, 87, 217);"
            "}";

    highlightedStyle = "QPushButton{"
                       "color: rgb(0,0,0);"
                       "background-color: green;"
                       + borderStyle +
                       "}"
                       "QPushButton:hover{"
                       "color: rgb(0, 0, 0);"
                       "background-color: rgb(176, 87, 217);"
                       "}";

}

QFrame *mainGame::createLine(QString type){
    QFrame *Line = new QFrame();
    Line->setFrameShadow(QFrame::Raised);
    Line->setLineWidth(0);
    Line->setMidLineWidth(10);
    Line->setStyleSheet("color: rgb(150, 179, 221); background-color: rgb(150, 179, 221);");
    if(type == "v"){
        Line->setFrameStyle(QFrame::VLine);
        Line->setMinimumWidth(10);
    }else if(type == "h"){
        Line->setMinimumHeight(10);
        Line->setFrameStyle(QFrame::HLine);
    }
    return Line;
}

void mainGame::createGrid(){
    const QSize btnSize = QSize(50, 50);
    QGridLayout *grid = new QGridLayout();


    SudokuGenerator sudokuGame;
    solvedPuzzle = sudokuGame.generateSudoku();

    Sudoku *p = qobject_cast<Sudoku*>( parentWidget());
    level = p->getLevel();

    if(level == 1){
        unSolvedPuzzle = sudokuGame.removeKElements(18);
        blocksToFill = 18;
    }else if(level == 2){
        unSolvedPuzzle = sudokuGame.removeKElements(36);
        blocksToFill = 36;
    }else if(level == 3){
        unSolvedPuzzle = sudokuGame.removeKElements(46);
        blocksToFill = 46;
    }


    int row = 0;
    for(int i=0; i<9; i++){
        int col = 0;
        for(int j=0; j<9; j++){

            button[i][j] = new QPushButton();

            if(unSolvedPuzzle[i][j] != EMPTY_VALUE){
                button[i][j]->setObjectName("btn-"+QString::number(i)+","+QString::number(j));
                button[i][j]->setText(QString::number(unSolvedPuzzle[i][j]));
                button[i][j]->setStyleSheet(normalStyle);
            }else{
                button[i][j]->setObjectName("ebtn-"+QString::number(i)+","+QString::number(j));
                button[i][j]->setText(" ");
                button[i][j]->setStyleSheet(emptyStyle);
                connect(button[i][j], SIGNAL(clicked(bool)), this, SLOT(enableBtn()));
            }
            button[i][j]->setFixedSize(btnSize);
            connect(button[i][j], SIGNAL(clicked(bool)), this, SLOT(highlightNumbers()));


            if(j == 3 || j==6){
                QFrame* vLine = createLine("v");
                grid->addWidget(vLine, row, col, 1, 1);
                col++;
            }
            grid->addWidget(button[i][j], row, col);
            col++;
        }
        row++;
        if(row == 3 || row == 7){
            QFrame *hLine = createLine("h");
            grid->addWidget(hLine, row, 0, 1, 11);
            row++;
        }
    }
    grid->setVerticalSpacing(0);
    grid->setHorizontalSpacing(0);

    ui->horLay->addLayout(grid);

    centralWid = p->centralWidget();
    centralWid->setParent(0);
    centralWid->setVisible(false);


    p->setCentralWidget(this);
}

void mainGame::beginTimer(){

    secondsPassed = 0;
    time = new QTime(0,0,0);
    ui->timeSpent->setDigitCount(8);
    ui->timeSpent->display(time->toString("hh:mm:ss"));

    timer = new QTimer(this);


    connect(timer, SIGNAL(timeout()), this, SLOT(showTimePassed()));
    connect(this, SIGNAL(destroyed()), timer, SLOT(stop()));

    timer->start(1000);

}

bool mainGame::saveDataToFile(QString takenTime){
    QString filename;
    switch(level){
    case 1:
        filename = "easy.dat";
        break;
    case 2:
        filename = "medium.dat";
        break;
    case 3:
        filename = "hard.dat";
        break;
    default:
        return false;
    }

    QString path = QDir::currentPath() + QDir::separator() + "gameData" + QDir::separator() + filename;
    QFile file(path);

    if(!file.open(QIODevice::Append)){
        qDebug() << file.errorString();
        return false;
    }

    QDataStream outStream(&file);
    QDateTime currentDate = QDateTime::currentDateTime();
    QString formattedDate = currentDate.toString("dd.MM.yyyy");
    GameData<QString> data(formattedDate, takenTime);

    outStream << data;


    file.close();

    return true;
}

void mainGame::gameCompletedMessage(){
    QString currentLevel = "";
    switch(level){
    case 1:
        currentLevel = "Easy";
        break;
    case 2:
        currentLevel = "Medium";
        break;
    case 3:
        currentLevel = "Hard";
        break;
    default:
        currentLevel = "";
        return;
    }

    QTime timeTaken = time->addSecs(secondsPassed);

    if(saveDataToFile(QString::number(secondsPassed))){
        QString message = "You Completed The Sudoku Puzzle\n"
                          "Time Taken :: " + timeTaken.toString("hh:mm:ss") + "\n"
                                                             "Level :: " + currentLevel;

        messages_dialog *msg = new messages_dialog(this);
        msg->singleBtnMessage("Game Completed", message);
        msg->setWindowFlags(Qt::FramelessWindowHint);
        msg->setModal(true);
        msg->setAttribute(Qt::WA_DeleteOnClose);

        connect(msg, SIGNAL(destroyed(QObject*)), this, SLOT(backBtnClicked()));

        msg->show();
    }else{
        backBtnClicked();
    }

}

void mainGame::resizeEvent(QResizeEvent *event){
    if(event->type() == QEvent::Resize){
        if(inputButtons != Q_NULLPTR){
            inputButtons->close();
        }
    }
}

void mainGame::enableBtn(){
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QRect btnPos = buttonSender->geometry();
    QString btnId = buttonSender->objectName();

    int n = btnId.length();
    int row = btnId[n-3].digitValue();

    if(inputButtons == Q_NULLPTR){
        inputButtons = new InputBtnWidget(this);
        inputButtons->setAttribute(Qt::WA_DeleteOnClose);
        if(row < 3){
            inputButtons->createAtPosition(DOWN, btnPos);
        }else{
            inputButtons->createAtPosition(UP, btnPos);
        }

        connect(inputButtons, SIGNAL(destroyed(QObject*)), this, SLOT(setNull()));
        inputButtons->show();
    }else{
        inputButtons->close();
    }

    selectedBtn = buttonSender;
}

void mainGame::setNull(){
    inputButtons = Q_NULLPTR;
}

void mainGame::changeBtnValue(int v){
    QString text = QString::number(v);
    QString objName = selectedBtn->objectName();
    int n = objName.length();
    int row = objName[n-3].digitValue();
    int col = objName[n-1].digitValue();

    if(selectedBtn->text() == " "){
        blocksToFill -= 1;
    }
    selectedBtn->setText(text);
    unSolvedPuzzle[row][col] = v;
    if(blocksToFill == 0){
        if(SudokuGenerator::validateSudoku(unSolvedPuzzle)){
            gameCompletedMessage();
        }
    }
}


void mainGame::clearHighlightedNumbers(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
           QString objName = button[i][j]->objectName();
           if(objName.startsWith("e")){
                button[i][j]->setStyleSheet(emptyStyle);
           }else{
                button[i][j]->setStyleSheet(normalStyle);
           }
        }
    }
}

void mainGame::highlightNumbers(){
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    QString bText = buttonSender->text();
    QString objName = buttonSender->objectName();

    if(bText != " " && bText.toInt() != currentHighlighted && !objName.startsWith("e")){
        // Clear Old Higlighted Numbers
        clearHighlightedNumbers();

        // Highlight New Numbers
        for(int i=0; i<9; i++){
           for(int j=0; j<9; j++){

                QString str = button[i][j]->text();
                if(str == bText){
                    button[i][j]->setStyleSheet(highlightedStyle);
                }
                if(!button[i][j]->isEnabled()){
                    button[i][j]->setEnabled(true);
                }
           }
        }
        currentHighlighted = bText.toInt();
    }else if(bText != " " && bText.toInt() == currentHighlighted && !objName.startsWith("e")){
        currentHighlighted = EMPTY_VALUE;
        clearHighlightedNumbers();
    }
    else{
        buttonSender->setStyleSheet(emptyStyle);
    }

}

void mainGame::backBtnClicked()
{
    centralWid->setVisible(true);
    Sudoku *p = qobject_cast<Sudoku*>( parentWidget());
    p->setCentralWidget(centralWid);
    if(!close()){
        qApp->quit();
    }
}

void mainGame::showTimePassed(){
    secondsPassed++;
    QTime t = time->addSecs(secondsPassed);
    ui->timeSpent->display(t.toString("hh:mm:ss"));

}

void mainGame::createNewGame(){
    Sudoku *p = qobject_cast<Sudoku*>( parentWidget());
    p->setCentralWidget(centralWid);
    mainGame *newGame = new mainGame(p);

    if(!close()){
        qApp->quit();
    }

    newGame->show();
}

mainGame::~mainGame()
{
    delete ui;
}


