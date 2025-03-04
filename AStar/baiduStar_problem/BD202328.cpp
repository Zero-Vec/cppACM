#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
int n, a[N];
bool v[N];
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    vector<int> ans;
    for (int i = 1; i <= n;i++){
        memset(v, 0, sizeof v);
        v[i] = 1;
        int nxt = a[i];
        bool tag = 0;
        while(!v[nxt]){
            if(!nxt){
                tag = 1;
                break;
            }
            v[nxt] = 1;
            nxt = a[nxt];
        }
        if(tag)
            ans.push_back(i);
    }
    ll res = 0;
    for(auto i:ans)
        res = res ^ i;
    cout << res << '\n';
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