#include <bits/stdc++.h>
using namespace std;
#define maxn 1005
int n, m;
string mp[maxn];
bool visDir[maxn][maxn][4];
int vis[maxn][maxn];

void walk(int &x, int &y, int curDir)
{
    // walk
    switch (curDir)
    {
    case 0:
        x--;
        break;
    case 1:
        x++;
        break;
    case 2:
        y--;
        break;
    case 3:
        y++;
        break;
    default:
        break;
    }
}
void chDir(int x, int y, int &curDir, int &count)
{
    if (mp[x][y] == '|')
    {
        if (curDir == 2)
            curDir = 3;
        else if (curDir == 3)
            curDir = 2;
    }
    else if (mp[x][y] == '-')
    {
        if (curDir == 0)
            curDir = 1;
        else if (curDir == 1)
            curDir = 0;
    }
    else if (mp[x][y] == '/')
    {
        if (curDir == 0)
        {
            curDir = 3;
        }
        else if (curDir == 1)
        {
            curDir = 2;
        }
        else if (curDir == 2)
        {
            curDir = 1;
        }
        else if (curDir == 3)
        {
            curDir = 0;
        }
    }
    else if (mp[x][y] == '\\')
    {
        if (curDir == 0)
        {
            curDir = 2;
        }
        else if (curDir == 1)
        {
            curDir = 3;
        }
        else if (curDir == 2)
        {
            curDir = 0;
        }
        else if (curDir == 3)
        {
            curDir = 1;
        }
    }
}
void solve(){
        cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> mp[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        string dir;
        cin >> x >> y >> dir;
        x--, y--;
        int count = 0;
        int curDir = 0; // 0: above, 1: below, 2: left, 3: right
        if (dir == "above")
            curDir = 0;
        else if (dir == "below")
            curDir = 1;
        else if (dir == "left")
            curDir = 2;
        else if (dir == "right")
            curDir = 3;

        // walk(x, y, curDir);
        // printf("(%d,%d)\n", x + 1, y + 1);

        walk(x, y, curDir);
        chDir(x, y, curDir, count);

        while (x >= 0 && x < n && y >= 0 && y < m)
        {
            if (visDir[x][y][curDir])
                break;
            visDir[x][y][curDir] = true;
            if (vis[x][y] == 0)
                count++;
            vis[x][y]++;

            walk(x, y, curDir);

            if (x < 0 || x >= n || y < 0 || y >= m)
                break;

            chDir(x, y, curDir, count);

            // printf("(%d,%d)\n", x + 1, y + 1);
        }
        cout << count << '\n';
        memset(vis, 0, sizeof(vis));
        memset(visDir, 0, sizeof(visDir));
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}