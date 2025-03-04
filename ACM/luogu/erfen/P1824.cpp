#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N], n, m;
bool check(int mid){
    int ans = 1;
    int t = a[1];
    for (int i = 2; i <= n;i++){
        if(a[i]-t>=mid){
            ans++;
            t = a[i];
        }
    }
    return ans >= m;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 0, r = 1e9 + 9;
    while(l+1!=r){
        int mid = (l + r) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l;
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