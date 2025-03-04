#include <bits/stdc++.h>
//这题不会
using namespace std;
using LL = long long;

LL cal(const string &s, const string &t)
{
    int n = s.size() - 1;
    vector<int> ne(n + 1);
    for (int i = 2, j = 0; i <= n; i++)
    {
        while (j && t[j + 1] != t[i])
        {
            j = ne[j];
        }
        if (t[j + 1] == t[i])
        {
            j++;
        }
        ne[i] = j;
    }
    vector<LL> cnt(n + 1);
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && t[j + 1] != s[i])
        {
            j = ne[j];
        }
        if (t[j + 1] == s[i])
        {
            j++;
        }
        if (j)
        {
            cnt[j]++;
        }
        if (j == n)
        {
            j = ne[j];
        }
    }
    for (int i = n; i >= 1; i--)
    {
        cnt[ne[i]] += cnt[i];
    }
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += cnt[i];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    LL score1 = cal(s, t);
    LL score2 = cal(t, s);

    if (score1 > score2)
    {
        printf("Xiaoqiu\n");
    }
    else if (score1 == score2)
    {
        printf("Draw\n");
    }
    else
    {
        printf("Xiaoyu\n");
    }
}