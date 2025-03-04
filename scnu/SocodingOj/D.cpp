#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 9;
int pre[N];
ll siz[N];
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
ll mo[N];
int n, m, k, a, b;
set<int> s;
struct node{
    int id;
    ll q;
    bool operator<(const node &u) const{
        return q == u.q ? id < u.id : q > u.q;
    }
};
void solve(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        pre[i] = i;
    while (m--){
        cin >> a >> b;
        if (pre[root(b)] < pre[root(a)])
            pre[root(a)] = root(b);
        else
            pre[root(b)] = root(a);
    }
    while (k--){
        int A, D;
        cin >> A >> D;
        while (D--){
            int c, d;
            cin >> c >> d;
            mo[c] += d;
            mo[A] -= d;
        }
    }
    /*
    for(int i=1;i<=n;i++)
        cout<<root(i)<<'\n';
    */
    for (int i = 1; i <= n; i++)
        s.insert(root(i));
    for (int i = 1; i <= n; i++){
        siz[root(i)] += mo[i];
    }
    vector<node> v;
    for (auto j : s){
        v.push_back({j, siz[j]});
    }
    sort(v.begin(), v.end());
    for (auto i : v){
        cout << i.id << ' ' << i.q << '\n';
    }
    /*
    for(int i=1;i<=n;i++)
        cout<<mo[i]<<'\n';
        */
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}