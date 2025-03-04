#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int x;
    int cnt = 0;
    while(cin>>x&&x!=250){
        cnt++;
    }
    cout << cnt + 1;
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