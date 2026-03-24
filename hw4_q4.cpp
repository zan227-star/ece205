#include <iostream>
#include <string>
using namespace std;

// Display the current board
void displayBoard(char board[]) {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << board[i];
        if ((i + 1) % 3 == 0)
            cout << "\n";
        else
            cout << " |";
    }
    cout << "\n";
}

// Check if a player has won
bool checkWin(char board[], char player) {
    // Rows
    if (board[0]==player && board[1]==player && board[2]==player) return true;
    if (board[3]==player && board[4]==player && board[5]==player) return true;
    if (board[6]==player && board[7]==player && board[8]==player) return true;
    // Columns
    if (board[0]==player && board[3]==player && board[6]==player) return true;
    if (board[1]==player && board[4]==player && board[7]==player) return true;
    if (board[2]==player && board[5]==player && board[8]==player) return true;
    // Diagonals
    if (board[0]==player && board[4]==player && board[8]==player) return true;
    if (board[2]==player && board[4]==player && board[6]==player) return true;
    return false;
}

// Check if the board is full (draw)
bool checkDraw(char board[]) {
    for (int i = 0; i < 9; i++)
        if (board[i] != 'X' && board[i] != 'O')
            return false;
    return true;
}

// Get a valid move from the current player
int getMove(char board[], char player) {
    int pos;
    while (true) {
        cout << "Player " << player << ", enter a position (1-9): ";
        string input;
        getline(cin, input);

        if (input.size() == 1 && isdigit(input[0])) {
            pos = input[0] - '0';
            if (pos < 1 || pos > 9) {
                cout << "Position out of range. Please enter a number between 1 and 9.\n";
            } else if (board[pos - 1] == 'X' || board[pos - 1] == 'O') {
                cout << "Position " << pos << " is already taken. Choose another.\n";
            } else {
                return pos;
            }
        } else {
            cout << "Invalid input. Please enter a single number between 1 and 9.\n";
        }
    }
}

int main() {
    // Initialize board with position numbers 1-9
    char board[9];
    for (int i = 0; i < 9; i++)
        board[i] = '1' + i;

    cout << "===== Tic-Tac-Toe =====\n";
    cout << "Positions are numbered as follows:\n";
    displayBoard(board);

    char currentPlayer = 'X';

    while (true) {
        int pos = getMove(board, currentPlayer);
        board[pos - 1] = currentPlayer;

        displayBoard(board);

        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins! Congratulations!\n";
            break;
        }

        if (checkDraw(board)) {
            cout << "It's a draw! Well played by both!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}