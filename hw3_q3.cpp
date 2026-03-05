#include <iostream>
using namespace std;


int differenceCal(int startTime, int endTime) {
    
    int startMin = (startTime / 100) * 60 + (startTime % 100);
    
    int endMin   = (endTime / 100) * 60 + (endTime % 100);
    
    return (endMin >= startMin) ? endMin - startMin : (1440 - startMin) + endMin;
}


void displayOutput(int startTime, int endTime, int difference) 
{
    cout << "Start Time: " << startTime << endl;
    cout << "End Time: " << endTime << endl;
    cout << "Difference in minutes: " << difference << " minutes";
}


int main () {

    int startTime, endTime, difference;

    cout << "What is the time now? (in military time 0000 to 2359)" << endl;
    cin >> startTime;

    cout << "What time do you exit the machine? (in military time 0000 to 2359)" << endl;
    cin >> endTime;

    difference = differenceCal(startTime, endTime);

    displayOutput(startTime, endTime, difference);

    return 0;
}