#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    queue<int> qu;
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = q; i <= n;i++)
        qu.push(i);
    for (int i = 1; i < q;i++)
        qu.push(i);
    int cnt = 0;
    while(qu.size() > 1){
        cnt++;
        int x = qu.front();
        qu.pop();
        if(cnt == m){
            cnt = 0;
            continue;
        }
        qu.push(x);
    }
    cout << qu.front() << '\n';
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