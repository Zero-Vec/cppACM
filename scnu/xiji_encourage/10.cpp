#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, m;
    cin >> n >> m;
    double sum = 0.0, last = n;
    for (int i = 1; i <= m;i++){
        if(i == 1){
            sum += last;
            last *= 0.25;
        }
        else{
            sum += 2.0 * last;
            last *= 0.25;
        }
    }
    cout << fixed << setprecision(2);
    cout << sum << '\n'
         << last << '\n';
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