// https://codeforces.com/problemset/problem/1417/B
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, t;
    cin >> n >> t;
    for (int i = 1, j = 0; i <= n;i++){
        int x;
        cin >> x;
        if(2*x<t)
            cout << 0 << ' ';
        else if(2*x>t)
            cout << 1 << ' ';
        else
            cout << j << ' ', j ^= 1;
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}