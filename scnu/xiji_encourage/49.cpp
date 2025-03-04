#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    cout << n / 10 << " ";
    n %= 10;
    cout << n / 5 << " ";
    n %= 5;
    cout << n / 2 << " ";
    n %= 2;
    cout << n;
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