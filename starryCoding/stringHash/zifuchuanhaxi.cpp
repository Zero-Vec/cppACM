//string-hash
//进制哈希：将一段字符串看作base（质数131，1771）进制的一个大整数
//一：快速判断两个字符串（子串）是否相等O(1)
//二：判断子串是否回文，正向哈希，方向哈希；
//类似前缀和，前缀哈希
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e6 + 9, base = 131;
ull h[N], b[N], hr[N];
char s[N];
int n, q;
ull gethash(int l,int r){
    return h[r] - h[l - 1] * b[r - l + 1];
}
ull gethashRev(int l,int r){
    return hr[l] - hr[r + 1] * b[r - l + 1];
}
void solve(){
    cin >> n;
    b[0] = 1;
    for (int i = 1; i <= n;i++){
        cin >> s[i];
        h[i] = h[i - 1] * base + s[i] - 'a' + 1;
        b[i] = b[i - 1] * base;
    }
    for (int i = n; i >= 1;i--)
        hr[i] = hr[i + 1] * base + s[i] - 'a' + 1;
    cin >> q;
    while(q--){
        //int l, r, x, y;
        //cin >> l >> r >> x >> y;
        //cout << (gethash(l, r) == gethash(x, y) ? "YES" : "NO") << '\n';
        int l, r;
        cin >> l >> r;
        cout << (gethash(l, r) == gethashRev(l, r) ? "YES" : "NO") << '\n';
    }
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