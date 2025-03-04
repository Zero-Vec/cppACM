#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 60;
ll n, m, a[N], sum[N], ans;
struct node{
    ll b, c;
    bool operator<(const node &u)const{
        return b < u.b;
    }
} sweet[N];
ll add(int l,int r){
    ll ans = 0;
    for (int i = l; i <= r;i++)
        ans+=sum[i];
    return ans;
}
void solve(){
    cin >> n;
    ll mx = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    sort(a + 1, a + 1 + n);
    cin >> m;
    for (int i = 1; i <= m;i++){
        cin >> sweet[i].b;
        if(sweet[i].b>mx){
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 1; i <= m;i++)
        cin >> sweet[i].c;
    sort(sweet + 1, sweet + 1 + m);
    for (int i = 1; i <= m;i++)
        for (int j = 1; j <= n; j++){
            if(sweet[i].b<=a[j]){
                sum[j] += sweet[i].c;
                break;
            }
        }
    for (int i = 1; i <= n;i++){
        ll tmp = (add(i, n)) / (n - i + 1);
        if(tmp<=sum[i]){
            sum[i + 1] += sum[i] - tmp;
            sum[i] = tmp;
        }
    }
    for (int i = 1; i <= n;i++)
        ans = max(ans, sum[i]);
    cout << ans << '\n';
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