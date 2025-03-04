#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll pre[N], nex[N];
int n, q;
struct node{
    ll a, b;
    bool operator<(const node &u)const{
        return b < u.b;
    }
} d[N];
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> d[i].a;
    for (int i = 1; i <= n;i++)
        cin >> d[i].b;
    sort(d + 1, d + 1 + n);
    for (int i = 1; i <= n;i++)
        pre[i] = pre[i - 1] + d[i].a * d[i].b;
    for (int i = n; i >= 1;i--)
        nex[i] = nex[i + 1] + d[i].a;
    cin >> q;
    while(q--){
        ll k;
        cin >> k;
        int l = 0, r = n + 1;
        while(l+1!=r){
            int mid = (l + r) >> 1;
            if(d[mid].b>=k)
                r = mid;
            else
                l = mid;
        }
        cout << pre[r - 1] + nex[r] * k << '\n';
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