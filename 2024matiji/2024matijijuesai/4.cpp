#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9;
int pre[N], a[N];
ll dp[N];
int n, m;
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        pre[i] = i;
    while(m--){
        int x, y;
        cin >> x >> y;
        pre[root(x)] = root(y);
    }
    map<int, int> mp;
    for (int i = 1; i <= n;i++)
        mp[root(i)]++;
    int k = 1;
    for(auto [i,j]:mp){
        a[k++] = j;
        //cout << j << '\n';
    }
    int B = n / 2;
    //cout << B << " ";
    /*
    for (int i = 1; i < k;i++){
        for (int j = B; j >= 0;j--)
        {
            if(j>=a[i])
                dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    cout << 1ll * dp[B] * (n - dp[B]);
    */
    sort(a + 1, a + k);
    int l = a[k-1], r = 0;
    for (int i = k - 2; i > 0;i--){
        if(r<=l)
            r += a[i];
        else
            l += a[i];
    }
    cout << 1ll * r * l;
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