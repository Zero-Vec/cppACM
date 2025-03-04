#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int f, c;
    cin >> f;
    c = 5 * (f - 32) / 9;
    cout << "Celsius = " << c;
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