#include "sudoku_engine.h" 
int main() { 
    int size = 9; 
    int** board = sudokuInitiator(); 
    sudokuPlayer(board, size); 
}