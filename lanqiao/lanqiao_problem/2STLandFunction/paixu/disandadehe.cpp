#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[110];
void solve(){
    int n;
    cin>>n;
    for (int i = 1; i <= n;i++)cin>>a[i];
    vector<int>v;
    for (int i = 1; i <= n - 2;i++){
        for (int j = i + 1; j <= n - 1;j++){
            for (int k = j + 1; k <= n;k++){
                v.push_back(a[i] + a[j] + a[k]);
            }
        }
    }
    auto last = unique(v.begin(), v.end());
    v.erase(last, v.end());
    sort(v.begin(),v.end());
    cout << v[v.size()-3];
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