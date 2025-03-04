#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15;
int t[N], d[N], l[N], n;
bool v[N];
//cnt表示当前已选择的总飞机数，sum表示前一个飞机最快降落时间
//t[i]+d[i]<sum,false
bool dfs(int cnt,int sum){
    if(cnt==n){
        return true;
    }
    //枚举飞机降落顺序
    for (int i = 1; i <= n;i++){
        if(v[i])continue;
        v[i] = 1;
        if(t[i]+d[i]<sum){
            v[i] = 0;
            return false;
        }
        int tmp = max(t[i], sum);
        if(dfs(cnt+1,tmp+l[i]))
            return true;
        v[i] = 0;
    }
    return false;
}
void solve(){
    cin >> n;
    memset(v, 0, sizeof v);
    for (int i = 1; i <= n;i++)
        cin >> t[i] >> d[i] >> l[i];
    cout << (dfs(0, 0) ? "YES" : "NO") << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}