#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9, inf = 2e9;
int n, D, ans = inf;
struct pos{
    int x, y;
    bool operator<(const pos &u)const{
        return x < u.x;
    }
} p[N];
//用双端队列模拟单调队列
deque<int> maxn, minn;
void solve(){
    cin >> n >> D;
    for (int i = 1; i <= n;i++)
        cin >> p[i].x >> p[i].y;
    sort(p + 1, p + 1 + n);
    int L = 1;
    for (int i = 1; i <= n;i++){
        while(maxn.size() && p[maxn.back()].y < p[i].y)
            maxn.pop_back();
        maxn.push_back(i);
        while(minn.size() && p[minn.back()].y > p[i].y)
            minn.pop_back();
        minn.push_back(i);
        while(L < i && p[maxn.front()].y - p[minn.front()].y >= D){
            ans = min(ans, p[i].x - p[L].x);
            L++;
            while(maxn.size() && maxn.front() < L)
                maxn.pop_front();
            while(minn.size() && minn.front() < L)
                minn.pop_front();
        }
    }
    cout << (ans == inf ? -1 : ans) << "\n";
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