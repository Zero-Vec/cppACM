#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];
int main()
{
    //快慢指针法
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int sum = 0;
    int ans = n + 1;
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j < i || (sum < s && j < n))
            sum += a[++j];
        if (sum >= s)
        {
            ans = min(ans, j - i + 1);
            sum -= a[i];
        }
    }
    cout << (ans == n + 1 ? 0 : ans);
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+9;
ll a[N], pre[N];
int n, s;
bool check(int mid){
    ll sum = 0;
    for (int i = 1; i + mid - 1 <= n;i++){
        if(pre[i+mid-1]-pre[i-1]>=s)
            return true;
    }
    return false;
}
void solve(){
    //二分＋前缀和的写法
    cin>>n>>s;
    ll mx = 0;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        mx = max(mx, a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    int l = 1, r = n;
    if(pre[n]<s)
        cout << 0;
    else{
        if(mx>=s)
            cout << 1;
        else{
            while(l<r){
                int mid = (l + r) / 2;
                if(check(mid))
                    r = mid;
                else
                    l = mid + 1;
            }
            cout << r;
        }
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
*/