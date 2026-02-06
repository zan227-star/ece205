#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    //Constants
    const double inital_debt = 1000.00; //inital costt of stereo
    const double monthly_interest_rate = 0.015; //the monthly interest rate for the stereo
    const double monthly_payment = 50.00; //monthly payments that need to be $50.00

    //Variables: to keep the values of all the changing status
    double balance = inital_debt;
    double total_interest = 0.00;
    double total_paid = 0.00;
    int month = 0;

    //Table Headers
    std::cout << std::right << std::setw(15) << "Month #" 
    << std::right << std::setw(15) << "Interest" 
    << std::right << std::setw(15) << "Principal" 
    << std::right << std::setw(15) << "Balance" 
    << std::right << std::setw(15) << "Total Interest" 
    << std::right << std::setw(15) << "Total Paid" << endl;

    while(balance > 0)
    {
        month++; //increase the months 
        
        double interest_this_month = balance * monthly_interest_rate; //calculate interest for this month 
        
        double actualpayment;
        double principle;

        if (balance + interest_this_month <= monthly_payment) //last payment - pay off remaining balance + interest
        {
            actualpayment = balance + interest_this_month;
            principle = balance;
            balance = 0.00;
        }
        else 
        {
            actualpayment = monthly_payment;
            principle = monthly_payment - interest_this_month;
            balance -= principle;
        }

        //this will update the total
        total_interest += interest_this_month;
        total_paid += actualpayment;

        cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

        //output the monthly data for each column
        std::cout << std::right << std::setw(15) << month 
        << std::right << std::setw(15) << interest_this_month 
        << std::right << std::setw(15) << principle 
        << std::right << std::setw(15) << balance
        << std::right << std::setw(15) << total_interest
        << std::right << std::setw(15) << total_paid << endl;
    }

    return 0;
}