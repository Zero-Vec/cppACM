#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll n, a[N], pre[N];
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    if(n==1){
        cout << 0 << '\n';
        return;
    }
    ll ans = 0, mx = 0, mn = 2e18;
    for (int i = 1; i <= n / 2;i++){
        if(n % i == 0){
            mx = 0, mn = 2e18;
            for (int j = 1; j <= n / i;j++){
                mx = max(mx, pre[j * i] - pre[(j - 1) * i]);
                mn = min(mn, pre[i * j] - pre[(j - 1) * i]);
            }
            ans = max(ans, mx - mn);
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
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll n, a[N];
bool judge(int x){
    if(x==2)
        return true;
    for (int i = 2; i <= sqrt(x);i++)
        if(x%i==0)
            return true;
    return false;
}
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    if (n == 1){
        cout << 0 << "\n";
        return;
    }
    sort(a + 1, a + 1 + n);
    ll c1 = 0, c2 = 0;
    if(judge(n)){
        // n不是素数
        int i = 2;
        while(n%i!=0){
            i++;
        }
        for (int j = 1; j <= n / i;j++)
            c1 += a[j];
        for (int j = n; j >= n - n / i + 1;j--)
            c2 += a[j];
        // cout << c2 << " " << c1 << '\n';
        cout << c2 - c1 << '\n';
    }
    else{
        // n是素数
        cout << a[n] - a[1] << '\n';
    }
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
*/