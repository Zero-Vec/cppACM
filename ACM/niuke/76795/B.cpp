#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 9;
ll a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll sum = 0;
    for (int i = 1; i <= n;i++){
        a[i] += sum;
        if(a[i]<0)
            sum += a[i];
        else if(i!=n)
            a[n] += a[i];
    }
    cout << a[n] << '\n';
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