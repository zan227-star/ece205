#include <iostream>
#include <cmath>
using namespace std;

void getInput(double &a, double &b, double &c)
{
    cout << "\nEnter the length of side a: ";
    cin >> a;
    
    cout << "Enter the length of side b: ";
    cin >> b;
    
    cout << "Enter the length of side c: ";
    cin >> c;
}

bool ValidTriangle(double a, double b, double c)
{
    // All sides must be positive and satisfy the triangle inequality
    return (a > 0 && b > 0 && c > 0) &&
           (a + b > c) &&
           (a + c > b) &&
           (b + c > a);
}

void computeTriangle(double a, double b, double c, double &area, double &perimeter)
{
    if (!ValidTriangle(a, b, c)) // Illegal combination: return zeros
    {
        area = 0;
        perimeter = 0;
        cout << "Invalid triangle, area and perimeter set to 0." << endl;
        return;
    }

    perimeter = a + b + c; // Compute perimeter
    double s = perimeter / 2.0; // Compute semi-perimeter
    area = sqrt(s * (s - a) * (s - b) * (s - c)); // Formula for area
}

void displayOutput(double a, double b, double c, double area, double perimeter)
{
    cout << "\nResults" << endl;
    cout << "Sides: a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "Perimeter: " << perimeter << endl;
    cout << "Area: " << area << endl;
}

int main()
{
    double a, b, c, area, perimeter;

    getInput(a, b, c);
    computeTriangle(a, b, c, area, perimeter);
    displayOutput(a, b, c, area, perimeter);

    return 0;
}