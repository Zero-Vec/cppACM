#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e3+9;
ll a[N];
void solve(){
    int n;
    cin>>n;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n;i++){
        cin>>a[i];
        if(a[i]&1)cnt1++;
        else
            cnt2++;
    }
    cout << cnt1 << " " << cnt2;
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