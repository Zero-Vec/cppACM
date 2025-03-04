#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1010;
int dp[N];
int mex(set<int> st){
    for (int i = 0;; i++)
        if(st.find(i) == st.end())
            return i;
}
int sg(int x){
    if(dp[x]!=-1)
        return dp[x];
    set<int> st;
    for (int i = 1; i <= x;i<<=1)
        st.insert(sg(x - i));
    return dp[x] = mex(st);
}
void solve(){
    memset(dp, -1, sizeof dp);
    int n;
    /*
    while(cin>>n)
        cout << (sg(n) ? "Kiki" : "Cici") << '\n';
    */
    cin >> n;
    for (int i = 0; i <= n;i++)
        cout << setw(2) << i << ' ';
    cout << '\n';
    for (int i = 0; i <= n;i++)
        cout << setw(2) << sg(i) << " ";
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