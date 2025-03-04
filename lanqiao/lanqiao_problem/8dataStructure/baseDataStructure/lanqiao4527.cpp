#include<bits/stdc++.h>
using namespace std;
using ll = long long;
priority_queue<int> pq;
int n, k, op, x, d;
void solve(){
    cin >> n >> k;
    pq.push(k);
    for (int i = 1; i <= n;i++){
        cin >> op;
        if(op==4){
            cout << pq.top() + d << '\n';
            pq.pop();
        }
        else {
            cin >> x;
            if(op==1){
                pq.push(x - d);
            }
            else if(op==2)
                d += x;
            else
                d -= x;
        }
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