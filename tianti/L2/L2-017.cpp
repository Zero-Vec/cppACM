#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=1e5+9;
int a[N];
int n;
void solve(){
    cin>>n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int d = 0, n1 = 0, N1 = 0, N2 = 0;
    n1 = n / 2;
    for (int i = n1 + 1; i <= n;i++)
        N2 += a[i];
    for (int i = 1; i <= n1;i++)
        N1 += a[i];
    d = max(d, N2 - N1);
    cout << "Outgoing #: " << n - n1 << '\n';
    cout << "Introverted #: " << n1 << '\n';
    cout << "Diff = " << d;
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