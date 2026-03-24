#include <iostream>
#include <cctype>
using namespace std;

const int ROWS = 10;
const int COLS = 4;

void displaySeats(char seats[][COLS]) { // Display the current seat chart
    cout << "\nCurrent Seat Chart:\n";
    cout << "    A B C D\n";
    cout << "    -------\n";
    for (int i = 0; i < ROWS; i++) {
        cout << (i + 1);
        if (i + 1 < 10) cout << "   ";
        else             cout << "  ";
        for (int j = 0; j < COLS; j++) {
            cout << seats[i][j];
            if (j < COLS - 1) cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void initSeats(char seats[][COLS]) { // Initialize all seats to A, B, C, D
    char labels[] = {'A', 'B', 'C', 'D'};
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            seats[i][j] = labels[j];
}

bool allSeatsTaken(char seats[][COLS]) { // Check if all seats are taken
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (seats[i][j] != 'X')
                return false;
    return true;
}

int letterToCol(char c) { // Convert seat letter to column index (A=0, B=1, C=2, D=3)
    c = toupper(c);
    if (c == 'A') return 0;
    if (c == 'B') return 1;
    if (c == 'C') return 2;
    if (c == 'D') return 3;
    return -1;
}

bool bookSeat(char seats[][COLS], int row, char colChar) { // Attempt to book a seat
    int col = letterToCol(colChar);

    if (row < 1 || row > ROWS || col == -1) {
        cout << "Invalid seat entry. Row must be 1-10 and column must be A-D.\n";
        return false;
    }

    if (seats[row - 1][col] == 'X') {
        cout << "Seat " << row << colChar << " is already taken. Please choose another.\n";
        return false;
    }

    seats[row - 1][col] = 'X'; // Returns true on success
    cout << "Seat " << row << (char)toupper(colChar) << " has been successfully booked.\n";
    return true;
}

int main() {
    char seats[ROWS][COLS];
    
    initSeats(seats);
    displaySeats(seats);

    char continueChoice = 'y';

    while (continueChoice == 'y' || continueChoice == 'Y') {
        if (allSeatsTaken(seats)) {
            cout << "All seats are taken. No more bookings possible.\n";
            break;
        }

        int row;
        char colChar;
        bool booked = false;

        while (!booked) { // Keep prompting until a valid, available seat is entered
            cout << "Enter desired seat (row 1-10 and column A-D): ";
            cin >> row >> colChar;
            booked = bookSeat(seats, row, colChar);
        }

        displaySeats(seats);

        if (allSeatsTaken(seats)) {
            cout << "All seats are taken!\n";
            break;
        }

        cout << "Would you like to book another seat? (y/n): ";
        cin >> continueChoice;
    }

    cout << "\nFinal Seat Chart:\n";
    displaySeats(seats);

    return 0;
}