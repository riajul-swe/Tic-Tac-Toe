#include <iostream>
#include <vector>

using namespace std;

// Function to initialize the board
void initializeBoard(vector<char>& board) {
    for (int i = 0; i < 9; ++i) {
        board[i] = ' ';
    }
}

// Function to print the board
void printBoard(const vector<char>& board) {
    cout << "\nTic Tac Toe Board: \n";
    for (int i = 0; i < 9; ++i) {
        cout << " " << board[i] << " ";
        if (i % 3 == 2) cout << "\n";
        else cout << "|";
    }
    cout << endl;
}

// Function to check if a player has won
bool checkWin(const vector<char>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        // Check rows
        if (board[i * 3] == player && board[i * 3 + 1] == player && board[i * 3 + 2] == player) return true;
        // Check columns
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) return true;
    }
    // Check diagonals
    if (board[0] == player && board[4] == player && board[8] == player) return true;
    if (board[2] == player && board[4] == player && board[6] == player) return true;

    return false;
}

// Function to check if the board is full
bool isBoardFull(const vector<char>& board) {
    for (char c : board) {
        if (c == ' ') return false;
    }
    return true;
}

// Function to take player input
bool makeMove(vector<char>& board, int position, char player) {
    if (position < 1 || position > 9 || board[position - 1] != ' ') {
        cout << "Invalid move! Try again.\n";
        return false;
    }
    board[position - 1] = player;
    return true;
}

int main() {
    vector<char> board(9);
    initializeBoard(board);

    char player = 'X';
    int position;
    bool gameWon = false;

    while (!gameWon && !isBoardFull(board)) {
        printBoard(board);
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> position;

        if (makeMove(board, position, player)) {
            gameWon = checkWin(board, player);
            if (!gameWon && !isBoardFull(board)) {
                player = (player == 'X') ? 'O' : 'X'; // Switch player
            }
        }
    }

    printBoard(board);
    if (gameWon) {
        cout << "Player " << player << " wins!\n";
    } else {
        cout << "It's a draw!\n";
    }

    return 0;
}
