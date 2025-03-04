#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n;
void solve(){
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        mp[x] = i;
    }
    for(auto [x,y]:mp){
        cout << y << " ";
    }
    cout << '\n';
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