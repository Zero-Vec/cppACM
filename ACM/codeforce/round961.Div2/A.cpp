#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, k;
    cin >> n >> k;
    if(k>=n*n){
        cout << 2 * n - 1<< '\n';
        return;
    }
    bool f = true, f2 = false;
    int tmp = n;
    ll ans = 0;
    while(k >= tmp){
        if(f){
            k -= tmp, tmp--, ans++;
            f = false;
        }
        else{
            for (int i = 1; i <= 2;i++){
                k -= tmp, ans++;
                if(k < tmp){
                    f2 = true;
                    break;
                }
            }
            if(f2)
                break;
            tmp--;
        }
    }
    if(k > 0)
        ans++;
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