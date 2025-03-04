#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    for (int i = 2; i <= n / i;i++){
        while(n % i == 0){
            n /= i;
            cout << i << " ";
        }
    }
    if(n > 1)
        cout << n;
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