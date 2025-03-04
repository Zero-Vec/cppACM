#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int ans = 0;
    for (int i = 10; i <= 1e9;i++){
        int t = i;
        int tmp = i;
        int cnt = 0;
        while(t){
            cnt++;
            t /= 10;
        }
        if(cnt&1)continue;
        int k = cnt / 2;
        int sum1 = 0, sum2 = 0;
        for (int j = 1; j <= k;j++){
            sum1 += tmp % 10;
            tmp /= 10;
        }
        for (int j = 1; j <= k; j++){
            sum2 += tmp % 10;
            tmp /= 10;
        }
        if(sum1==sum2){
            ans++;
            //cout << i << '\n';
        }
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