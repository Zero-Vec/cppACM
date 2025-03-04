#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int col[N], n;
void solve()
{
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> col[i];
        mp[col[i]]++;
    }
    int cnt = mp.size(), ans = 0, cnt2 = 0; // 答案，当前消失种类数
    set<int> s;
    for (int i = n; i >= 1; i--)
    {
        s.insert(col[i]);
        mp[col[i]]--;
        if (mp[col[i]] == 0)
            cnt2++;
        if (s.size() == cnt)
        {
            ans++;
            // cout << i << '\n';
            cnt -= cnt2;
            s.clear();
            cnt2 = 0;
        }
    }
    if (s.size())
        ans++;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int a[N];
int col[3];
map<int, int> mp;
void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        col[a[i]]++;
        if(col[a[i]]==1)
            cnt++;
    }
    int cnt1 = 0, cnt2 = 0, ans = 0;
    for (int i = n; i >= 1;i--){
        mp[a[i]]++, col[a[i]]--;
        if(mp[a[i]]==1)
            cnt1++;
        if(col[a[i]]==0)
            cnt2++;
        if(cnt1==cnt){
            ans++;
            cnt -= cnt2;
            mp.clear();
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
*/