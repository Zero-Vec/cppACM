#include<bits/stdc++.h>
using namespace std;
using ll = long long;
char ch[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
void solve(){
    for (int i = 2023;;i++){
        string ans;
        int t = i;
        while(t){
            ans+=ch[t%16];
            t /= 16;
        }
        reverse(ans.begin(), ans.end());
        bool tag=1;
        for (int j = 0; j < ans.size();j++){
            if('0'<=ans[j]&&ans[j]<='9')tag=0;
        }
        if(tag){
            //cout << ans << '\n';
            cout<<i;
            return;
        }
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