#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int m, n, a[N], mn[N][50], Lg[N], ans;
int gcd(int a, int b)
{
    return !b ? a : gcd(b, a % b);
}

int read(){
    int ret = 0;
    char ch = getchar();
    while(ch<'0'||ch>'9')
        ch = getchar();
    while(ch>='0'&&ch<='9'){
        ret = ret * 10 + ch - '0';
        ch = getchar();
    }
    return ret;
}

void write(int x){
    if(x>=10)
        write(x / 10);
    putchar(x % 10 + '0');
}

void pre()
{
    Lg[1] = 0;
    for (int i = 2; i <= n; i++)
        Lg[i] = Lg[i >> 1] + 1;
}
void ST_create()
{
    for (int i = 1; i <= n; i++)
        mn[i][0] = a[i];
    for (int j = 1; j <= Lg[n]; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            mn[i][j] = gcd(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
}
int ST_query(int l, int r)
{
    int k = Lg[r - l + 1];
    return gcd(mn[l][k], mn[r - (1 << k) + 1][k]);
}
void solve()
{
    // ST表  区间最大公因数
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    pre();
    ST_create();
    while (m--)
    {
        int a1, a2;
        a1 = read(), a2 = read();
        ans = ST_query(a1, a2);
        write(ans);
        putchar('\n');
    }
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