#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n, m, d[N], w[N];
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> d[i];
    for (int i = 1; i <= m;i++)
        cin >> w[i];
    sort(d + 1, d + 1 + n);
    sort(w + 1, w + 1 + m);
    if(n > m){
        cout << "NO\n";
    }
    else{
        for (int i = 1; i <= n;i++){
            if(d[i] > w[m - n + i]){
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
    }
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