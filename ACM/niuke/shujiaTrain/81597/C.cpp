#include <cstdio>
#include <string.h>
#include <algorithm>
#include <iostream>
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;

int n = 2, m;
char g[4][N];
int f[N][4];

int res = 0;

void DP()
{
    for (int i = 1; i <= m; i++)
    {
        if (g[1][i] == 'R' && g[2][i] == 'R')
        {
            f[i][1] = max(f[i - 1][1] + 1, f[i - 1][2] + 2);
            f[i][2] = max(f[i - 1][2] + 1, f[i - 1][1] + 2);
        }
        else if (g[1][i] == 'W' && g[2][i] == 'R')
        {
            f[i][2] = f[i - 1][2] + 1;
        }
        else if (g[1][i] == 'R' && g[2][i] == 'W')
        {
            f[i][1] = f[i - 1][1] + 1;
        }
    }
}

int main()
{
    cin >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    g[1][0] = g[2][0] = 'W';

    DP();

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            res = max(f[i][j], res);

    if (res != 0)
        cout << res - 1 << endl;
    else
        cout << res << endl;
    return 0;
}