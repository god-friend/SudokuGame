#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include "sudoku.h"
#include <QTime>
#include <QTimer>
#include <QString>
#include <QDataStream>

namespace Ui {
class mainGame;
}

class mainGame : public QWidget
{
    Q_OBJECT

public:
    explicit mainGame(QWidget *parent = nullptr);
    ~mainGame();

private slots:
    void enableBtn();
    void showBtnClicked();
    void showTimePassed();
    void backBtnClicked();
    void createNewGame();
    void highlightNumbers();


private:
    Ui::mainGame *ui;

    QPushButton *disabledBtn;
    QWidget *centralWid;
    Sudoku *p;
    QTime *time;
    QTimer *timer;
    QPushButton *options[10];
    QPushButton *button[9][9];
    QString emptyStyle;
    QString highlightedStyle;
    QString normalStyle;

    int secondsPassed;
    int blocksToFill;
    bool showBtnsEnabled;
    int currentHighlighted;

    std::vector<std::vector<int>> solvedPuzzle;
    std::vector<std::vector<int>> unSolvedPuzzle;


    QFrame *createLine(QString type);
    void createGrid();
    void showOptions();
    void beginTimer();
    void gameCompletedMessage();
    bool saveDataToFile(QString takenTime);
    void initializeStyles();
    void clearHighlightedNumbers();


};


class GameData{
public:
    QString atDate;
    QString timeTaken;

    GameData(){}
    GameData(QString date, QString time){
        atDate = date;
        timeTaken = time;
    }

    friend QDataStream &operator << (QDataStream &out, GameData data){
        out << data.atDate << data.timeTaken;
        return out;
    }

    friend QDataStream &operator >> (QDataStream &in, GameData &obj){
        in >> obj.atDate >> obj.timeTaken;
        return in;
    }

};

#endif // MAINGAME_H
