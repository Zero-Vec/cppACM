#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e3+9;
int n;
struct node{
    vector<int> v;
    int ind = 0;
}g[N];
void solve(){
    cin >> n;
    int x;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n - 1;j++){
            cin >> x;
            g[i].v.push_back(x);
        }
    int ans = 0;
    while(1){
        bool tag = 0;
        int vis[N] = {0};
        for (int i = 1; i <= n;i++){
            if(vis[i]||g[i].ind==n-1)continue;
            int j = g[i].v[g[i].ind];
            if(vis[j]||g[j].ind==n-1||g[j].v[g[j].ind]!=i)continue;
            tag = 1;
            vis[i] = vis[j] = 1;
            g[i].ind++;
            g[j].ind++;
        }
        if(!tag)
            break;
        else
            ans++;
    }
    int flag = 0;
    for (int i = 1; i <= n;i++){
        if(g[i].ind!=n-1){
            flag = 1;
            break;
        }
    }
    cout << (flag ? -1 : ans);
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