#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e6 + 9, base = 131;
char s[N];
ull h[N], hr[N], b[N];
int n;
ull gethash(int l,int r){
    return h[r] - h[l - 1] * b[r - l + 1];
}
ull gethashRev(int l,int r){
    return hr[l] - hr[r + 1] * b[r - l + 1];
}
bool check(int mid){
    for (int i = 1; i <= n - mid + 1;i++){
        int j = i + mid - 1;
        if(gethash(i,j)==gethashRev(i,j))
            return true;
    }
    return false;
}
void solve(){
    cin >> n;
    cin >> s + 1;
    b[0] = 1;
    for (int i = 1; i <= n;i++){
        h[i] = h[i - 1] * base + s[i] - 'a' + 1;
        b[i] = b[i - 1] * base;
    }
    for (int i = n; i >= 1;i--)
        hr[i] = hr[i + 1] * base + s[i] - 'a' + 1;
    int l = 1, r = n + 1;
    int ans = 1;
    while(l+1!=r){
        int mid = (l + r) >> 1;
        if(check(2*mid-1))
            l = mid;
        else
            r = mid;
    }
    ans = max(ans, 2 * l - 1);
    l = 1, r = n + 1;
    while(l+1!=r){
        int mid = (l + r) >> 1;
        if(check(2*mid))
            l = mid;
        else
            r = mid;
    }
    ans = max(ans, 2 * l);
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