#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node{
    ll d, p;
    bool operator<(const node &u)const{
        return p > u.p;
    }
}d[N];
bool cmp(node a,node b){
    return a.d < b.d;
}
int n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> d[i].d >> d[i].p;
    sort(d + 1, d + 1 + n, cmp);
    priority_queue<node> pq;
    ll ans = 0, sum = 0;
    for (int i = 1; i <= n;i++){
        pq.push(d[i]);
        sum += d[i].p;
        while(pq.size()>d[i].d){
            node t = pq.top();
            pq.pop();
            sum -= t.p;
        }
        ans = max(sum, ans);
    }
    cout << ans;
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