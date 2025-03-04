#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
map<int, char> mp;
void solve(){
    int n;
    cin >> n;
    vector<string> v;
    string s;
    mp[0] = '1', mp[1] = '0', mp[2] = 'X', mp[3] = '9', mp[4] = '8', mp[5] = '7',
    mp[6] = '6', mp[7] = '5', mp[8] = '4', mp[9] = '3', mp[10] = '2';
    for (int i = 1; i <= n;i++){
        cin >> s;
        bool tag = 1;
        int cnt = 0;
        for (int j = 0; j < 17;j++){
            if(s[j]<='9'&&s[j]>='0'){
                cnt += (s[j] - '0') * a[j];
            }
            else{
                tag = 0;
                break;
            }
        }
        if(mp[cnt%11]!=s[17])
            tag = 0;
        if(!tag)
            v.push_back(s);
    }
    if(v.size()){
        for(auto i:v){
            cout << i << '\n';
        }
    }
    else
        cout << "All passed";
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