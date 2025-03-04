#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, p;
/*
int sg(int x) {
    if(f[x]!=-1) {
        return f[x];
    }
    set<int>s;
    for(int i=0; i<10; i++) {
        if(x>=pow(p,i)) {
            s.insert(sg(x-pow(p,i)));
        }
    }
    for(int i=0;; i++) {
        if(!s.count(i)) {
            return f[x]=i;
        }
    }

}
*/
int sg(ll x)
{
    if (x == p)
        return 2;
    if (x & 1)
        return 1;
    return 0;
}
void solve()
{
    cin >> n >> p;
    if (p & 1)
    {
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            if (x & 1)
                ans ^= 1;
            else
                ans ^= 0;
        }
        cout << (ans ? "GOOD" : "BAD");
        return;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        ans ^= sg(x % (p + 1));
    }
    cout << (ans ? "GOOD" : "BAD");
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}