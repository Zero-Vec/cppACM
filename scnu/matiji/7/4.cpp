#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node{
    ll a, b;
    bool operator<(const node &u)const{
        return a > u.a;
    }
} d[N];
bool cmp(node t1,node t2){
    return t1.b > t2.b;
}
int n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> d[i].a >> d[i].b;
    sort(d + 1, d + 1 + n, cmp);
    ll ans = 0, sum = 0;
    priority_queue<node> pq;
    for (int i = 1; i <= n;i++){
        while(d[i].b<=pq.size()){
            node t = pq.top();
            pq.pop();
            sum -= t.a;
        }
        pq.push(d[i]);
        sum += d[i].a;
        ans = max(ans, sum);
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