#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int r, l;
    char c;
    cin >> l >> c;
    r = l / 2 + (l & 1 ? 1 : 0);
    for (int i = 1; i <= r;i++)
        for (int j = 1; j <= l;j++)
            if(j!=l)
                cout << c;
            else
                cout << c << "\n";
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