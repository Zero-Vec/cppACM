#include<iostream>
using namespace std;
using ll = long long;
int n;
int a[60];
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int l = 1;
    int ans = 0;
    while(l<n){
        int minn = min(a[l], a[l + 1]), maxn = max(a[l], a[l + 1]);
        if(2*minn>=maxn){
            l++;
            continue;
        }
        while(2*minn<maxn){
            minn *= 2;
            ans++;
        }
        l++;
    }
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