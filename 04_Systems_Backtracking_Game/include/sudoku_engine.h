#ifndef __SUDOKU_ENGINE_H 
#define __SUDOKU_ENGINE_H 
 
void printBoard(int** board, int size); 
int** sudokuInitiator(); 
int sudokuCount(int** board, int size); 
bool sudokuChecker(int** board, int size, int row, int col, int value); 
bool completeChecker(int** board, int size); 
void sudokuCleanup(int*** history, int** board, int size); 
void sudokuPlayer(int** board, int size); 
 
#endif 