#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
struct node{
    ll a, b;
    bool operator<(const node &u)const{
        return a <= u.a;
    }
}d[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> d[i].a >> d[i].b;
    int l = 1, r = n;
    sort(d + 1, d + 1 + n);
    ll ans = 0;
    while(l<r){
        if(d[l].a==d[r].a)
            break;
        if(d[l].b==d[r].b){
            ans += d[l].b * (d[r].a - d[l].a);
            r--, l++;
        }
        else if(d[l].b<d[r].b){
            ans += d[l].b * (d[r].a - d[l].a);
            d[r].b -= d[l].b;
            l++;
        }
        else{
            ans += d[r].b * (d[r].a - d[l].a);
            d[l].b -= d[r].b;
            r--;
        }
    }
    cout << ans << '\n';
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