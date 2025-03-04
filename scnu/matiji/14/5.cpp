#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int n, pre[N], m, a, b;
int root(int x){
    return pre[x] = (pre[x] == x ? x : root(pre[x]));
}
void merge(int i, int j){
    int x = root(i), y = root(j);
    if (x != y)
        pre[x] = y;
}
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= 2 * n;i++)
        pre[i] = i;
    char ch;
    while(m--){
        cin >> ch >> a >> b;
        if (ch == 'D')
            merge(a + n, b), merge(a, b + n);
        else if(ch == 'S')
            merge(a, b), merge(a + n, b + n);
    }
    set<int> s;
    for (int i = 1; i <= n;i++){
        if(root(i) == root(i+n)){
            cout << 0 << '\n';
            return;
        }
    }
    for (int i = 1; i <= 2 * n;i++){
        s.insert(pre[i]);
    }
    cout << 1;
    for (int i = 0; i < s.size() / 2;i++)
        cout << 0;
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