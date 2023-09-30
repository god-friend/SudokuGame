#include "sudokugenerator.h"
#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>
#include <unordered_set>

SudokuGenerator::SudokuGenerator()
{
    sudokuBoard = std::vector(BOARD_SIZE, std::vector<int>(BOARD_SIZE, EMPTY_VALUE));
    values = {1,2,3,4,5,6,7,8,9};
}

std::vector<std::vector<int>> SudokuGenerator::generateSudoku(){
    fillDiagnols();
    solveSudoku(sudokuBoard);

    return sudokuBoard;

}

bool SudokuGenerator::valueUsedInBox(int row, int col, int val){

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(sudokuBoard[row+i][col+j] == val){
                return true;
            }
        }
    }
    return false;
}

void SudokuGenerator::fillBox(int row, int col){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(values.begin(), values.end(), std::default_random_engine(seed));

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){

            for(auto val: values){
                if(!valueUsedInBox(row, col, val)){
                    sudokuBoard[row+i][col+j] = val;
                    break;
                }
            }
        }
    }

}

void SudokuGenerator::fillDiagnols(){

    for(int i=0; i<9; i+=3){
        fillBox(i, i);
    }

}

bool SudokuGenerator::isSafe(int row, int col, int val, std::vector<std::vector<int>> board){

    for(int i=0; i<9; i++){
        if(board[row][i] == val) return false;
        if(board[i][col] == val) return false;

        int r = 3 * (row / 3) + i / 3;
        int c = 3 * (col / 3) + i % 3;
        if(board[r][c] == val) return false;

    }
    return true;
}

bool SudokuGenerator::solveSudoku(std::vector<std::vector<int>> &board){


    for(int row=0; row<BOARD_SIZE; row++){
        for(int col=0; col<BOARD_SIZE; col++){
            if(board[row][col] == EMPTY_VALUE){

                for(int val=1; val<=9; val++){
                    if(isSafe(row, col, val, board)){
                        board[row][col] = val;

                        if(solveSudoku(board)){
                            return true;
                        }else
                            board[row][col] = EMPTY_VALUE;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool SudokuGenerator::notInRow(std::vector<std::vector<int>> board){

    for(int row=0; row<9; row++){
        std::vector<bool> nums(10, false);

        for(int col=0; col<9; col++){
            int n = board[row][col];
            if(nums[n] == true){
                return false;
            }

            nums[n] = true;
        }
    }

    return true;
}

bool SudokuGenerator::notInCol(std::vector<std::vector<int>> board){

    for(int col=0; col<9; col++){
        std::vector<bool> nums(10, false);

        for(int row=0; row<9; row++){
            int n = board[row][col];
            if(nums[n] == true){
                return false;
            }

            nums[n] = true;
        }
    }

    return true;
}

bool SudokuGenerator::checkBox(int row, int col, std::vector<std::vector<int>> board){
    std::vector<bool> nums(10, false);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int n = board[row+i][col+j];
            if(nums[n] == true){
                return false;
            }

            nums[n] = true;
        }
    }
    return true;
}

bool SudokuGenerator::notInBox(std::vector<std::vector<int>> board){

    for(int row=0; row<9; row+=3){

        for(int col=0; col<9; col+=3){
            if(!checkBox(row, col, board)){
                return false;
            }
        }
    }

    return true;
}

bool SudokuGenerator::validateSudoku(std::vector<std::vector<int>> board){
    return  notInRow(board) && notInCol(board) && notInBox(board);
}


std::vector<std::vector<int>> SudokuGenerator::removeKElements(int k){
    std::vector<std::vector<int>> newPuzzle = sudokuBoard;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::srand(seed);

    int i = 0;
    while(i < k){
        int r = rand() % 9;
        int c = rand() % 9;
        if(newPuzzle[r][c] != EMPTY_VALUE){
            newPuzzle[r][c] = EMPTY_VALUE;
            i++;
        }
    }


    return newPuzzle;
}



