#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N];
int n, x;
void solve(){
    cin >> n >> x;
    ll mx = 0, maxn = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(i==x)
            mx = a[i];
        maxn = max(maxn, a[i]);
    }
    sort(a + 1, a + 1 + n);
    int id;
    for (int i = n; i >= 1;i--){
        if(a[i]==mx){
            id = i;
            break;
        }
    }
    int ans=0;
    ll tmp = a[id];
    if(maxn==mx){
        for (int i = id - 1; i >= 1;i--){
            if(tmp!=a[i] && i != id - 1)
                break;
            tmp = a[i];
            ans++;
        }
        cout << ans;
    }
    else{
        tmp = maxn;
        for (int i = n; i >= 1; i--)
        {
            if (tmp != a[i] && i != n)
                break;
            tmp = a[i];
            ans++;
        }
        cout << ans;
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