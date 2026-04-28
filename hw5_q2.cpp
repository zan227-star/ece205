#include <iostream>
using namespace std;

const int deepDish = 1;
const int handToss = 2;
const int pan = 3;

const int small = 1;
const int medium = 2;
const int large = 3;

class Pizza 
{
    private:

    int type;
    int size;
    int toppings;

    public:

    Pizza()
    {
        type = handToss;
        size = small;
        toppings = 0;
    }

    // Mutator function
    void setType(int t)
    {
        type = t;
    }

    void setSize(int s)
    {
        size = s;
    }

    void setToppings(int m)
    {
        toppings = m;
    }

    // Accessor functions
    int getType()
    {
        return type;
    }

    int getSize()
    {
        return size;
    }

    int getToppings()
    {
        return toppings;
    }

    void outputDescription()
    {
        cout << "Pizza Type: ";
        if (type == 1)
        {
            cout << "Deep Dish" << endl;
        }
        else if (type == 2)
        {
            cout << "Hand Toss" << endl;
        }
        else if (type == 3)
        {
            cout << "Pan" << endl;
        }

        cout << "Pizza Size: ";
        if (size == 1)
        {
            cout << "Small" << endl;
        }
        if (size == 2)
        {
            cout << "Medium" << endl;
        }
        if (size == 3)
        {
            cout << "Large" << endl;
        }

        cout << "Number of toppings: " << toppings << endl;
    }

    double computePrice()
    {
        double basePrice = 0.00;

        if (size == 1)
        {
            basePrice = 10.00;
        }
        else if (size == 2)
        {
            basePrice = 14.00;
        }
        else if (size == 3)
        {
            basePrice = 17.00;
        }

        return basePrice + (toppings * 2.00);
    }

};

int main()
{
    char cont = 'y';
    int count = 1;

    while (cont == 'y' || cont == 'Y')
    {
        Pizza pizza;
        int t, s, top;

        cout << "=== Pizza " << count << " ===" << endl;

        cout << "Enter type (1 = Deep Dish, 2 = Hand Toss, 3 = Pan): ";
        cin >> t;
        pizza.setType(t);

        cout << "Enter size (1 = Small, 2 = Medium, 3 = Large): ";
        cin >> s;
        pizza.setSize(s);

        cout << "Enter number of toppings: ";
        cin >> top;
        pizza.setToppings(top);

        cout << endl;
        pizza.outputDescription();
        cout << "Price: $" << pizza.computePrice() << endl;
        cout << endl;

        cout << "Add another pizza? (y/n): ";
        cin >> cont;
        count++;
    }

    return 0;
}