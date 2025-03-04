#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 20;
int a[N];
int n, l, r, x;
set<int> s;
void solve(){
    cin>>n>>l>>r>>x;
    for (int i = 1;i<=n;i++)
        cin >> a[i];
    int sum = pow(2, n);//总方案数
    int res = 0;
    for (int i = 0; i < sum;i++){
        s.clear();
        int ans = 0;
        int maxn = 0, minx = 1e9 + 1;
        for (int j = 0; j < n;j++){
            if((i>>j)&1){
                ans += a[j + 1];
                maxn = max(maxn, a[j + 1]);
                minx = min(minx, a[j + 1]);
                s.insert(a[j + 1]);
            }
        }
        if(ans>=l&&ans<=r&&s.size()>=3&&maxn-minx>=x)
            res++;
    }
    cout << res;
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