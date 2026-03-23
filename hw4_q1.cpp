#include <iostream>
using namespace std;

void readInput(int array[], int size) //Reading integers input from user
{
    cout << "Enter " << size << " non-negative integers:" << endl;

    for (int i = 0; i < size; i++) //Input of non-negative integers
    {
        cout << "Number[" << i + 1 << "]: ";
        cin >> array[i];

        while (array[i] < 0) //Validation for non-negative
        {
            cout << "Invalid! Please enter a different integer: ";
            cin >> array[i];
        }
    }
}

void histogram(int array[], int size, int bins[], int maxBins)
{
    for (int i = 0; i < maxBins; i++) // Have all bins start at 0
    {
        bins[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        int binIndex = array[i] / 10;

         if (binIndex < maxBins) //Bounds check
            bins[binIndex]++;
    }
}

void displayOutput(int bins[], int maxBins)
{
    cout << "\n--- Histogram ---" << endl;

    for (int i = 0; i < maxBins; i++)
    {
        int low = i * 10;
        int high = low + 9;
        cout << "bin " << i << " (" << low << " - " << high << "): " << bins[i] << endl;
    }
}

int main()
{
    const int MAX_BINS = 10; //Supports values 0 - 99
    int size;

    cout << "Enter the number of integers: ";
    cin >> size;

    int array[size];
    int bins[MAX_BINS];

    readInput(array, size);
    histogram(array, size, bins, MAX_BINS);
    displayOutput(bins, MAX_BINS);

    return 0;
}