#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(int a,int b){
    return !b ? a : gcd(b, a % b);
}
void solve(){
    int a,b;
    cin >> a >> b;
    cout << a / gcd(a, b) << " " << b / gcd(a, b) << '\n';
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