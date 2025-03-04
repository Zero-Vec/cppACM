#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 9;
ll h[N];
ll shu(int l, int r) { return r - l + 1; }
ll heng(int l,int r){
    ll hmin = 0x3f3f3f3f3f3f3f3f;
    for (int i = l; i <= r;i++)
        hmin = min(hmin, h[i]);
    for (int i = l; i <= r;i++)
        h[i] -= hmin;
    ll ans = hmin;
    while(l<=r){
        while(l<=r&&h[l]==0)
            l++;
        int tmp = l;
        while(tmp<=r&&h[tmp]!=0)
            tmp++;
        ans += min(heng(l, tmp - 1), shu(l, tmp - 1));
    }
    return ans;
}
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> h[i];
    }
    cout << min(heng(1, n), shu(1, n));
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