#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
vector<int> g[N];
map<int, int> cnt[N];
int col[N];
void dfs(int x){
    for(auto i:g[x]){
        dfs(i);
        for(auto j:cnt[i]){
            cnt[x][j.first] += cnt[i][j.first];
        }
    }
    return;
}
int n, fa;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> col[i] >> fa;
        g[fa].push_back(i);
        cnt[i][col[i]]++;
    }
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n;i++){
        int mn = 2e5 + 9, mx = 0;
        for(auto j:cnt[i]){
            mn = min(mn, j.second);
            mx = max(mx, j.second);
        }
        if(mn==mx)
            ans++;
    }
    cout << ans;
}
int main()
{
    //暴力解法:只能7/10，骗10.5分，可以了
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}