#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

/*
构造方法很多吧，这里提供一种我的构造方法，如果k==0，输出 1 1 2 2 3 3 ... n n，如果k==1，输出1 1 2 3 4 ...n 2 3 4...n，
否则比如n == 6, k == 4，构造1 2 3 4 5 6 1 2 6 5 4 3，即前n个是一个排列，
后n个是一个排列，这样至少会有两个排列，如果再多的话，就在第n+1位再依次输出1 2 3...。
*/
void solve()
{
    int n, k;
    std::cin >> n >> k;
    if (n == 1)
    {
        if (k == 0)
        {
            std::cout << -1 << '\n';
        }
        if (k == 1)
        {
            std::cout << -1 << '\n';
        }
        if (k == 2)
        {
            std::cout << "1 1" << '\n';
        }
        return;
    }
    if (k == 0)
    {
        if (n == 2)
        {
            std::cout << -1 << '\n';
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            std::cout << i << ' ' << i << ' ';
        }
    }
    else if (k == 1)
    {
        std::cout << "1 1 ";
        for (int i = 2; i <= n; i++)
        {
            std::cout << i << ' ';
        }
        for (int i = 2; i <= n; i++)
        {
            std::cout << i << ' ';
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            std::cout << i << ' ';
        }
        for (int i = 1; i <= k - 2; i++)
        {
            std::cout << i << ' ';
        }
        for (int i = n; i >= k - 1; i--)
        {
            std::cout << i << ' ';
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    i64 t = 1;
    // std::cin >> t;
    while (t--)
    {
        solve();
    }
}