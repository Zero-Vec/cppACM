#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int p, k;
bool check(int x){
    int ans = x;
    while(x>=p){
        ans += x / p;
        x = x / p + x % p;
    }
    return ans >= k;
}
void solve(){
    cin >> p >> k;
    if(k == 0 || k == 1){
        cout << k << '\n';
        return;
    }
    if(p == 1){
        cout << 1 << "\n";
        return;
    }
    int l = 1, r = k + 1;
    while(l+1!=r){
        int mid = (l + r) >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r << '\n';
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