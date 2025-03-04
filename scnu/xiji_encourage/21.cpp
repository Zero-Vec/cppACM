#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
bool check(const string &str) {
    int l = 0, r = str.size() - 1;
    if (str.size() == 1) return false;
    while (l < r) {
        if (str[l] != str[r]) return false;
        l++;
        r--;
    }
    return true;
}

void solve() {
    cin >> s;
    int mx = 0;
    string ans = "";
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            string subStr = s.substr(i, j - i + 1);
            if (check(subStr) && subStr.size() > mx) {
                mx = subStr.size();
                ans = subStr;
            }
        }
    }
    
    if (mx == 0) {
        cout << 0 << '\n';
    } else {
        cout << mx << '\n';
        cout << ans << '\n';
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