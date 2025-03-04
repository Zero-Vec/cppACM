#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[10], n, l;
void solve(){
    cin >> l >> n;
    int id = pow(26, l) - n;
    for (int i = 0; i < l;i++){
        a[i] = id % 26;
        id /= 26;
    }
    for (int i = l - 1; i >= 0;i--)
        cout << char(a[i] + 'a');
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