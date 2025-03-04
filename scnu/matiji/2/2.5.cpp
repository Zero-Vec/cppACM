#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n, c, a[N];
stack<int>st;
vector<int> v;
void solve(){
    cin >> n >> c;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int cnt = 1;
    while(true){
        if(cnt>n){
            while(st.size())
                v.push_back(st.top()), st.pop();
            break;
        }
        int limit = c - st.size(), id, temp = 0x3f3f3f3f;
        limit = min(limit, n - cnt + 1);
        for (int i = cnt; i < cnt + limit;i++)
            if(a[i]<temp)
                id = i, temp = a[i];
        if(!st.size()||temp<st.top()){
            for (int i = cnt; i < id;i++)
                st.push(a[i]), cnt++;
            v.push_back(a[id]);
            cnt++;
        }
        else
            v.push_back(st.top()), st.pop();
    }
    for(auto i:v)
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