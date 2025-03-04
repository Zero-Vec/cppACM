#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int z;
    cin >> z;
    if(z==2||z==1){
        cout << "NO";
    }
    else{
        cout << "YES\n";
        cout << 1 << " " << z - 1;
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