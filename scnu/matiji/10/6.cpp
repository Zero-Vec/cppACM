#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll n, m, a[N], b[N], top;
struct node{
    ll k, x;
} st[N];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    while(m--){
        ll k, x;
        cin >> k >> x;
        while(top && st[top].x <= x)
            top--;
        st[++top] = {k, x};
    }
    ll nn = st[1].x;
    sort(b + 1, b + 1 + nn);
    ll l = 1, r = nn;
    st[top + 1].x = 0;
    for (int i = 1; i <= top;i++){
        ll t = st[i].x - st[i + 1].x;
        if(st[i].k==1)
            while(t--)
                a[nn--] = b[r--];
        else
            while(t--)
                a[nn--] = b[l++];
    }
    for (int i = 1; i <= n;i++)
        cout << a[i] << " ";
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