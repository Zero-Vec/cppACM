#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int n, m, pre[N * N], cnt, r;
char mp[N][N];
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void init(int x){
    for (int i = 1; i <= x;i++)
        pre[i] = i;
}
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void merge(int i,int j){
    int x = root(i), y = root(j);
    if(x!=y)
        pre[x] = y;
}
int convert(int x,int y){
    return (x - 1) * m + y;
}
void solve(){
    cin >> n >> m;
    init(n * m);
    for (int i = 1; i <= n;i++)
        cin >> (mp[i] + 1);
    for (int i = 1; i <= m;i++)
        if(mp[n][i]=='1')
            cnt++;
    if(cnt < 2){
        cout << "No";
        return;
    }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            if(mp[i][j]=='0')continue;
            if(!r)
                r = convert(i, j);
            for (int k = 0; k < 4;k++){
                int x = i + dx[k], y = j + dy[k];
                if(x<1||y<1||x>n||y>m)continue;
                if(mp[x][y]=='1')
                    merge(convert(i, j), convert(x, y));
            }
        }
    }
    r = root(r);
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++){
            if(mp[i][j]=='1')
                if(root(convert(i,j))!=r){
                    cout << "No";
                    return;
                }
        }
    cout << "Yes";
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