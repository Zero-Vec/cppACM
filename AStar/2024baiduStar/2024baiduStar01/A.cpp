#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
struct node{
    ll p, s;
    bool operator<(const node &u)const{
        return p + s < u.p + u.s;
    }
} a[N];
ll n, b, sum[N];
void solve(){
    cin >> n >> b;
    for (int i = 1; i <= n;i++){
        cin >> a[i].p >> a[i].s;
        sum[i] = a[i].p + a[i].s;
    }
    sort(a + 1, a + 1 + n);
    sort(sum + 1, sum + 1 + n);
    //枚举每一个作为优惠
    int ans = 0;
    for (int i = 1; i <= n;i++){
        ll cnt = 0;
        int num = 0;
        cnt += a[i].p / 2 + a[i].s;
        if(cnt>b)continue;
        num++;
        for (int j = 1; j <= n;j++){
            if(j==i)continue;
            cnt += sum[j];
            if(cnt>b)
                break;
            num++;
        }
        ans = max(ans, num);
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