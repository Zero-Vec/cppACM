#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 7;
int n, m, a[N], pre[N];
priority_queue<int> pq[N];
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        pre[i] = i;
    }
    while(m--){
        int x, y;
        cin >> x >> y;
        pre[root(x)] = root(y);
    }
    for (int i = 1; i <= n;i++)
        pq[root(i)].push(a[i]);
    for (int i = 1; i <= n;i++){
        int k = root(i);
        cout << pq[k].top() << " ";
        pq[k].pop();
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