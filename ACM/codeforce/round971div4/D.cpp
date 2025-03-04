#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
void solve(){
    vector<int> v0, v1;
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int x, y;
        cin >> x >> y;
        if(y == 0)
            v0.push_back(x);
        else
            v1.push_back(x);
    }
    sort(v0.begin(),v0.end());
    sort(v1.begin(), v1.end());
    ll l0 = v0.size(), l1 = v1.size();
    ll ans = 0;
    for(auto i:v0){
        if(binary_search(v1.begin(),v1.end(), i))
            ans += l1 - 1;
        if (binary_search(v1.begin(), v1.end(), i - 1) && binary_search(v1.begin(), v1.end(), i + 1))
            ans++;
    }
    for (auto i : v1){
        if (binary_search(v0.begin(), v0.end(), i))
            ans += l0 - 1;
        if (binary_search(v0.begin(), v0.end(), i - 1) && binary_search(v0.begin(), v0.end(), i + 1))
            ans++;
    }
    cout << ans << '\n';
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