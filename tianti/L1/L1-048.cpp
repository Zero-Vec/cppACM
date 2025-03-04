#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int a[N][N], b[N][N], ans[N][N];
void solve(){
    int na, ma, nb, mb;
    cin >> na >> ma;
    for (int i = 1; i <= na;i++)
        for (int j = 1; j <= ma;j++)
            cin >> a[i][j];
    cin >> nb >> mb;
    for (int i = 1; i <= nb;i++)
        for (int j = 1; j <= mb;j++)
            cin >> b[i][j];
    if(ma!=nb){
        cout << "Error: " << ma << " != " << nb;
        return;
    }
    for (int i = 1; i <= na;i++){
        for (int j = 1; j <= mb;j++){
            for (int z1 = 1; z1 <= ma;z1++)
                ans[i][j] += a[i][z1] * b[z1][j];
        }
    }
    cout << na << " " << mb << '\n';
    for (int i = 1; i <= na;i++){
        for (int j = 1; j <= mb;j++){
            if(j==1)
                cout << ans[i][j];
            else
                cout << " " << ans[i][j];
        }
        cout << '\n';
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