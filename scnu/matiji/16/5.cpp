#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 9, p = 1e9 + 7;
struct GRAPH{
    int head[N], nxt[N << 1], to[N << 1], cnt;
    void add(int u,int v){
        nxt[++cnt] = head[u];
        to[cnt] = v;
        head[u] = cnt;
    }
} gr;
int f[N][30][2], n, q, k, a[N], st[N], top;
void dfs(int u,int fa){
    st[++top] = u;
    for (int j = 0; j < 30;j++)
        f[u][j][(a[u] >> j) & 1]++;
    if(top > k + 1)
        for (int j = 0; j < 30;j++)
            f[st[top - k - 1]][j][(a[u] >> j) & 1]--;
    for (int i = gr.head[u]; i;i=gr.nxt[i]){
        int v = gr.to[i];
        if(v == fa)continue;
        dfs(v, u);
    }
    top--;
}
void dfs_sum(int u,int fa){
    for (int i = gr.head[u]; i;i=gr.nxt[i]){
        int v=gr.to[i];
        if(v == fa)continue;
        dfs_sum(v, u);
        for (int j = 0; j < 30;j++)
            f[u][j][0] += f[v][j][0], f[u][j][1] += f[v][j][1];
    }
}
void solve(){
    cin >> n >> q >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i < n;i++){
        int u, v;
        cin >> u >> v;
        gr.add(u, v);
        gr.add(v, u);
    }
    dfs(1, 0); // 树上差分，并处理每一个节点的各位0，1的和
    dfs_sum(1, 0); // 树上前缀和 求出节点x不超过距离k所含贡献0和1的个数
    while(q--){
        int x;
        cin >> x;
        ll ans = 0;
        for (int j = 0; j < 30; j++){
            ans = (ans + 1ll * f[x][j][0] * f[x][j][1] % p * (1 << j) % p) % p;
        }
        cout << ans << '\n';
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