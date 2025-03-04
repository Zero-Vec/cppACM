#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int getsum(int x){
    int ans = 0;
    while(x){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
void solve(){
    int n;
    cin >> n;
    cout << getsum(n) << '\n';
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