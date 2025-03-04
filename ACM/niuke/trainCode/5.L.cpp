#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, x;
    cin >> n >> x;
    for (int i = 0; i <= n;i++){
        if(i-(n-i)==x){
            cout << i << " " << n - i;
            return;
        }
    }
    cout << -1;
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