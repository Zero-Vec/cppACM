#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N];
void solve(){
    int n,x;
    cin >> n;
    int mx = 0,mn=1e5+9;
    while(cin>>x){
        a[x]++;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    int res1, res2;
    for (int i = mn; i <= mx;i++){
        if(!a[i])
            res1 = i;
        if(a[i]>1)
            res2 = i;
    }
    cout << res1 << ' ' << res2;
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