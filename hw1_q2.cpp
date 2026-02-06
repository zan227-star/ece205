#include <iostream>
using namespace std;

int main() {
    const double hourly_rate = 36.75; //the money per hour the worker makes
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);


    //Asking the worker for his inoformation
    int hours, dependents;
    cout << "How many hours did you work this week\? \n";
    cin >> hours;
    cout << "How many people depend on your income\? \n";
    cin >> dependents;
    
    //Income of the worker
    double income;
    if (hours <= 40) //if the amount of hours is less than or equal to 40 hours
    { 
        income = hours * hourly_rate;
        cout << "You have worked for " << hours << " hours, and earned $" << income << endl;
    }
    else //if the amount of hours is more than 40 hours
    {
        income = (40 * hourly_rate) + ((hours - 40) * (1.5 * hourly_rate));
        cout << "You have worked for " << hours << " hours, and earned $" << income << endl;
    }

    //Taxes/dues 
    double deducted, social_security, federal_income, state_tax, bethlehem_tax;
    int union_tax = 20;
    social_security = income * 0.06;
    federal_income = income * 0.15;
    state_tax = income * 0.04;
    bethlehem_tax = income * 0.01;
    cout << "Your union tax is $" << union_tax << endl;
    cout << "Your social seurcity tax is $" << social_security << endl;
    cout << "Your federal income tax is $" << federal_income << endl;
    cout << "Your state tax is $" << state_tax << endl;
    cout << "Your City of Bethlehem tax is $" << bethlehem_tax << endl;

    //Do they live alone?
    if (dependents > 2)
    {
        int health_insurance = 40;
        cout << "Since you have " << dependents << "depending on you, you pay $" << health_insurance << " in health insurance." << endl;
        deducted = social_security + federal_income + state_tax + bethlehem_tax + union_tax + health_insurance;
    }
    else 
    {
        int health_insurance = 0;
        cout << "Since you have " << dependents << "depending on you, you pay $" << health_insurance << " in health insurance." << endl;
        deducted = social_security + federal_income + state_tax + bethlehem_tax + union_tax;
    }

    //Output
    double net_income;
    net_income = income - deducted;

    cout << "You are paying $" << deducted << " in taxes." << endl;
    cout << "This makes your net total income is " << net_income << "$" << endl;

    return 0;
}
