#include <iostream>
#include <vector>
using namespace std;

// Collect characters from user until '0' is entered
void getInput(vector<char>& myVector) {
    char input;
    cout << "Enter characters one at a time (enter '0' to stop):" << endl;
    while (true) {
        cout << "> ";
        cin >> input;
        if (input == '0') break;
        myVector.push_back(input);
    }
}

// Delete any repeated characters, shifting remaining elements down
void deleteRepeatedChars(vector<char>& myVector) {
    for (int i = 0; i < (int)myVector.size(); i++) {
        for (int j = i + 1; j < (int)myVector.size(); ) {
            if (myVector[j] == myVector[i]) {
                // Shift all elements after j down by 1
                for (int k = j; k < (int)myVector.size() - 1; k++) {
                    myVector[k] = myVector[k + 1];
                }
                myVector.pop_back(); // Remove the last (now duplicate) element
            } else {
                j++;
            }
        }
    }
}

// Sort vector in decreasing order (z to a) using selection sort
void selectionSort(vector<char>& myVector) {
    int n = myVector.size();
    for (int i = 0; i < n - 1; i++) {
        // Find the maximum character in the remaining unsorted portion
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (myVector[j] > myVector[maxIndex]) {
                maxIndex = j;
            }
        }
        // Swap the found maximum with the first element of unsorted portion
        if (maxIndex != i) {
            char temp = myVector[i];
            myVector[i] = myVector[maxIndex];
            myVector[maxIndex] = temp;
        }
    }
}

// Print all characters in the vector
void printVector(const vector<char>& myVector) {
    if (myVector.empty()) {
        cout << "(empty)" << endl;
        return;
    }
    for (int i = 0; i < (int)myVector.size(); i++) {
        cout << "[" << i << "]: " << myVector[i] << endl;
    }
}

int main() {
    vector<char> myVector;

    getInput(myVector);

    cout << "\nOriginal input:" << endl;
    printVector(myVector);

    deleteRepeatedChars(myVector);
    cout << "\nAfter removing duplicates:" << endl;
    printVector(myVector);

    selectionSort(myVector);
    cout << "\nAfter sorting (z to a):" << endl;
    printVector(myVector);

    return 0;
}