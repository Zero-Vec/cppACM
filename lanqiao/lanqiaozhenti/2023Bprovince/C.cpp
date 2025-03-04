#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
int a[N], b[N], n;
bool check_min(int mid){
    for (int i = 1; i <= n;i++)
        if(a[i]/mid>b[i])
            return false;
    return true;
}
bool check_max(int mid){
    for (int i = 1; i <= n;i++)
        if(a[i]/mid<b[i])
            return false;
    return true;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i] >> b[i];
    int l = 0, r = 1e9;
    int ans1 = 0, ans2 = 0;
    while(l+1!=r){
        int mid = (l + r) / 2;
        if(check_min(mid))
            r = mid;
        else
            l = mid;
    }
    ans1 = r;
    l = ans1, r = 1e9 + 1;
    while(l+1!=r){
        int mid = (l + r) / 2;
        if(check_max(mid))
            l = mid;
        else
            r = mid;
    }
    ans2 = l;
    cout << ans1 << ' ' << ans2;
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