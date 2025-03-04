#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[110];
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        if (k % a[i] == 0)
        {
            ans = min(ans, k / a[i]);
        }
    }
    cout << (ans == 1e9 ? -1 : ans);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k, a[110];
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    bool tag = false;
    int res = 1e9;
    for (int i = n; i >= 1;i--){
        int ans = 1e9;
        int t = k / a[i];
        if(k % a[i] == 0){
            tag = true;
            ans = t;
        }
        else{
            int b = k % a[i];
            for (int j = 1; j < i;j++){
                if(a[j] == b){
                    ans = t + 1;
                }
            }
        }
        res = min(res, ans);
    }
    cout << (tag ? res : -1);
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