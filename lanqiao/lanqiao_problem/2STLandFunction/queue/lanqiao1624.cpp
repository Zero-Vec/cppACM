//小蓝吃糖果
/*
小蓝有n种糖果，每种数量已知。小蓝不喜欢连续2次吃同样的糖果。问有没有可行吃糖方案
输入：第一行是整数n（0<n<1000000）第二行包含n个数，表示n种糖果的数量mi，0<mi<1000000
输出一行，包含一个Yes或No
样例：输入:
3
4 1 1
输出：
No
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int n;
void solve()
{
    cin >> n;
    ll sum = 0, mx = -1;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }
    cout << (sum >= 2 * mx - 1 ? "Yes" : "No") << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    priority_queue<int> pq;
    int n;
    cin >> n;
    int x;
    for (int i = 1; i <= n;i++){
        cin >> x;
        pq.push(x);
    }
    while(pq.size()>1){
        int a = pq.top();
        pq.pop();
        a--;
        int b = pq.top();
        pq.pop();
        b--;
        if (a >= 1)
            pq.push(a);
        if(b>=1)
            pq.push(b);
    }
    if(!pq.size()||pq.top()==1)
        cout << "Yes";
    else
        cout << "No";
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
*/