#include <iostream>
#include <vector>
using namespace std;

const int deepDish = 1;
const int handTossed = 2;
const int pan = 3;

const int small = 1;
const int medium = 2;
const int large = 3;

class Pizza {
private:
    int type;
    int size;
    int toppings;

public:
    Pizza() {
        type = handTossed;
        size = medium;
        toppings = 0;
    }

    // Mutators
    void setType(int t)     
    { 
        type = t; 
    }
    void setSize(int s)     
    {
        size = s; 
    }
    void setToppings(int n) 
    { 
        toppings = n; 
    }

    // Accessors
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

    void outputDescription() {
        cout << "  Pizza Type: ";
        if (type == deepDish)        cout << "Deep Dish" << endl;
        else if (type == handTossed) cout << "Hand Tossed" << endl;
        else if (type == pan)         cout << "Pan" << endl;

        cout << "  Pizza Size: ";
        if (size == small)       cout << "Small" << endl;
        else if (size == medium) cout << "Medium" << endl;
        else if (size == large)  cout << "Large" << endl;

        cout << "  Number of Toppings: " << toppings << endl;
    }

    double computePrice() {
        double basePrice = 0.0;
        if (size == small)       basePrice = 10.0;
        else if (size == medium) basePrice = 14.0;
        else if (size == large)  basePrice = 17.0;
        return basePrice + (toppings * 2.0);
    }
};

class Order {
private:
    vector<Pizza> pizzas; // private vector of Pizza objects

public:
    // Adds a pizza to the order
    void addPizza(int type, int size, int toppings) {
        Pizza p;
        p.setType(type);
        p.setSize(size);
        p.setToppings(toppings);
        pizzas.push_back(p);
    }

    // Outputs all pizzas in the order and the total price
    void outputOrder() {
        if (pizzas.empty()) {
            cout << "The order is empty." << endl;
            return;
        }

        double totalPrice = 0.0;

        cout << "========== ORDER SUMMARY ==========" << endl;
        for (int i = 0; i < pizzas.size(); i++) {
            cout << "Pizza " << i + 1 << ":" << endl;
            pizzas[i].outputDescription();
            cout << "  Price: $" << pizzas[i].computePrice() << endl;
            cout << endl;
            totalPrice += pizzas[i].computePrice();
        }

        cout << "Total Price: $" << totalPrice << endl;
    }
};

int main() {
    Order order;
    char cont = 'y';
    int count = 1;

    while (cont == 'y' || cont == 'Y') {
        int t, s, top;

        cout << "--- Pizza " << count << " ---" << endl;

        cout << "Enter type (1 = Deep Dish, 2 = Hand Tossed, 3 = Pan): ";
        cin >> t;

        cout << "Enter size (1 = Small, 2 = Medium, 3 = Large): ";
        cin >> s;

        cout << "Enter number of toppings: ";
        cin >> top;

        order.addPizza(t, s, top);

        cout << "Add another pizza? (y/n): ";
        cin >> cont;
        count++;
        cout << endl;
    }

    cout << endl;
    order.outputOrder();

    return 0;
}