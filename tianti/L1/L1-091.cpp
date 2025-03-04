#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, m, k;
    string x;
    cin >> n >> x >> m >> k;
    if(k==n)
        cout << "mei you mai " << x << " de";
    else if(k==m)
        cout << "kan dao le mai " << x << " de";
    else
        cout << "wang le zhao mai " << x << " de";
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