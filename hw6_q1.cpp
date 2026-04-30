#include <iostream>
#include <vector>
using namespace std;

// Collect integers from user until a negative number is entered
void getInput(vector<int>& numbers) {
    int input;
    cout << "Enter integers (enter a negative number to stop):" << endl;
    while (true) {
        cout << "> ";
        cin >> input;
        if (input < 0) break;
        numbers.push_back(input);
    }
}

// Determine how many bins we need based on the largest value
int getNumBins(const vector<int>& numbers) {
    if (numbers.empty()) return 0;
    int maxVal = numbers[0];
    for (int n : numbers)
        if (n > maxVal) maxVal = n;
    return (maxVal / 10) + 1;
}

// Count how many numbers fall into each bin
void buildHistogram(const vector<int>& numbers, vector<int>& bins) {
    for (int n : numbers) {
        int binIndex = n / 10;
        // Expand bins vector if needed
        while (binIndex >= (int)bins.size())
            bins.push_back(0);
        bins[binIndex]++;
    }
}

// Print the histogram to the console
void printHistogram(const vector<int>& bins) {
    cout << "\n--- Histogram ---" << endl;
    if (bins.empty()) {
        cout << "No data to display." << endl;
        return;
    }
    for (int i = 0; i < (int)bins.size(); i++) {
        int low  = i * 10;
        int high = low + 9;
        cout << "Bin [" << low << " - " << high << "]: " << bins[i];
        // Visual bar
        cout << "  |";
        for (int j = 0; j < bins[i]; j++) cout << "*";
        cout << endl;
    }
}

int main() {
    vector<int> numbers;
    vector<int> bins;

    getInput(numbers);

    if (numbers.empty()) {
        cout << "No numbers were entered." << endl;
        return 0;
    }

    int numBins = getNumBins(numbers);
    bins.resize(numBins, 0);

    buildHistogram(numbers, bins);
    printHistogram(bins);

    return 0;
}