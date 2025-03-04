#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, ans=1, row=1, w = 1;
void solve(){
    char a;
    cin >> n >> a;
    while(ans<n){
        row++;
        w += 2;
        ans += 2 * w;
    }
    if(ans>n){
        row--;
        ans -= 2 * w;
    }
    for (int i = row; i >= 1;i--){
        for (int j = 1; j <= row - i;j++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1;j++)
            cout << a;
        cout << "\n";
    }
    for (int i = 2; i <= row;i++){
        for (int j = 1; j <= row - i;j++)
            cout << " ";
        for (int j = 1; j <= 2 * i - 1;j++)
            cout << a;
        cout << "\n";
    }
    cout << n - ans;
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