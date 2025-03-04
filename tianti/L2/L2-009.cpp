#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
struct node{
    int id;
    double mo;
    int gs;
    bool operator<(const node &u)const{
        if(mo==u.mo){
            if(gs==u.gs)
                return id < u.id;
            else
                return gs > u.gs;
        }
        else
            return mo > u.mo;
    }
} d[N];
int n, k;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> k;
        d[i].id = i;
        while(k--){
            int x, y;
            cin >> x >> y;
            d[x].mo += y;
            d[x].gs++;
            d[i].mo -= y;
        }
    }
    sort(d + 1, d + 1 + n);
    for (int i = 1; i <= n;i++){
        cout << d[i].id << ' ';
        cout << fixed << setprecision(2) << d[i].mo / 100 << '\n';
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