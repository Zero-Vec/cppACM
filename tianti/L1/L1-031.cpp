#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int h;
    double w;
    cin >> h >> w;
    double a = (h - 100) * 0.9 * 2;
    if(abs(w-a)<a*0.1)
        cout << "You are wan mei!" << '\n';
    else if(w>a)
        cout << "You are tai pang le!" << '\n';
    else
        cout << "You are tai shou le!" << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}