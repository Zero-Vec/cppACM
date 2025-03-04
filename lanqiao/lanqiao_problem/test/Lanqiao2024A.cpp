#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<int, int> mp;
void solve()
{
    mp[0] = 13, mp[1] = 1, mp[2] = 2, mp[3] = 3, mp[4] = 5;
    mp[5] = 4, mp[6] = 4, mp[7] = 2, mp[8] = 2, mp[9] = 2;
    ll ans = 0;
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int riqi[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 2000; i <= 2023; i++)
    {
        int t = i;
        for (int j = 1; j <= 4; j++)
        {
            riqi[j] = t % 10;
            t /= 10;
        }
        for (int j = 1; j <= 12; j++)
        {
            riqi[5] = j / 10;
            riqi[6] = j % 10;
            for (int z = 1; z <= days[j]; z++)
            {
                riqi[7] = z / 10;
                riqi[8] = z % 10;
                int cnt = 0;
                for (int m = 1; m <= 8; m++)
                    cnt += mp[riqi[m]];
                if (cnt > 50)
                    ans++;
            }
        }
    }
    // cout << ans;
    riqi[1] = 2, riqi[2] = 0, riqi[3] = 2, riqi[4] = 4;
    for (int j = 1; j <= 4; j++)
    {
        riqi[5] = j / 10;
        riqi[6] = j % 10;
        if (j != 4)
        {
            for (int z = 1; z <= days[j]; z++)
            {
                riqi[7] = z / 10;
                riqi[8] = z % 10;
                int cnt = 0;
                for (int m = 1; m <= 8; m++)
                    cnt += mp[riqi[m]];
                if (cnt > 50)
                    ans++;
            }
        }
        else
        {
            for (int z = 1; z <= 13; z++)
            {
                riqi[7] = z / 10;
                riqi[8] = z % 10;
                int cnt = 0;
                for (int m = 1; m <= 8; m++)
                    cnt += mp[riqi[m]];
                if (cnt > 50)
                    ans++;
            }
        }
    }
    // cout << ans;
    cout << ans + 2;
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