#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int a[N], dp1[N], dp2[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++){
        dp1[i] = 1;
        for (int j = 1; j < i;j++){
            if(a[i]>=a[j])
                dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }
    for (int i = n; i >= 1;i--){
        dp2[i] = 1;
        for (int j = n; j > i;j--){
            if(a[i]>=a[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n;i++){
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }
    cout << n - ans;
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