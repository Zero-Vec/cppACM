#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s;
    cin >> s;
    int len = s.size();
    for (int j = 0; j < s.size();j++){
        int t = s[j] - '0';
        for (int i = j + 1; i < s.size();i++){
            int k = s[i] - '0';
            if(t < k){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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