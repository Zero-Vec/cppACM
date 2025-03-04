#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
double w[N], n;
int a, b;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a >> b;
        w[i] = 1.0 * b / a;
    }
    int id = -1;
    double res = 0;
    for (int i = 1; i <= n;i++)
        if(res < w[i])
            res = w[i], id = i;
    // for (int i = 1; i <= n;i++)
    //     cout << w[i] << " \n"[i == n];
    cout << id;
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