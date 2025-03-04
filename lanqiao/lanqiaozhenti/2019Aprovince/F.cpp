#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+9;
int a[N];
void solve(){
    //cout << log(32) / log(2);
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int dep = log(n + 1) / log(2);
    if(n&(n+1)!=0){
        dep++;
    }
    //cout << dep << '\n';
    ll ans = -1e5 - 10;
    int cnt = 1;
    for (int i = 1; i < dep;i++){
        ll sum = 0;
        for (int j = pow(2, i - 1); j <= pow(2, i) - 1;j++){
            sum += a[j];
        }
        if(sum>ans){
            ans = sum;
            cnt = i;
        }
    }
    ll sum = 0;
    for (int j = pow(2, dep-1); j <= n; j++){
        sum += a[j];
        if (sum > ans){
            ans = sum;
            cnt = dep;
        }
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