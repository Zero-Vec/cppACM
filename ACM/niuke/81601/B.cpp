#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k;
void solve(){
    cin >> n >> k;
    if(n % 2 == 0 && k == n / 2){
        cout << n;
        return;
    }
    if(k>n/2)
        k = n - k;
    cout << n * k + 1;
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