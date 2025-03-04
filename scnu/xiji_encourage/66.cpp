#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    bool tag = false;
    // 枚举起点
    for (int i = 1; i < n;i++){
        for (int j = i; j < n;j++){
            int sum = (i + j) * (j - i + 1) / 2;
            if(sum == n){
                tag = true;
                for (int k = i; k <= j;k++)
                    cout << k << ' ';
                cout << '\n';
            }
        }
    }
    if(!tag)
        cout << "NONE\n";
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