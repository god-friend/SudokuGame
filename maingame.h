#ifndef MAINGAME_H
#define MAINGAME_H

#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QTime>
#include <QTimer>
#include <QString>
#include <QResizeEvent>
#include "inputbtnwidget.h"

namespace Ui {
class mainGame;
}

class mainGame : public QWidget
{
    Q_OBJECT

public:
    explicit mainGame(QWidget *parent = nullptr);
    ~mainGame();

    void changeBtnValue(int v);

private slots:
    void enableBtn();
    void showTimePassed();
    void backBtnClicked();
    void createNewGame();
    void highlightNumbers();
    void setNull();

private:
    Ui::mainGame *ui;

    QPushButton *selectedBtn;
    QPushButton *options[10];
    QPushButton *button[9][9];

    QWidget *centralWid;

    QTime *time;
    QTimer *timer;

    QString emptyStyle;
    QString highlightedStyle;
    QString normalStyle;

    int secondsPassed;
    int blocksToFill;
    int currentHighlighted;
    int level;

    InputBtnWidget *inputButtons;

    std::vector<std::vector<int>> solvedPuzzle;
    std::vector<std::vector<int>> unSolvedPuzzle;


    QFrame *createLine(QString type);

    void createGrid();
    void beginTimer();
    void gameCompletedMessage();
    void initializeStyles();
    void clearHighlightedNumbers();
    void resizeEvent(QResizeEvent *event);

    bool saveDataToFile(QString takenTime);


};




#endif // MAINGAME_H
