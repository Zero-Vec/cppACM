#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int mp[3][N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= 2;i++){
        for (int j = 1; j <= n;j++){
            cin >> mp[i][j];
        }
    }
    if(n==1||(n==2&&mp[1][1]==mp[2][1])){
        cout << -1 << "\n";
    }
    else{
        bool tag = 0;
        for (int i = 1; i <= n ;i++){
            if(mp[1][i]==mp[2][i]&&i!=1&&i!=n)
                tag = 1;
        }
        for (int i = 1; i <= n - 1;i++){
            if(mp[1][i]==mp[2][i+1])
                tag = 1;
        }
        for (int i = 1; i <= n - 1;i++){
            if(mp[2][i]==mp[1][i+1])
                tag = 1;
        }
        cout << (tag ? 1 : 2) << "\n";
    }
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