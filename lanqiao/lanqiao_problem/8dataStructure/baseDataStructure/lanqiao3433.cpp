#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
priority_queue<int> pq;
void solve(){
    int n, q;
    cin >> n >> q;
    ll sum = 0;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        sum += x;
        pq.push(x);
    }
    for (int i = 1; i <= q;i++){
        int mod;
        cin >> mod;
        while(pq.size()&&pq.top()>=mod){
            int y = pq.top();
            pq.pop();
            sum = sum - y + y % mod;
            pq.push(y % mod);
        }
        cout << sum << ' ';
    }
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