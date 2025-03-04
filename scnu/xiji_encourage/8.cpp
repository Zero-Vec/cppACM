#include<bits/stdc++.h>
using namespace std;
int main() {
    int x, n;
    cin >> x >> n;
    double xn = x;
    for (int i = 0; i < n; ++i) {
        xn = (2 * xn + x / (xn * xn)) / 3;
    }
    cout << fixed << setprecision(5) << xn << endl;

    return 0;
}