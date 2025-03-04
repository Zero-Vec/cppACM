#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool judge(int x)
{
    int c = 0;
    while (x)
    {
        c++, x /= 10;
    }
    return c == 4;
}
void solve()
{
    int x;
    cin >> x;
    if (!judge(x))
    {
        cout << "Error!\n";
        return;
    }
    vector<char> v;
    while (x)
    {
        char t = 'A' + (x % 10 - 1 + 13);
        x /= 10;
        v.push_back(t);
    }
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i];
    cout << '\n';
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