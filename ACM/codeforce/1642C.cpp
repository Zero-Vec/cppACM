// https://codeforces.com/problemset/problem/1642/C
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
void solve(){
    int n, x;
    cin >> n >> x;
    multiset<ll> st;
    for (int i = 1; i <= n;i++){
        ll y;
        cin >> y;
        st.insert(y);
    }
    int ans = 0;
    while(st.size()){
        ll t = *st.begin();
        st.erase(st.begin());
        t = t * x;
        if(st.size()){
            auto it = st.find(t);
            if(it!=st.end()){
                st.erase(it);
            }
            else{
                ans++;
            }
        }
        else{
            ans++;
        }
    }
    cout << ans << '\n';
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