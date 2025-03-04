#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6;
void solve(){
    ll x;
    cin>>x;
    if(x<=1){
        cout << -1 << '\n';
    }
    else if(x<=1e6+1){
        cout << x - 1 << " " << 1 << " " << 1 << '\n';
    }
    else{
        int a, b, c;
        if(x%N==0){
            a = 1e6, b = x / N - 1, c = 1e6;
        }
        else{
            a = 1e6, b = x / N, c = x - a * b;
        }
        cout << a << " " << b << " " << c << '\n';
    }
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