#ifndef SUDOKUGENERATOR_H
#define SUDOKUGENERATOR_H


#include <vector>

#define BOARD_SIZE 9
#define EMPTY_VALUE 0

class SudokuGenerator
{
public:
    SudokuGenerator();
    std::vector<std::vector<int>> generateSudoku();
    std::vector<std::vector<int>> removeKElements(int k);
    static bool validateSudoku(std::vector<std::vector<int>> board);
private:
    std::vector<std::vector<int>> sudokuBoard;
    std::vector<int> values;

    bool valueUsedInBox(int row, int col, int val);
    void fillDiagnols();
    void fillBox(int row, int col);

    bool solveSudoku(std::vector<std::vector<int>> &board);
    bool isSafe(int row, int col, int val, std::vector<std::vector<int>> board);
    static bool notInRow(std::vector<std::vector<int>> board);
    static bool notInCol(std::vector<std::vector<int>> board);
    static bool checkBox(int row, int col, std::vector<std::vector<int>> board);
    static bool notInBox(std::vector<std::vector<int>> board);
};

#endif // SUDOKUGENERATOR_H
