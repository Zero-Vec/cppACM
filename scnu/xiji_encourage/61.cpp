#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int mons[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool check(int y){
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}
void solve(){
    int y, m, d;
    cin >> y >> m >> d;
    int ans = 0;
    if(check(y))
        mons[2] = 29;
    for (int i = 1; i < m;i++)
        ans += mons[i];
    cout << ans + d << '\n';
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