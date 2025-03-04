#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll k, m, h;
bool check(int x){
    // ll res = x, gs = x;
    // while(gs >= m){
    //     ll tmp = (gs / m) * k;
    //     res += tmp;
    //     gs = gs % m;
    //     gs += tmp;
    //     if(res>=h){
    //         return true;
    //     }
    // }
    // return res >= h;
    return (x + (x - k) / (m - k) * k) >= h;
}
void solve(){
    cin >> m >> k >> h;
    if(h == 0){
        cout << 0 << '\n';
        return;
    }
    if (h <= m){
        cout << h << '\n';
        return;
    }
    if(k == m){
        cout << m << '\n';
        return;
    }
    // cout << (h - (h - k) / m * k) << '\n';


    // int l = 0, r = h;
    // while(l+1!=r){
    //     int mid = (l + r) >> 1;
    //     if(check(mid))
    //         r = mid;
    //     else
    //         l = mid;
    // }
    // cout << r << '\n';
    

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