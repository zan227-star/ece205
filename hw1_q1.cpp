#include <iostream>
using namespace std;

int main ()
{
    int numberOfseconds;
    cout << "This is a Calclator for converting second to hours and minutes. \n";
    cout << "How many seconds? \n";
    cin >> numberOfseconds; //takes input from the user
    cout << numberOfseconds << " seconds is equal to... \n";
    
    //Part 1: Hours, Minutes, and Seconds
    int numberOfhours;
    int numberOfminutes;
    int final_numberOfseconds;

    numberOfhours = numberOfseconds / 3600; //number of seconds in a hour
    numberOfminutes = (numberOfseconds % 3600) / 60; // using the remiander of the hours, to find the minutes
    final_numberOfseconds = numberOfseconds % 60; //find the remaining number of seconds

    //Part 2: Hours Only
    double final_numberOfhours;
    final_numberOfhours = numberOfseconds / 3600.0;

    //Part 3: Minutes Only
    double final_numberOfminutes;
    final_numberOfminutes = numberOfseconds / 60.0;

    //Part 4: Output
    
    //magic formula to force decimal sizes
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    cout << final_numberOfhours << " hours. \n";
    cout << final_numberOfminutes << " minutes. \n";
    cout << "Or " <<numberOfhours << " hours, " << numberOfminutes << " minutes, " << final_numberOfseconds << " seconds. \n";

    return 0;
}