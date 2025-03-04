#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+9;
int a[N], dp[N];
int n, mx = 1, cnt = 1;
void solve(){
    //O(n)算法的最长连续递增子序列
    cin>>n;
    for (int i = 0;i<n;i++)
        cin>>a[i];
    dp[0]=a[0];
    for (int i = 0; i < n - 1;i++){
        if(a[i+1]>a[i]){
            cnt++;
            if(cnt>mx){
                mx = cnt;
                for (int j = 0; j < mx;j++)
                    dp[j] = a[i - j + 1];
            }
        }
        else
            cnt = 1;
    }
    for (int i = mx - 1; i >= 0;i--){
        if(!i)
            cout << dp[i];
        else
            cout << dp[i] << ' ';
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