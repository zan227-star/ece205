#include <iostream>
using namespace std;

class PrimeNumber {
private:
    int prime;

    // Helper function — checks if a number is prime
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    // Helper function — finds the next prime above n
    int nextPrime(int n) {
        int candidate = n + 1;
        while (!isPrime(candidate)) {
            candidate++;
        }
        return candidate;
    }

    // Helper function — finds the next prime below n
    int prevPrime(int n) {
        if (n <= 2) {
            cout << "No prime smaller than 2 exists." << endl;
            return n;
        }
        int candidate = n - 1;
        while (!isPrime(candidate)) {
            candidate--;
        }
        return candidate;
    }

public:
    // Default constructor — sets prime to 1
    PrimeNumber() {
        prime = 1;
    }

    // Parameterized constructor
    PrimeNumber(int p) {
        prime = p;
    }

    // Accessor
    int getPrime() {
        return prime;
    }

    // Prefix ++ (++obj) — increments first, then returns
    PrimeNumber operator++() {
        prime = nextPrime(prime);
        return *this;
    }

    // Postfix ++ (obj++) — returns original first, then increments
    PrimeNumber operator++(int) {
        PrimeNumber temp = *this;
        prime = nextPrime(prime);
        return temp;
    }

    // Prefix -- (--obj) — decrements first, then returns
    PrimeNumber operator--() {
        prime = prevPrime(prime);
        return *this;
    }

    // Postfix -- (obj--) — returns original first, then decrements
    PrimeNumber operator--(int) {
        PrimeNumber temp = *this;
        prime = prevPrime(prime);
        return temp;
    }
};

int main() {
    // Test default constructor
    PrimeNumber p1;
    cout << "Default constructor: " << p1.getPrime() << endl;

    // Test parameterized constructor
    PrimeNumber p2(13);
    cout << "Starting prime: " << p2.getPrime() << endl;

    // Test prefix ++
    ++p2;
    cout << "After prefix ++: " << p2.getPrime() << endl;

    // Test postfix ++
    PrimeNumber p3(13);
    PrimeNumber p4 = p3++;
    cout << "\nPostfix ++ test (starting at 13):" << endl;
    cout << "Returned value: " << p4.getPrime() << endl;
    cout << "p3 after postfix ++: " << p3.getPrime() << endl;

    // Test prefix --
    PrimeNumber p5(13);
    --p5;
    cout << "\nAfter prefix -- (starting at 13): " << p5.getPrime() << endl;

    // Test postfix --
    PrimeNumber p6(13);
    PrimeNumber p7 = p6--;
    cout << "\nPostfix -- test (starting at 13):" << endl;
    cout << "Returned value: " << p7.getPrime() << endl;
    cout << "p6 after postfix --: " << p6.getPrime() << endl;

    // Test chaining
    PrimeNumber p8(7);
    cout << "\nChaining ++ from 7:" << endl;
    cout << (++p8).getPrime() << endl;  // 11
    cout << (++p8).getPrime() << endl;  // 13
    cout << (++p8).getPrime() << endl;  // 17

    return 0;
}