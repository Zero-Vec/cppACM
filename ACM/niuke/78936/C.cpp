#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int N = 2e6 + 10;
const int INF = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> PII;
ll a, b, c, d;

void sol()
{
    cin >> a >> b >> c >> d;
    // 自己写
    ll ans = max(a + b, d + c);
    // a ,d
    ans = min(ans, max(max(a, d) + c / 2, max(a, d) + b / 2));
    // b c
    ans = min(ans, max(max(b, c) + a / 2, max(b, c) + d / 2));
    // a,b
    ans = min(ans, a + max(c / 2, b) + d / 2);
    ans = min(ans, b + max(d / 2, a) + c / 2);
    // c d
    ans = min(ans, c + max(a / 2, d) + b / 2);
    ans = min(ans, d + max(b / 2, c) + a / 2);

    ans = min(ans, max(a + b, max(a, d) + c / 2));
    ans = min(ans, max(a + b, max(c, b) + d / 2));
    ans = min(ans, max(c + d, max(b, c) + a / 2));
    ans = min(ans, max(c + d, max(a, d) + b / 2));
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        sol();
    return 0;
}