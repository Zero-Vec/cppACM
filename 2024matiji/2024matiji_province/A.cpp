#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n;
void solve(){
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    a.erase(it, a.end());
    cout << a[1];
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