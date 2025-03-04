#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
struct node{
    int s, t;
    ll d;
} a[N];
int n, m;
ll b[N], tmp[N], diff[N];
bool check(int x){
    memset(diff, 0, sizeof diff);
    for (int i = 1; i <= n;i++){
        tmp[i] = b[i];
        diff[i] = tmp[i] - tmp[i - 1];
    }
    for (int i = 1; i <= x;i++){
        diff[a[i].s] -= a[i].d, diff[a[i].t + 1] += a[i].d;
    }
    for (int i = 1; i <= n;i++){
        tmp[i] = tmp[i - 1] + diff[i];
        if(tmp[i]<0)
            return true;
        //cout<<tmp[i]<<'\n';
    }
    return false;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> b[i];
    }
    for (int i = 1; i <= m;i++){
        cin >> a[i].d >> a[i].s >> a[i].t;
    }
    int l = 0, r = n + 1;
    while(l+1!=r){
        int mid = (l + r) >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid;
    }
    if(l==n){
        cout << 0 << '\n';
    }
    else{
        cout << -1 << '\n';
        cout << r;
    }
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