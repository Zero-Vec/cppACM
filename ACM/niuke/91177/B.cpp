#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll n, x, a[N];
void solve(){
    cin >> n >> x;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    ll tmp = x, sum = 0;
    for (int i = 1; i <= n;i++){
        if (tmp == 0)
            break;
        if(tmp >= a[i]){
            sum += a[i], tmp -= a[i];
        }
        else{
            sum += a[i];
            if(tmp > 0){
                tmp -= a[i];
            }
            else{
                tmp += a[i];
            }
        }
    }
    cout << sum << '\n';
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