#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int y, n;
    cin >> y >> n;
    int cnt = 0;
    for (int i = y; i <= 6000;i++){
        int wei = 0;
        int t = i;
        set<int> s;
        while(t){
            s.insert(t % 10);
            t /= 10;
            wei++;
        }
        if(wei<4)
            s.insert(0);
        if(s.size()==n){
            cout << cnt << ' ';
            for (int j = 1; j <= 4 - wei;j++)
                cout << 0;
            cout << i;
            return;
        }
        cnt++;
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