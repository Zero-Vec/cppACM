#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e3 + 9;
int sum[N][N];
int n, m;
vector<int> g[N];
void solve(){
    cin >> n >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= n;i++){
        for(auto j:g[i]){
            for(auto k:g[j]){
                if(i!=k)
                    sum[i][k]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= n;j++){
            ans += (sum[i][j] - 1) * sum[i][j] / 2;
        }
    }
    cout << ans;
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