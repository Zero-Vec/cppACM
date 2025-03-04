#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int y1, y2, m;
    cin >> y1 >> m;
    vector<int> v;
    while(m--){
        int y;
        cin>>y;
        v.push_back(y);
    }
    cin >> y2;
    int cnt = 0;
    for(auto i:v){
        if(i>=y1&&i<=y2)
            cnt++;
    }
    cout << y2 - y1 + 1 - cnt << '\n';
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