#include <iostream>
using namespace std;

bool getInput(int &hours, int &minutes)
{
    cout << "Enter the time between 0 - 23 or enter -1 to quit:" << endl; // Get the hours
    cin >> hours;

    if (hours == -1)
    {
        return false;
    }

    cout << "Enter minutes between 0 - 59: " << endl; // Get the minutes
    cin >> minutes;

    return true;
}

void convertTime(int hour24, int minutes, int &hour12, char &AmPm)
{
    if (hour24 == 0) // Midnight
    {
        hour12 = 12;
        AmPm = 'A';
    } 
    else if (hour24 > 12 ) // Afternoon
    {
        hour12 = hour24 - 12;
        AmPm = 'P';
    }
    else if (hour24 == 12) // Noon
    {
        hour12 = hour24;
        AmPm = 'P';
    }
    else // Morning
    {
        hour12 = hour24;
        AmPm = 'A';
    }
}

void displayOutput(int hour12, int minutes, char AmPm)
{
    cout << "Covert Time: " << hour12 << ":";

    if (minutes < 10)
    {
        cout << "0";
    }
    cout << minutes << " ";

    if (AmPm == 'A')
    {
        cout << "AM" << endl;
    }
    else
    {
        cout << "PM" << endl;
    }

}

int main() 
{
    int hour24, hour12, minutes;
    char AmPm;

    cout << "Start of Code" << endl;

    while (getInput(hour24, minutes))
    {
        convertTime(hour24, minutes, hour12, AmPm);
        displayOutput(hour12, minutes, AmPm);
    }

    cout << "End of Code" << endl;

    return 0;
}