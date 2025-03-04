#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int n, a[N], b[N], mn[N][20], mx[N][20], Lg[N];
int l, r, mid, ans;
void pre(){
    Lg[1] = 0;
    for (int i = 2; i <= n;i++)
        Lg[i] = Lg[i >> 1] + 1;
}
void ST_create(){
    for (int i = 1; i <= n;i++)
        mx[i][0] = a[i], mn[i][0] = b[i];
    for (int j = 1; j <= Lg[n];j++)
        for (int i = 1; i <= n - (1 << j) + 1;i++)
            mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]),
            mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
}
int ST_qmax(int l,int r){
    int k = Lg[r - l + 1];
    return max(mx[l][k], mx[r - (1 << k) + 1][k]);
}
int ST_qmin(int l,int r){
    int k = Lg[r - l + 1];
    return min(mn[l][k], mn[r - (1 << k) + 1][k]);
}
int findl(int i){
    int l = 1, r = i, mid, ans = 0, minn, maxn;
    while(l<=r){
        mid = (l + r) >> 1;
        maxn = ST_qmax(mid, i), minn = ST_qmin(mid, i);
        if(maxn<=minn)
            ans = mid, r = mid - 1;
        else
            l = mid + 1;
    }
    return ans;
}
int findr(int i){
    int l = 1, r = i, mid, ans = 0, minn, maxn;
    while (l <= r){
        mid = (l + r) >> 1;
        maxn = ST_qmax(mid, i), minn = ST_qmin(mid, i);
        if (maxn >= minn)
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    return ans;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        cin >> b[i];
    pre();
    ST_create();
    for (int i = 1; i <= n;i++){
        int j = findl(i);
        if(j<1||j>i)continue;
        int k = findr(i);
        ans += k - j + 1;
    }
    cout << ans;
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