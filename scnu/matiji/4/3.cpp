#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a, m;
void solve(){
    cin >> a >> m;
    for (int i = 1; i <= 1e5;i++){
        a += a % m;
        if(a%m==0){
            cout << "Yes";
            return;
        }
    }
    cout << "No";
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