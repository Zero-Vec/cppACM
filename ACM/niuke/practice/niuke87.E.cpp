#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
ll a[N], b[N];
void solve(){
    int n;
    cin >> n;
    ll maxn = -1e9 - 2;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    b[1] = 0;
    for (int i = 2; i <= n;i++){
        if(a[i]>=a[i-1])
            b[i] = 0;
        else{
            b[i] = a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    for (int i = 1; i <= n;i++)
        cout << b[i] << " ";
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