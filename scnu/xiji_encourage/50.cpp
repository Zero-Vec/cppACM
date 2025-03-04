#include<bits/stdc++.h>
using namespace std;
int main() {
    double e;
    cin >> e;
    double pi = 1.0, ans_pi;
    int n = 1, ans_n = 1;
    double t;
    double dif = 100.0;
    do {
        t = (2.0 * n / (2.0 * n - 1)) * (2.0 * n / (2.0 * n + 1));
        pi *= t;
        n++;
        if(dif > fabs(pi * 2 - e)){
            dif = fabs(pi * 2 - e);
            ans_pi = pi * 2;
            ans_n = n;
        }
    } while (pi * 2 < e);
    // pi *= 2;
    cout << fixed << setprecision(9) << ans_pi << " " << ans_n - 1 << '\n';
    return 0;
}