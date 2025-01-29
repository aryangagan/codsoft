#include <iostream>
#include <vector>
using namespace std;

// Function to display the game board
void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == '-') return false;
        }
    }
    return true;
}

// Function to handle the Tic-Tac-Toe game
void playTicTacToe() {
    vector<vector<char>> board(3, vector<char>(3, '-'));
    char currentPlayer = 'X';
    bool gameOn = true;

    cout << "Welcome to Tic-Tac-Toe!\n";
    displayBoard(board);

    while (gameOn) {
        int row, col;

        // Get the current player's move
        cout << "Player " << currentPlayer << "'s turn.\n";
        cout << "Enter your move (row and column: 0 1 2): ";
        cin >> row >> col;

        // Validate input
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != '-') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Update the board
        board[row][col] = currentPlayer;
        displayBoard(board);

        // Check for win or draw
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            gameOn = false;
        } else if (checkDraw(board)) {
            cout << "The game is a draw!\n";
            gameOn = false;
        } else {
            // Switch players
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    // Ask to play again
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        playTicTacToe();
    } else {
        cout << "Thanks for playing!\n";
    }
}

int main() {
    playTicTacToe();
    return 0;
}