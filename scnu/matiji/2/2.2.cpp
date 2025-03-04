#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int a[N];
int n;
void solve(){
    cin>>n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= n;i++){
        if(a[i]>a[i-1]){
            ans += a[i] - a[i - 1];
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