#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4e5 + 9;
int n, m, l[N], r[N], ans, a[N], tot;
bool mark[N];
struct node{
    int id, v;
    bool operator<(const node &u)const{
        return v < u.v;
    }
} tmp;
priority_queue<node> q;
void solve(){
    cin >> n >> m;
    if(m>n/2){
        cout << "Error!";
        return;
    }
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 2; i < n;i++){
        l[i] = i - 1, r[i] = i + 1;
        q.push({i, a[i]});
    }
    l[1] = n, l[n] = n - 1;
    r[1] = 2, r[n] = 1;
    q.push({1, a[1]});
    q.push({n, a[n]});
    tot = n;//当前结点个数
    for (int i = 1; i <= m;i++){
        tmp = q.top();
        q.pop();
        if(mark[tmp.id]){
            i--;
            continue;
        }
        ans += tmp.v;
        a[++tot] = a[l[tmp.id]] + a[r[tmp.id]] - a[tmp.id];
        mark[l[tmp.id]] = mark[tmp.id] = mark[r[tmp.id]] = 1;
        q.push({tot, a[tot]});
        l[tot] = l[l[tmp.id]];
        r[tot] = r[r[tmp.id]];
        r[l[l[tmp.id]]] = tot;
        l[r[r[tmp.id]]] = tot;
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