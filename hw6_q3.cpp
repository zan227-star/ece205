#include <iostream>
#include <vector>
using namespace std;

// Build a boolean vector where index = number, value = isPrime
// Marks composites by crossing off multiples of each prime found
vector<bool> buildSieve(int n) {
    // Initialize all entries as true (assume all are prime to start)
    vector<bool> isPrime(n, true);

    // 0 and 1 are not prime
    if (n > 0) isPrime[0] = false;
    if (n > 1) isPrime[1] = false;

    // For each number starting at 2, mark all its multiples as not prime
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            // Start at i*i since smaller multiples already marked
            for (int j = i * i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return isPrime;
}

// Collect all prime indices from the sieve into a vector
vector<int> getPrimes(const vector<bool>& isPrime) {
    vector<int> primes;
    for (int i = 2; i < (int)isPrime.size(); i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// Print all primes to the console
void printPrimes(const vector<int>& primes, int n) {
    cout << "\nPrime numbers less than " << n << ":" << endl;
    if (primes.empty()) {
        cout << "None found." << endl;
        return;
    }
    for (int i = 0; i < (int)primes.size(); i++) {
        cout << primes[i];
        if (i < (int)primes.size() - 1) cout << ", ";
    }
    cout << endl;
    cout << "\nTotal primes found: " << primes.size() << endl;
}

int main() {
    int n;
    cout << "Enter an integer N to find all primes less than N: ";
    cin >> n;

    if (n < 2) {
        cout << "There are no prime numbers less than " << n << "." << endl;
        return 0;
    }

    vector<bool> isPrime = buildSieve(n);
    vector<int> primes = getPrimes(isPrime);
    printPrimes(primes, n);

    return 0;
}