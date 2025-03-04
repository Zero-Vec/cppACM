#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int a[5];
    for (int i = 0; i < 5;i++)
        cin >> a[i];
    for (int i = 0; i < 5;i++)
        if(a[i] == 1){
            cout << i + 1;
            return;
        }
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