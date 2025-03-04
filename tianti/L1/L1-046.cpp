#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int x;
    cin >> x;
    char ans[1100];
    int cnt = 0, s = 0, wei = 0;
    while(1){
        s = s * 10 + 1;
        wei++;
        if(cnt||s/x){//商第一位为0时不存入数组中??
            ans[cnt] = '0' + s / x;
            cnt++;
        }
        s %= x;
        if(!s){
            ans[cnt] = '\0';
            cout << ans;
            cout << " " << wei;
            break;
        }
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