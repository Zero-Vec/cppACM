#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int a[N];
int n, m;
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    while(m--){
        int l, r;
        cin >> l >> r;
        while(l < r)
            swap(a[l++], a[r--]);
    }
    for (int i = 1; i <= n;i++)
        cout << a[i] << ' ';
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