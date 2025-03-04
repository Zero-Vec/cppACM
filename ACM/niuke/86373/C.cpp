#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n, a[N];
void solve(){
    cin >> n;
    int cnt1 = 0, cnt2 = 0, ans = 0;
    map<int, int> mp;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(a[i]<0)
            cnt1++;
        else
            mp[a[i]]++;
    }
    for(auto [x,y]:mp){
        cnt2 += (y % 2);
    }
    if(cnt1>=cnt2){
        ans = (cnt1 - cnt2) % 2;
    }
    else{
        ans = cnt2 - cnt1;
    }
    cout << ans << '\n';
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
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N], n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int id = -1;
    for (int i = 1; i <= n;i++){
        if(a[i]<0){
            id = i;
            break;
        }
    }
    if(id==-1&&a[n]==0){
        cout << (n & 1 ? 1 : 0);
        return;
    }
    int l = 1, r = n, cnt = 0;
    while((a[l]<0&&a[r]>=0)||(a[l]==0&&a[r]==0)){
        cnt += 2;
        l++, r--;
    }
    if(l==r){
        cout << 1;
        return;
    }
    if(l>r){
        cout << 0;
        return;
    }
    if(a[r]<0){
        cout << ((r - l) & 1 ? 0 : 1);
        return;
    }
    cout << n - cnt;
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
*/