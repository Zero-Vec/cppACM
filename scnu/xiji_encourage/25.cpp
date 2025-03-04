#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int y, m;
void solve(){
    cin >> y >> m;
    if(y < 0 || y > 100000 || m < 1 || m > 12){
        cout << "Error!\n";
        return;
    }
    if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
        mon[2] = 29;
    cout << mon[m] << '\n';
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
