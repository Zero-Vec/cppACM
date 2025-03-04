#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int n, k;
struct node{
    int x, id;
    bool operator<(const node &u)const{
        return x == u.x ? id < u.id : x < u.x;
    }
}a[N];
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n;i++){
        int t;
        cin >> t;
        a[i] = {t, i};
    }
    sort(a + 1, a + 1 + n);
    set<int> s;
    for (int i = 1; i < n;i++){
        if(a[i].x==a[i+1].x&&a[i+1].id-a[i].id<=k)
            s.insert(a[i].x);
    }
    ll ans = 0;
    for(auto i:s){
        ans = ans ^ i;
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