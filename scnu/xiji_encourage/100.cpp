#include <bits/stdc++.h>
using namespace std;

int n, a[101], mid, all, ans;

int main() {
    ifstream infile("card.in");
    ofstream outfile("card.out");

    infile >> n;
    if (n == 0) {
        infile.close();
        outfile.close();
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        infile >> a[i];
        all += a[i];
    }
    all /= n;
    for (int i = 1; i <= n; i++) {
        if (a[i] - all) {
            a[i + 1] += a[i] - all;
            ans++;
        }
    }
    outfile << ans;

    infile.close();
    outfile.close();
    return 0;
}