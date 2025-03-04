#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
int n, a[N], w;
void solve(){
    cin >> w >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 1, r = n;
    int ans = 0;
    while (l<r){
        if(a[r]+a[l]>w){
            ans++, r--;
        }
        else{
            ans++, l++, r--;
        }
    }
    cout << (l == r ? ans + 1 : ans) << '\n';
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