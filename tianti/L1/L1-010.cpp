#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int a[3];
    for (int i = 0; i < 3;i++)
        cin >> a[i];
    sort(a, a + 3);
    for (int i = 0; i < 3;i++){
        if(!i)
            cout << a[i];
        else
            cout << "->" << a[i];
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