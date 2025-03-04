#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int a[N];//初始序列
int v[N];//每个颜色的个数
map<int, int> mp;
void solve(){
    int n;
    cin >> n;
    int cnt = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        v[a[i]]++;
        if(v[a[i]]==1)
            cnt++;
    }
    int ans = 0;
    for (int i = n; i >= 1;i--){
        mp[a[i]]++, v[a[i]]--;
        if(v[a[i]]==0)
            cnt2++;
        if(mp[a[i]]==1)
            cnt1++;
        if(cnt==cnt1){
            ans++;
            mp.clear();
            cnt -= cnt2;
            cnt1 = 0, cnt2 = 0;
        }
    }
    cout << ans << "\n";
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