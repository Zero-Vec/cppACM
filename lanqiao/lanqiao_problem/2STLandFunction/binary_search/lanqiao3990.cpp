#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N];
ll n, k, s;
bool check(int mid){
    ll cnt = 0;
    for (int i = 1; i <= n;i++){
        cnt += a[i] / mid;
    }
    return cnt >= k;
}
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        s += a[i];
    }
    int l = 0, r = 1e9;
    while(l+1!=r){
        int mid = (l + r) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << (l == 0 ? -1 : l);
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