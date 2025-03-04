#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> v;
void solve(){
    int n, m, x, k;
    cin >> n >> m;
    for (int i = 1; i <= n * m;i++){
        cin >> x;
        v.push_back(x);
    }
    cin >> k;
    while(k--){
        v.insert(v.begin(), v[n * m - 1]);
        v.pop_back();
    }
    for (int i = 0; i < v.size() / m;i++)
        for (int j = m * i; j < m * i + m;j++)
            cout << v[j] << " \n"[j == m * i + m - 1];
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