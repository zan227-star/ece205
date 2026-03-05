#include <iostream>
using namespace std;

void getInput(double &pounds, double &ounces)
{
    cout << "Enter weight in pounds: ";
    cin >> pounds;

    while (pounds < 0)
    {
        cout << "\nPounds cannot be negative. Please re-enter: ";
        cin >> pounds;
    }

    cout << "Enter weight in ounces: ";
    cin >> ounces;

    while (ounces < 0 || ounces >= 16)
    {
        cout << "Ounces must be between 0 and 15. Please re-enter: ";
        cin >> ounces;
    }
}

void convertWeight(double pounds, double ounces, int &kg, int &grams)
{
    double totalPounds = pounds + (ounces / 16.0); // Convert to total pounds

    double totalKg = totalPounds / 2.2046; // Convert pounds to kilograms

    kg = (int)totalKg;
    grams = (int)((totalKg - kg) * 1000);
}

void displayOutput(double pounds, double ounces, int kg, int grams)
{
    cout << "\nResult:" << endl;
    cout << pounds << "lb " << ounces << "oz  =  " << kg << "kg " << grams << "g" << endl;
}

int main()
{
    double pounds, ounces;
    int kg, grams;
    char choice;

    do
    {
        getInput(pounds, ounces);
        convertWeight(pounds, ounces, kg, grams);
        displayOutput(pounds, ounces, kg, grams);

        cout << "\nConvert another weight? (y/n): ";
        cin >> choice;

    } 
    while (choice == 'y' || choice == 'Y');

    cout << "\nEnd Code" << endl;

    return 0;
}