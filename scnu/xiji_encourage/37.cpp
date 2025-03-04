#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<vector<int>> v;
string s;
void solve(){
    while (getline(cin, s)){
        vector<int> nums;
        stringstream ss(s);
        int num;
        while (ss >> num)
            nums.push_back(num);
        v.push_back(nums);
    }
    int n = v.size();
    for (int i = 0; i < n / 2; i++){
        vector<int> ans;
        for (auto j : v[2 * i])
            ans.push_back(j);
        for (auto j : v[2 * i + 1])
            ans.push_back(j);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        for (auto j : ans)
            cout << j << ' ';
        cout << '\n';
    }
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