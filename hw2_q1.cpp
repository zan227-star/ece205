#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    const double grav_const = 6.673 * pow(10.0, -8.0); // G = 6.673 * 10^-8 
    double mass_1, mass_2, distance, grav_force, something, numerator, denominator; // List of variables
    something = 0.00;

    while (something < 1)
    {
        // Asking for the values of the variables
        cout << "What is the mass of the first object? (in kilograms)" << endl;
        cin >> mass_1;
        
        cout << "What is the mass of the second object? (in kilogams)" << endl;
        cin >> mass_2;
        
        cout << "How far apart are the two objects? (in meters)" << endl;
        cin >> distance;

        // Calculation for the gravitional force of attractive
        numerator = grav_const * mass_1 * mass_2; // numerator = G * m1 * m2
        denominator = pow(distance, 2.0); // denominator = d^2
        grav_force = numerator / denominator; 

        //Output
        cout << "The gravitional attractive force is " << grav_force << " cm^3/(g*sec^2)" << endl;
    }
    return 0;
}