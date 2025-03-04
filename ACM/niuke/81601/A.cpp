#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 4e5 + 10;
int n, T;
long long num0[N], num1[N];
double fb[N];
int e[N], h[N], ne[N], idx, w[N];
int st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    ne[idx] = h[a], h[a] = idx, w[idx++] = c;
}

void DP1(int x, int father, int high)
{
    double minn = 0x3f3f3f3f;
    double maxx = -1;
    for (int i = h[x]; ~i; i = ne[i])
    {
        int y = e[i];
        if (y == father)
            continue;

        num0[y] = num0[x];
        num1[y] = num1[x];
        if (w[i] == 0)
            num0[y]++;
        else if (w[i] == 1)
            num1[y]++;

        fb[y] = (double)num0[y] / (num0[y] + num1[y]);
        fb[y] = max(fb[x], fb[y]);

        DP1(y, x, high + 1);

        if (high % 2 == 1) // 格林美选0最小的
        {
            minn = min(minn, fb[y]);
        }
        else
        {
            maxx = max(maxx, fb[y]);
        }
    }
    if (high % 2 == 1 && minn != 0x3f3f3f3f)
        fb[x] = max(fb[x], minn);
    else if (maxx != -1)
        fb[x] = max(fb[x], maxx);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        // memset(num0, 0, sizeof num0);
        // memset(num1, 0, sizeof num1);
        // memset(h, -1, sizeof h);
        // memset(st, 0, sizeof st);
        idx = 0;
        fb[1] = -1;
        cin >> n;
        for (int i = 1; i <= n;i++)
            num0[i] = num1[i] = st[i] = 0, h[i] = -1;
        int a, b, c;
        for (int i = 1; i < n; i++)
        {
            cin >> a >> b >> c;
            add(a, b, c), add(b, a, c);
        }

        DP1(1, -1, 1);

        double ans = -1;
        for (int i = h[1]; ~i; i = ne[i])
        {
            int y = e[i];
            ans = max(ans, 1.0 - fb[y]);
        }
        cout << fixed << setprecision(12) << ans << '\n';
    }
    return 0;
}