#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i < 8;i++){
        for (int j = i + 1; j < 9;j++){
            int a = i * 10 + j, b = j * 10 + i;
            if(a * b == n){
                cout << i << j << '\n';
                return;
            }
        }
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