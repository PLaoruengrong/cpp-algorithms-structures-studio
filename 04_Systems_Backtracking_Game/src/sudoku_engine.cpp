void printBoard(int** board, int size) { 
    cout << "Current Sudoku Board:" << endl; 
    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) { 
            if (board[i][j] == 0) cout << "x "; 
            else cout << board[i][j] << " "; 
            if (j == 2 || j == 5) cout << "| "; 
        } 
        cout << endl; 
        if (i == 2 || i == 5) { 
            for (int j = 0; j < size+2; j ++) { 
                cout << "--"; 
            } 
            cout << endl; 
        } 
    } 
} 
 
// Function to initialize the Sudoku board 
int** sudokuInitiator() { 
    int size = 9; 
    int** board = new int*[size]; // Initialize a 9x9 board with 0s 
    for (int i = 0; i < size; i++) { 
        board[i] = new int[size]; 
        for (int j = 0; j < size; j++) { 
            board[i][j] = 0; 
        } 
    } 
    cout << "Enter the initial values for the Sudoku board (row, col, value). Enter -1 to stop:" << endl; 
    while (true) { 
        int row, col, value; 
        cout << "Enter row (1-9), column (1-9), and value (1-9): "; 
        cin >> row; 
        if (row == -1) break; 
        cin >> col >> value; 
        if (row < 1 || row > size || col < 1 || col > size || value < 1 || value > size) { 
            cout << "Invalid input. Try again." << endl; 
            continue; 
        } 
        board[row - 1][col - 1] = value; 
        printBoard(board, size); 
    } 
    return board; 
} 
 
int sudokuCount(int** board, int size) { 
    int count = 0; 
    for (int i = 0; i < size; i++) { 
        for (int j=0; j< size; j++) { 
            if (board[i][j] != 0) count +=1; 
        } 
    } 
    return count; 
} 
 
// Function to check if a move is valid 
bool sudokuChecker(int** board, int size, int row, int col, int value) { 
    // Check row and column 
    for (int i = 0; i < size; i++) { 
        if (board[row-1][i] == value || board[i][col-1] == value) return false; 
    } 
    // Check 3x3 subgrid 
    int startRow = (row / 3) * 3, startCol = (col / 3) * 3; 
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            if (board[startRow + i][startCol + j] == value) return false; 
        } 
    } 
    return true; 
} 
 
bool completeChecker(int** board, int size) { 
    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) { 
            if (board[i][j] == 0) { 
                return false; 
            } 
        } 
    } 
    return true; 
} 
 
void sudokuCleanup(int*** history, int** board, int size) { 
    for (int i =0; i< size; i++) { 
        delete[] board[i]; 
        for (int j=0; j < size; j++) { 
            delete[] history[i][j]; 
        } 
        delete[] history[i]; 
    } 
    delete[] history; 
} 
 
// Function to allow the player to play Sudoku 
void sudokuPlayer(int** board, int size) { 
    int init_val_ct = sudokuCount(board, size); 
    int*** history = new int**[size*size-init_val_ct]; // Stack to store board states for backtracking 
    int ind = 0; 
    history[ind] = board; // add initial state 
    ind ++; 
 
    while (true) { 
        printBoard(board, size); 
        cout << "Options: " << endl; 
        cout << "1. Make a move" << endl; 
        cout << "2. Backtrack" << endl; 
        cout << "3. Quit" << endl; 
        int choice; 
        cin >> choice; 
        if (choice == 1) { // Make a move 
            int row, col, value; 
            cout << "Enter row (1-9), column (1-9), and value (1-9): "; 
            cin >> row >> col >> value; 
            if (row < 1 || row > size || col < 1 || col > size || value < 1 || value > size) { 
                cout << "Invalid input. Try again." << endl; 
                continue; 
            } 
            if (board[row - 1][col - 1] != 0) { 
                cout << "Cell already filled. Try again." << endl; 
                continue; 
            } 
            if (!sudokuChecker(board, size, row , col , value)) { 
                cout << "Invalid move. Try again." << endl; 
                continue; 
            } 
            board[row - 1][col - 1] = value; 
            int** temp_board = new int*[size]; 
            for (int i = 0; i < size; i++) { 
                temp_board[i] = new int[size]; 
                for (int j = 0; j < size; j++) { 
                    temp_board[i][j] = board[i][j]; 
                } 
            } 
             
            history[ind] = temp_board; 
            ind ++; 
            cout << "Move accepted." << endl; 
 
            // Check if board is completely filled 
            if (completeChecker(board, size)) { 
                cout << "Congratulations! You completed the Sudoku puzzle!" << endl; 
                sudokuCleanup(history, board, size); 
                break; 
            } 
        } else if (choice == 2) { // Backtrack 
            int steps; 
            while(true) { 
                cout << "How many steps to backtrack? "; 
                cin >> steps; 
                if (steps <= ind && steps > 0) break;  
                else cout << "Invalid number of steps" << endl; 
            } 
             
            board = history[ind-steps]; 
            ind = (ind-steps)+1; 
            cout << "Backtracked to a previous state." << endl; 
        } else if (choice == 3) { // Quit 
            cout << "Thanks for playing!" << endl; 
            sudokuCleanup(history, board, size); 
            break; 
        } else { 
            cout << "Invalid choice. Try again." << endl; 
        } 
    } 
}