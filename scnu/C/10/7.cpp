#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5;
int ans[N];
set<int> b;
void solve(){
    int x;
    int i = 1;
    while(cin >> x && x != -1){
        ans[i++] = x;
    }
    while(cin >> x && x != -1){
        b.insert(x);
    }
    for (int j = 1; j < i;j++)
        if(!b.count(ans[j]))
            cout << ans[j] << " ";
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