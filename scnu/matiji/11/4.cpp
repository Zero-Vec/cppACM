#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1007;
struct node{
    double x, y, r, l;
    bool v;
    bool operator<(const node &u)const{
        return r < u.r;
    }
} e[N];
void solve(){
    int n;
    double r;
    while(cin >> n >> r && !(n == 0 && r == 0)){
        bool tag = false;
        memset(e, 0, sizeof e);
        for (int i = 1; i <= n;i++){
            cin >> e[i].x >> e[i].y;
            if(r*r<e[i].y*e[i].y)
                tag = true;
            else{
                e[i].l = -sqrt(r * r - e[i].y * e[i].y) + e[i].x;
                e[i].r = sqrt(r * r - e[i].y * e[i].y) + e[i].x;
                e[i].v = false;
            }
        }
        if(tag){
            cout << -1 << '\n';
            continue;
        }
        sort(e + 1, e + 1 + n);
        int ans = 0;
        for (int i = 1; i <= n;i++){
            if(e[i].v==false){
                for (int j = i; j <= n;j++){
                    if(e[j].v==false&&e[j].l<=e[i].r){
                        e[j].v = true;
                    }
                }
                e[i].v = true;
                ans++;
            }
        }
        cout << ans << '\n';
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