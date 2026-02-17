#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;

void hatSize(double weight, double height)
{
    double hatsize;

    hatsize = (2.9 * weight) / height;

    cout << "\nBase on your info your Hat Size is " << hatsize << endl;
}

void jacketSize(double height, double weight, double age) // Function for 
{
    double cal_one, adjust, jacketsize;

    cal_one = (height * weight) / 288;
    adjust = floor((age - 30) / 10) * 1.0/8; // Flooring the number because we want a full 10 years
    jacketsize = cal_one + adjust;

    cout << "\nBase on your info your Jacket Size is " << jacketsize << endl;
}

void waistSize(double weight, double age)
{
    double waistsize, cal_one, adjust;

    cal_one = weight / 5.7;
    adjust = floor((age - 28)/2) * 1.0/10; // Flooring the number because we dont do halves
    waistsize = cal_one + adjust;
    
    cout << "\nBase on your info your Waist Size is " << waistsize << " inches." << endl;
}

int main ()
{
    double height, weight, age;
    
    cout << "\nWhat is your height? (in inches)" << endl;
    cin >> height;

    cout << "\nWhat is your weight? (in pounds)" << endl;
    cin >> weight;

    cout << "\nWhat is your age?" << endl;
    cin >> age;

    hatSize(weight, height);
    jacketSize(height, weight, age);
    waistSize(weight, age);
    
    return 0;
}