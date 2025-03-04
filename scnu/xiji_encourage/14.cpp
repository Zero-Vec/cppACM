#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n, m;
    vector<int> ans;
    set<int> s;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    cin >> m;
    for (int i = 1; i <= m;i++){
        int x;
        cin >> x;
        if(s.count(x) && !count(ans.begin(), ans.end(), x))
            ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    if(!ans.size()){
        cout << "No Answer" << '\n';
    }
    for (int i = ans.size() - 1; i >= 0;i--)
        cout << ans[i] << " ";
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