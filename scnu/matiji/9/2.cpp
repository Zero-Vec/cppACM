#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 7;
const int inf = 0x3f3f3f3f;
deque<int> q;
int ans = inf;
int n, m, a[N], cnt[N], l, r, type;
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(!cnt[a[i]])
            type++;
        cnt[a[i]]++;
        q.push_front(i);
        while(q.size()&&cnt[a[q.back()]]>1)
            cnt[a[q.back()]]--, q.pop_back();
        if(type==m)
            if(q.size()<ans)
                ans = q.size(), r = q.front(), l = q.back();
    }
    cout << l << " " << r;
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