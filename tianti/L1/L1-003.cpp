#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[10];
void solve(){
    string s;
    cin >> s;
    for (int i = 0; i < s.size();i++){
        int j = s[i] - '0';
        cnt[j]++;
    }
    for (int i = 0; i < 10;i++){
        if (cnt[i])
            cout << i << ":" << cnt[i] << "\n";
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