#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N][N];
int posx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int posy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int main()
{
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            if(a[i][j]==1)
                cout << "9 ";
            else
            {
                int ans = 0;
                for (int k = 0; k < 8;k++)
                {
                    if(!a[i+posx[k]][j+posy[k]])
                        continue;
                    else
                        ans++;
                }
                cout << ans << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}