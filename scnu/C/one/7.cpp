#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << setw(8) << right << a << " "
         << setw(8) << right << b << " "
         << setw(8) << right << c;
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