#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int a[N], cnt[N];
int n, b;
int sum, k;
void solve(){
    cin >> n >> b;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++){
        if (a[i] & 1)
            sum++;
        else
            sum--;
        if (!sum && i != n)
            cnt[++k] = abs(a[i + 1] - a[i]);
    }
    sort(cnt + 1, cnt + 1 + k);
    int ans = 0;
    for (int i = 1; i <= k;i++){
        if(b>=cnt[i]){
            b -= cnt[i];
            ans++;
        }
        else
            break;
    }
    cout << ans;
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