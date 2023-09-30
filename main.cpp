#include "sudoku.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Sudoku w;
    w.setWindowState(Qt::WindowMaximized);

    w.show();
    return a.exec();
}
