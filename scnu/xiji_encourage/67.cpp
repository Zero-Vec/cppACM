#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    vector<int> ans;
    int now = 2;
    while(n != 1){
        int cnt = 0;
        while(n % now == 0){
            n /= now;
            cnt++;
        }
        if(cnt > 1)
            ans.push_back(now);
        now++;
    }
    for(auto i:ans)
        cout << i << ' ';
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