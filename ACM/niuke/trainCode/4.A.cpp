#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int a,b,k;
    cin >> a >> b >> k;
    if(a>=k*b){
        cout << "good";
    }
    else
        cout << "bad";
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