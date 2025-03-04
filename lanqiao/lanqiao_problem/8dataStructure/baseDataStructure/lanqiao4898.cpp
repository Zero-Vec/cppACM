#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 30;
int pre[N];
int n;
string s, t;
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
struct Edge{
    int x, y, e;
    bool operator<(const Edge &u) const{
        return e < u.e;
    }
};
void solve()
{
    cin >> n;
    for (int i = 1; i < N; i++)
        pre[i] = i;
    cin >> s >> t;
    vector<Edge> v;
    for (int i = 0; i < n;i++){
        if(s[i]==t[i])continue;
        int x = s[i] - 'a' + 1, y = t[i] - 'a' + 1;
        v.push_back({x, y, 1});
    }
    int ans = 0;
    for(auto edge:v){
        if(root(edge.x)==root(edge.y))continue;
        ans++;
        pre[root(edge.x)] = root(edge.y);
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