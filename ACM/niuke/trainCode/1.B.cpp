#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin >> n;
    set<pair<int, int>> s;
    int ans1 = 2, ans2 = 2;
    for (int i = 1; i <= n;i++){
        int r, c;
        cin >> r >> c;
        s.insert({r, c});
        if(c>=0)
            ans2 = 1;
        if(c<=0)
            ans1 = 1;
    }
    for(auto [r,c]:s){
        for (int i = -1; i <= 1; i++){
            if(s.count({r^3,c+i})){
                if(c<0)
                    ans1 = 0;
                if(c>0)
                    ans2 = 0;
                if(c==0&&c+i<0)
                    ans1 = 0;
                if(c==0&&c+i>0)
                    ans2 = 0;
            }
        }
    }
    int ans = 3 - s.count({2, 0}) - s.count({1, 1}) - s.count({1, -1});
    ans = min(ans, ans1 + ans2);
    cout << ans << "\n";
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