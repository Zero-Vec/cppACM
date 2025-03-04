#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    char ch;
    int a;
    float b;
    double c;
    cin >> ch >> a >> b >> c;
    cout << ch << " " << a << " ";
    cout << fixed << setprecision(6);
    cout << b << " " << c;
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