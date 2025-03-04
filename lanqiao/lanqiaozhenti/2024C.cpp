#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n, k;
double T;
double a[N], tmp[N], sum[N],sum2[N];
bool check(int x){
    for (int i = 1; i <= x;i++)
        tmp[i] = a[i];
    sort(tmp + 1, tmp + 1 + x);
    memset(sum, 0, sizeof sum);
    memset(sum2, 0, sizeof sum2);
    for (int i = 1; i <= x;i++){
        sum[i] = sum[i - 1] + tmp[i];
        sum2[i] = sum2[i - 1] + tmp[i] * tmp[i];
    }
    for (int i = 1; i + k - 1 <= x; i++){
        double t = sum[i + k - 1] - sum[i - 1];
        double phi = sum2[i + k - 1] - sum2[i - 1] - 2 * t * t / k + k * (t / k) * (t / k);
        phi = phi / k;
        if(phi<T)
            return true;
    }
    return false;
}
void solve(){
    cin >> n >> k >> T;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int l = k - 1, r = n + 1;
    while(l+1!=r){
        int mid = (l + r) >> 1;
        if(check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << (r == n + 1 ? -1 : r) << '\n';
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