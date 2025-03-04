#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 9;
int n;
ll a[N], t[N];
vector<int> ls;
int bin(int x){
    return lower_bound(ls.begin(), ls.end(), x) - ls.begin() + 1;
}
int lowbit(int x){
    return x & -x;
}
void update(int k,int x){
    for (int i = k; i <= ls.size(); i += lowbit(i))
        t[i] += x;
}
ll getsum(int k){
    ll res = 0;
    for (int i = k; i >= 1; i -= lowbit(i))
        res += t[i];
    return res;
}
void solve(){
    // 逆序数: 树状数组+离散化
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
        update(bin(a[i]), 1);
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