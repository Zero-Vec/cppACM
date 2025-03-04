#include <iostream>
#include <cmath>
using namespace std;

#define N 1000

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int m, k, i, n, x[N];

    cin >> m >> k;

    n = 0; // array index

    for (i = m + 1; n < k; i++) { // loop through numbers greater than m
        if (isPrime(i)) {
            x[n++] = i; // store prime number in array
        }
    }

    for (i = 0; i < n; i++) {
        cout << x[i];
        if (i < n - 1) cout << ",";
    }

    return 0;
}