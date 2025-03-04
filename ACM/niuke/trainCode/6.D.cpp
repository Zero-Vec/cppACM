#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    double p;
    cin >> p;
    cout << pow(1 - p, 2) * pow(p, 3) + pow(p, 2) * pow(1 - p, 3);
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