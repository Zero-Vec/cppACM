#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
const int N = 1e5 + 9;
int a[N];
void solve(){
    cin >> n;
    int m;
    cin >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    while(m--){
        next_permutation(a + 1, a + 1 + n);
    }
    for (int i = 1; i <= n; i++)
        cout<<a[i]<<" ";
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