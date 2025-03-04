#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int cnt[N], prefix[N];
void dfs(int dep,int st,int mul,int sum){
    if(mul>1e6)
        return;
    if(dep==4){
        cnt[mul]++;
        return;
    }
    int maxn = pow(1e6 / mul, 1.0 / (4 - dep)) + 9;
    for (int i = st + 1; i < (dep == 3 ? sum : maxn);i++){
        dfs(dep + 1, i, mul * i, sum + i);
    }
    return;
}
void solve(){
    dfs(1, 0, 1, 0);
    for(int i = 1; i <= 1e6;i++){
        prefix[i] = prefix[i - 1] + cnt[i];
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << "\n";
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    //cout << pow(1e6 / 10, 1.0 / (4 - 2)) + 9 << "\n";
    //cout << pow(1e6 / 10, 1 / (4 - 2)) + 9;
    return 0;
}