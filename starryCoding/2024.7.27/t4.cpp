#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node{
    ll x, y, z;
    bool operator<(const node &u)const{
        if(x!=u.x)
            return x > u.x;
        else{
            return y < u.y;
        }
    }
};
ll n, L, v[N], t[N];
void solve(){
    cin >> L >> n;
    priority_queue<node> pq;
    for (int i = 1; i <= n;i++)
        cin >> v[i];
    for (int i = 1; i <= n;i++){
        cin >> t[i];
        pq.push({1, v[i], t[i]});
    }
    ll ans = 0;
    while(L>0){
        node tmp = pq.top();
        pq.pop();
        ans = tmp.x;
        L -= tmp.y;
        tmp.x += tmp.z;
        pq.push(tmp);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}