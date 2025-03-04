#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int l[N], r[N], w[N];
ll ans;
void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n;i++){
        cin >> w[i];
    }
    for (int i = 1; i <= n;i++){
        cin >> l[i] >> r[i];
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