#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define NODE pair<int,int>
const int N = 3600;
int n, a[N][N], f[N], ans;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        for (int j = 1; j <= n;j++)
            cin >> a[i][j];
    for (int i = 1; i <= n;i++){
        stack<NODE> st;//first存储列号，second存储它的和
        for (int j = 1; j <= n;j++){
            if(a[i][j])
                f[j] = i;
            while(!st.empty() && f[st.top().first]<f[j])
                st.pop();
            if(st.empty()){
                st.push({j, 0});
                st.top().second = (i - f[st.top().first]) * st.top().first;
            }
            else{
                NODE tmp = st.top();
                st.push({j, 0});
                st.top().second = tmp.second + (i - f[st.top().first]) * (st.top().first - tmp.first);
            }
            ans += st.top().second;
        }
    }
    cout << ans;
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