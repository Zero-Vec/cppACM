#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll prefix[N];
struct Node{
    int x=0, y=0;
    bool operator <(const Node &b)const{
        return x == b.x ? y < b.y : x < b.x;
    }
} s[N];
void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> s[i].x >> s[i].y;
    }
    sort(s + 1, s + n + 1);
    for (int i = 1; i <= n;i++){
        prefix[i] = prefix[i - 1] + s[i].y;
    }
    ll ans = m;
    for (int i = 1; i <= n;i++){
        if(s[i].x-prefix[i]<=m){
            ans = m + prefix[i];
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}