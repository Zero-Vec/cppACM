#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 50;
int a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    if (n == 2){
        if(a[1]+1==a[2]){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
    else{
        cout << "NO\n";
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