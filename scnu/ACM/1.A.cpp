#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, k;
    cin >> n >> k;
    int ans = n - k;
    if(n==k){
        if(n==1){
            cout << 0 << '\n';
            return;
        }
        else{
            if (k & 1){
                int id = k / 2 + 1;
                ans += k - id;
                cout << ans << '\n';
                for (int i = id; i < k; i++)
                    cout << i << " \n"[i == k - 1];
                return;
            }
            else{
                int id = k / 2;
                ans += k - id;
                cout << ans << '\n';
                for (int i = id; i < k; i++)
                    cout << i << " \n"[i == k - 1];
                return;
            }
        }
    }
    if(k&1){
        int id = k / 2 + 1;
        ans += k - id;
        cout << ans << '\n';
        for (int i = id; i < k;i++)
            cout << i << ' ';
        for (int i = k + 1; i <= n;i++)
            cout << i << " \n"[i == n];
    }
    else{
        int id = k / 2;
        ans += k - id;
        cout << ans << '\n';
        for (int i = id; i < k; i++)
            cout << i << ' ';
        for (int i = k + 1; i <= n; i++)
            cout << i << " \n"[i == n];
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}