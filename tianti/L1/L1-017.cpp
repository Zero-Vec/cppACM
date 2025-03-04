#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
void solve(){
    cin >> s;
    double ans = 0;
    bool tag = 0;//判断奇偶
    int cnt = 0;
    for (int i = 0; i < s.size();i++){
        if('0'<=s[i]&&s[i]<='9'){
            if(s[i]=='2')cnt++;
        }
        if(i==s.size()-1){
            int x = s[i] - '0';
            if(x%2==0)tag=1;
        }
    }
    double k1 = cnt / (s.size() - 1);
    if (s[0] == '-'){
        double k1 = cnt / (s.size() - 1);
        if(tag){
            ans = (double(cnt) / (s.size() - 1) * 1.5 * 2) * 100;
        }
        else{
            ans = (double(cnt) / (s.size() - 1) * 1.5) * 100;
        }
    }
    else{
        if (tag){
            ans = (double(cnt) / (s.size()) * 2) * 100;
        }
        else{
            ans = (double(cnt) / (s.size())) * 100;
        }
    }
    cout << fixed << setprecision(2) << ans << "%";
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