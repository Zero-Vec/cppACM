#include<bits/stdc++.h>
using namespace std;
using ll = long long;
//合并果子
void solve(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin>>n;
    int x;
    for (int i = 1; i <= n;i++){
        cin >> x;
        pq.push(x);
    }
    ll ans = 0;
    while(pq.size()>=2){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    cout<<ans<<"\n";
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