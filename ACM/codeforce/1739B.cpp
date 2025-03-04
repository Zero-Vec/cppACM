// https://codeforces.com/problemset/problem/1739/B
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[110], d[110];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> d[i];
    a[1] = d[1];
    for (int i = 2; i <= n;i++){
        if(d[i]&&a[i-1]-d[i]>=0){
            cout << -1 << '\n';
            return;
        }
        a[i] = a[i - 1] + d[i];
    }
    for (int i = 1; i <= n;i++)
        cout << a[i] << " \n"[i == n];
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