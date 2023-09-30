#ifndef SUDOKU_H
#define SUDOKU_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Sudoku; }
QT_END_NAMESPACE

class Sudoku : public QMainWindow
{
    Q_OBJECT

public:
    Sudoku(QWidget *parent = nullptr);
    ~Sudoku();
    void setVal(int n);
    int getLevel();

private slots:
    void diffLevelClicked();
    void changeStatus();
    void startGameBtnClicked();
    void myScoreBtn();

private:
    Ui::Sudoku *ui;
    int level;

    void createFiles();
};
#endif // SUDOKU_H
