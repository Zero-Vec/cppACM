#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9;
int n, q;
struct node{
    int x, y;
}add[N],que[N];
vector<int> ls;
ll a[N];
int getidx(int x){
    return lower_bound(ls.begin(), ls.end(), x) - ls.begin() + 1;
}
void solve(){
    cin >> n >> q;
    for (int i = 1; i <= n;i++){
        int x, w;
        cin >> x >> w;
        add[i] = {x, w};
        ls.push_back(x);
    }
    for (int i = 1; i <= q;i++){
        int l, r;
        cin >> l >> r;
        ls.push_back(l), ls.push_back(r);
        que[i] = {l, r};
    }
    sort(ls.begin(), ls.end());
    ls.erase(unique(ls.begin(), ls.end()), ls.end());
    for (int i = 1; i <= n;i++){
        int id = getidx(add[i].x);
        int w = add[i].y;
        a[id] += w;
    }
    for (int i = 1; i <= ls.size();i++)
        a[i] += a[i - 1];
    for (int i = 1; i <= q; i++){
        int l = getidx(que[i].x), r = getidx(que[i].y);
        cout << a[r] - a[l - 1] << '\n';
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