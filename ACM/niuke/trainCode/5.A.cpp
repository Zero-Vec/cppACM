#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        if(x==1)
            cnt++;
    }
    cout << n - cnt;
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