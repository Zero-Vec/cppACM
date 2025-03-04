#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    unsigned int x;
    cin >> x;
    int cnt = 0;
    while(x){
        if(x&1)
            cnt++;
        x >>= 1;
    }
    cout << cnt;
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