#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(queue<int> order){
    stack<int> s;
    int n = order.size();
    for (int i = 1; i <= n;i++){
        s.push(i);
        while(!s.empty() && s.top() == order.front())
            s.pop(), order.pop();
    }
    if(s.size())
        return false;
    return true;
}
void solve(){
    int n;
    queue<int> order;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        order.push(x);
    }
    cout << (check(order) ? "YES\n" : "NO\n");
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