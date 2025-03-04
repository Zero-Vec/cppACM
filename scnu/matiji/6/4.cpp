#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int x[N], h[N], dis[N];//dis[i]表示x[i]到x[i+1]的距离
int n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> x[i] >> h[i];
    }
    for (int i = 1; i < n;i++)
        dis[i] = x[i + 1] - x[i];
    if(n<3){
        cout << n;
    }
    else{
        int ans = 0;
        for (int i = 2; i < n;i++){
            if(dis[i-1]>h[i]){
                ans++;
                continue;
            }
            if(dis[i]>h[i]){
                ans++;
                dis[i] -= h[i];
            }
        }
        cout << ans + 2;
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