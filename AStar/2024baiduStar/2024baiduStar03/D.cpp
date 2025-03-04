#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int a[N];
int n;
map<int, int> mp;
void solve()
{
    cin >> n;
    set<int> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v.insert(a[i]);
    }
    int ans1 = 0, num = 0;
    bool tag = false;
    for (int i = 1; i <= n; i++)
    {
        int l = i;
        num = 1;
        while (l <= n && a[l] == a[l - 1])
            num++, l++;
        ans1 = max(ans1, num);
        num = 0;
    }
    //cout << ans1;
    int res = 0;
    for(auto k:v){
        for (int i = 1; i <= n;i++){
            int l = i;
            num = 1;
            int gs = 0;
            while(l <= n ){
                if(a[l]==k){
                    gs++;
                    l++;
                    continue;
                }
                if(a[l]==a[l-gs-1]){
                    num++;
                    l++;
                    gs = 0;
                }
                else
                    break;
            }
            res = max(num, res);
        }
    }
    cout << res - ans1;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}