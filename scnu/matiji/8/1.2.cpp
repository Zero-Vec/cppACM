#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
char mp[N][N];
int a[N][N],pre[N][N];
int n, m;
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= m;j++){
            cin >> mp[i][j];
            a[i][j] = mp[i][j] - '0';
        }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
            cout << pre[i][j] << ' ';
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
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
char mp[N][N];
int a[N][N];
int n, m;
int getnum(int x,int y){
    int res = 0;
    for (int i = 1; i <= x;i++)
        for (int j = 1; j <= y;j++)
            if(a[i][j]==1)
                res++;
    return res;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m;j++){
            cin >> mp[i][j];
            a[i][j] = mp[i][j] - '0';
        }
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++)
            cout << getnum(i, j) << ' ';
        cout << '\n';
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
*/