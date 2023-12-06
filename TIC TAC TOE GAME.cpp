#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
int printBoard(const vector<vector<char> >& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------" << endl;
        }
    }
    cout << endl;
}

// Function to check if the current player has won
bool checkWin(const vector<vector<char> >& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true; // Check rows
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true; // Check columns
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true; // Check diagonal from top-left to bottom-right
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true; // Check diagonal from top-right to bottom-left
    }
    return false;
}

// Function to check if the board is full, indicating a draw
bool checkDraw(const vector<vector<char> >& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // There is an empty space, the game is not a draw
            }
        }
    }
    return true; // All spaces are filled, indicating a draw
}

// Function to play the Tic-Tac-Toe game
void playTicTacToe() {
    vector<vector<char> > board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        printBoard(board);

        // Get player move
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }

        // Check for a draw
        if (checkDraw(board)) {
            printBoard(board);
            cout << "The game is a draw." << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    while (true) {
        playTicTacToe();

        // Ask if the players want to play again
        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
    }

    return 0;
}
