#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
const int N = 20;
int a[N];
int ans[60000][N];
int cnt;
void dfs(int x,int sum){
    if(sum>n)
        return;//剪枝
    if(x>10){
        if(sum==n){
            cnt++;
            for (int i = 1; i <= 10;i++){
                ans[cnt][i] = a[i];
            }
        }
        return;
    }
    for (int i = 1; i <= 3;i++){
        a[x] = i;
        dfs(x + 1, sum + i);
        a[x] = 0;
    }
}
void solve(){
    cin >> n;
    dfs(1, 0);
    cout << cnt << "\n";
    for (int i = 1; i <= cnt;i++){
        for (int j = 1; j <= 10;j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
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