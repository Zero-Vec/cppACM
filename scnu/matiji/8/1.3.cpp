#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node
{
    ll x, t;
    bool operator<(const node &u) const
    {
        return x < u.x;
    }
} d[N];
ll cmp[N];
ll n, m;
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> d[i].x >> d[i].t;
    ll ans = 0;
    ll sum = 0;
    ll cnt = 0;
    sort(d + 1, d + 1 + n);
    for (int i = 1; i <= n; i++)
        cmp[i] = d[i].x - d[i - 1].x;
    priority_queue<ll> pq;
    for (int i = 1; i <= n; i++)
    {
        m -= cmp[i];
        if (sum + d[i].t <= m)
        {
            cnt++;
            sum += d[i].t;
            pq.push(d[i].t);
            ans = max(ans, cnt);
        }
        else
        {
            if (pq.size())
            {
                ll tmp = pq.top();
                if (tmp > d[i].t + cmp[i])
                {
                    pq.pop();
                    sum -= tmp;
                    sum += d[i].t;
                    pq.push(d[i].t);
                }
            }
        }
    }
    cout << ans;
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
/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node{
    ll x, t;
    bool operator<(const node &u) const{
        return x < u.x;
    }
} d[N];
ll n, m;
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> d[i].x >> d[i].t;
    sort(d + 1, d + 1 + n);
    ll sum = 0;
    priority_queue<ll> pq;
    for (int i = 1; i <= n;i++){
        if(sum+d[i].x+d[i].t<=m){
            pq.push(d[i].t);
            sum += d[i].t;
        }
        else{
            if(pq.size()&&sum+d[i].x-pq.top()+d[i].t<=m){
                sum -= pq.top();
                pq.pop();
                pq.push(d[i].t);
                sum += d[i].t;
            }
        }
    }
    cout << pq.size();
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
*/