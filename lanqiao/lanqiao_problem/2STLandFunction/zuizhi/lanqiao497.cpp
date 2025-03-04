#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int a[N];
int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        sum += a[i];
    }
    cout << *max_element(a, a + n) << "\n";
    cout << *min_element(a, a + n) << '\n';
    cout << fixed << setprecision(2) << 1.0 * sum / n;
    return 0;
}