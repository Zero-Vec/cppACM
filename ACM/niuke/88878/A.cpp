#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a, b, c;
void solve(){
    cin >> a >> b >> c;
    vector<ll> v;
    v.push_back(a), v.push_back(b), v.push_back(c);
    for (int i = 0; i < 3;i++){
        vector<ll> t = v;
        t[i] *= 2;
        sort(t.begin(), t.end());
        if(t[1] + t[0] > t[2]){
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
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