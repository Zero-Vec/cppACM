// https://codeforces.com/problemset/problem/1772/C
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int k, n;
    cin >> k >> n;
    int num = 1;
    for (int i = 1; i <= k;i++){
        int t = min(num, n - k + i);
        num += i;
        cout << t << " ";
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