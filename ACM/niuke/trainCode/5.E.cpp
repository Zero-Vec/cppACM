#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    if(n%2==0){
        cout << "YES" << '\n';
        return;
    }
    if(a[n-1]>a[n]){
        cout << "NO" << '\n';
        return;
    }
    ll add = (a[n] - a[n - 1]) / (n - 1); // 相邻缩小差的次数
    for (int i = n - 1; i >= 1;i--){
        if (a[i + 1] + add < a[i]){
            cout << "NO"<< "\n";
            return;
        }
        if (i % 2 == 0&&i!=n-1){
            add += (a[i + 1] - a[i] + add) / i;
        }
    }
    cout << "YES" << '\n';
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