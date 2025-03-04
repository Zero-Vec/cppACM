#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    bool tag = 1;
    for (int i = 1; i <= n;i++){
        if(a[i]!=i){
            tag = 0;
            break;
        }
    }
    if(tag){
        cout << 1 << '\n';
        cout << 1 << ' ' << n + 1;
        return;
    }
    cout << 0;
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