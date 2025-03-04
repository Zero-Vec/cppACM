#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 57;
#define int long long
int n, m, a[N], l, r, mid;
bool check(int p){
    int tmp = 0;
    for (int i = 1; i <= n;i++)
        if(p>a[i])
            tmp += p - a[i];//需要多少张特殊卡
    if(tmp<=m&&tmp<=p)
        return true;
    return false;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        r = max(r, a[i]);
    }
    l = 0, r += m;
    while (l + 1 != r){
        mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}