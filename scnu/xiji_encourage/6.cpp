#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    set<int> s;
    int n, m;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    cin >> m;
    for (int i = 1; i <= m;i++){
        int x;
        cin >> x;
        if(s.count(x))
            s.erase(x);
        else
            s.insert(x);
    }
    for(auto x:s){
        cout << x << " ";
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