#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e3 + 9;
const int inf = 0x3f3f3f3f;
int n, W, w[N], v[N];
ll dpw[N], dpn[N];//最大价值、最小数量  重量限制为i时所含最大价值和最小数量
void solve(){
    cin >> n >> W;
    for (int i = 1; i <= n;i++)
        cin >> w[i] >> v[i];
    for (int i = 1; i <= n;i++){
        for (int j = W; j >= v[i];j--){
            if(dpw[j-v[i]]+w[i]>=dpw[j]){
                dpw[j] = dpw[j - v[i]] + w[i];
                dpn[j] = dpn[j - v[i]] + 1;
            }
        }
    }
    cout << dpw[W] << " " << dpn[W];
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