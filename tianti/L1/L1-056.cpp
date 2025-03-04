#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
string s[N];
int a[N];
int n;
void solve(){
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n;i++){
        cin >> s[i] >> a[i];
        sum += a[i];
    }
    n *= 2;
    double avg = 1.0 * sum / n;
    string ans;
    int mn = 1000;
    for (int i = 1; i <= n;i++){
        if(abs(avg-a[i])<mn){
            mn = abs(avg - a[i]);
            ans = s[i];
        }
    }
    cout << int(avg) << " " << ans;
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