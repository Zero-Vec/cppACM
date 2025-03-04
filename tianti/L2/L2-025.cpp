#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 8;
int n, m;
vector<int> g[N];
bool v[N];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= m;i++){
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int k;
    cin >> k;
    while(k--){
        int t;
        cin >> t;
        memset(v, 0, sizeof v);
        while(t--){
            int x;
            cin >> x;
            v[x] = 1;
        }
        bool tag = 0;
        for (int i = 1; i <= n;i++){
            if(v[i])continue;
            for(auto j:g[i]){
                if(!v[j]){
                    tag = 1;
                    break;
                }
            }
        }
        cout << (tag ? "NO\n" : "YES\n");
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