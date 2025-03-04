#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9;
int n, m, s[N], ans = -2e8;
void solve(){
    cin >> n >> m;
    for (int i = 1;i<=n;i++){
        cin >> s[i];
        s[i] += s[i - 1];
    }
    deque<int> q;
    q.push_back(0);
    for (int i = 1; i <= n;i++){
        if(q.size() && q.front() < i - m)
            q.pop_front();
        ans = max(ans, s[i] - s[q.front()]);
        while(q.size() && s[q.back()] >= s[i])
            q.pop_back();
        q.push_back(i);
    }
    cout << ans << '\n';
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