#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int x, y;
    cin >> x >> y;
    if(x<0||y<0){
        cout << "PING\n";
        return;
    }
    if(abs(x-y) > 1){
        cout << "PING\n";
    }
    else{
        if((x+y)&1)
            cout << "YES\n";
        else
            cout << "NO\n";
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