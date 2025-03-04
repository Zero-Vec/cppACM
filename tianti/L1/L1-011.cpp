#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string ans,a,b;
    getline(cin,a);
    getline(cin, b);
    for (int i = 0; i < a.size();i++){
        if(b.find(a[i])==-1)
            ans += a[i];
    }
    //cout << a.size() << '\n';
    cout << ans;
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