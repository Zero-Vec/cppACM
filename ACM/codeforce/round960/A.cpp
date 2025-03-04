#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 55;
int a[N], n, cnt[N];
void solve(){
    cin >> n;
    for (int i = 0; i < N;i++)
        a[i] = cnt[i] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = N - 1; i >= 1;i--){
        if(!cnt[i])continue;
        if(cnt[i] & 1){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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