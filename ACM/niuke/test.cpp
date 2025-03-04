#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int x;
    cin >> x;
    int cnt = 0;
    if((x/10)%10!=x%10){
        cout << "No\n";
        return;
    }
    while(x){
        cnt++;
        x /= 10;
    }
    cout << (cnt == 2 ? "Yes\n" : "No\n");
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