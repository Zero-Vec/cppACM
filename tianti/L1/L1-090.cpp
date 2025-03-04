#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int a, b;
    cin >> a >> b;
    cout << a + b - 16 << "\n";
    cout << a + b - 3 << "\n";
    cout << a + b - 1 << "\n";
    cout << a + b;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}