#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll t[N], n, a[N];
int lowbit(int x){
    return x & -x;
}
void update(int k){
    for (int i = k; i <= n;i+=lowbit(i))
        t[i]++;
}
ll getsum(int k){
    ll res = 0;
    for (int i = k; i >= 1;i-=lowbit(i))
        res += t[i];
    return res;
}
vector<int> ls;
int bin(int x){
    return lower_bound(ls.begin(), ls.end(), x) - ls.begin() + 1;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        ls.push_back(a[i]);
    }
    sort(ls.begin(),ls.end());
    ls.erase(unique(ls.begin(), ls.end()), ls.end());
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        ans += getsum(ls.size()) - getsum(bin(a[i]));
        update(bin(a[i]));
    }
    cout << ans << '\n';
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