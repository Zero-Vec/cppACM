#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
void solve(){
    ull a,b,n;
    cin >> a >> b >> n;
    ull sum = 0;
    ull t = 1ull * 5 * a + 1ull * 2 * b;
    ull week = 1ull * n / t;
    n -= week * t;
    ull cnt = 1ull * 7 * week;
    while(sum<n){
        cnt++;
        if(cnt%7==0||cnt%7==6)
            sum += b;
        else
            sum += a;
    }
    cout << cnt;
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