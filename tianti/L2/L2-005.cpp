#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=60;
vector<int> v[N];
int n;
//使用stl中的交集和补集即可
void solve(){
    cin>>n;
    for (int i = 1; i <= n;i++){
        int m;
        cin>>m;
        while(m--){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }
    for (int i = 1; i <= n;i++){
        sort(v[i].begin(), v[i].end());
    }
    int k;
    cin >> k;
    while(k--){
        int a,b;
        cin>>a>>b;
        vector<int> c, d;
        set_intersection(v[a].begin(), v[a].end(), v[b].begin(), v[b].end(), inserter(c, c.begin()));
        set_union(v[a].begin(), v[a].end(), v[b].begin(), v[b].end(), inserter(d, d.begin()));
        c.erase(unique(c.begin(), c.end()), c.end());
        d.erase(unique(d.begin(), d.end()), d.end());
        double ans = (c.size() * 100.0) / d.size();
        cout << fixed << setprecision(2) << ans << "%" << '\n';
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