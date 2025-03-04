#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int N = 1e6 + 9;
ll n, t, a[N], sum[N], ans;
ll q[N];
void merge_sort(int l,int r,ll *a){
    if(l>=r)
        return;
    int mid = l + r >> 1;
    merge_sort(l, mid, a);
    merge_sort(mid + 1, r, a);
    int i = l, j = mid + 1, t = 0;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j]){
            q[t++] = a[j++];
            ans += mid - i + 1;//降序序列，求非逆序数
            ans %= mod;
        }
        else
            q[t++] = a[i++];
    }
    while(i<=mid)
        q[t++] = a[i++];
    while(j<=r)
        q[t++] = a[j++];
    for (i = l, j = 0; i <= r;i++,j++)
        a[i] = q[j];
}
void solve(){
    //利用归并排序求伪逆序数（或求逆序数）
    cin >> n >> t;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        a[i] -= t;
        sum[i] = sum[i - 1] + a[i];
    }
    merge_sort(0, n, sum);
    cout << ans % mod;
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