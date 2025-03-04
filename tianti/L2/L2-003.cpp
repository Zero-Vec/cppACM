#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int n;
double cnt;
struct node{
    double w,sum;
    double a;
    bool operator<(const node &u)const{
        return a > u.a;
    }
} d[N];
void solve(){
    cin >> n >> cnt;
    for (int i = 1; i <= n;i++)
        cin >> d[i].w;
    for (int i = 1; i <= n;i++){
        cin >> d[i].sum;
        d[i].a = 1.0 * d[i].sum / d[i].w;
    }
    sort(d + 1, d + 1 + n);
    double ans = 0;
    int id = 1;
    for (int i = 1; i <= n;i++){
        if(cnt-d[i].w<=0){
            ans += cnt * d[i].a;
            break;
        }
        cnt -= d[i].w;
        ans += d[i].sum;
    }
    cout << fixed << setprecision(2) << ans;
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