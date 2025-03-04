#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int L, n, k, a[N], l, r, mid, ans;
bool check(int p){
    int cnt = 0;
    for (int i = 2; i <= n;i++){
        int temp = a[i] - a[i - 1];
        int a1 = temp / p, a2 = temp % p;
        if(a1){
            if(a2)
                cnt += a1;
            else
                cnt += a1 - 1;
        }
    }
    if(cnt>k)
        return false;
    else
        return true;
}
void solve(){
    cin >> L >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    l = 0, r = L;
    while(l+1!=r){
        int mid = (l + r) / 2;
        if(check(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r;
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