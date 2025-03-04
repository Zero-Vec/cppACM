#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int s, n, k;
    std::cin >> s >> n >> k;

    if (k == 0)
    {
        if (s < n)
        {
            std::cout << "NO" << '\n';
        }
        else
        {
            std::cout << "YES" << '\n';
            for (int i = 1; i < n; i++)
            {
                std::cout << 1 << ' ';
            }
            std::cout << s - (n - 1) << '\n';
        }
        return;
    }
    if (k == 1 && s == 1)
    {
        std::cout << "NO" << '\n';
        return;
    }
    if (k >= n)
    {
        if (k == n && s == (k - 1) * k / 2)
        {
            std::cout << "YES" << '\n';
            for (int i = 0; i < n; i++)
            {
                std::cout << i << ' ';
            }
            std::cout << '\n';
            return;
        }
        std::cout << "NO" << '\n';
        return;
    }

    int res = s - (k - 1) * k / 2;
    // std::cout << res << '\n';
    if (res < 0)
    {
        std::cout << "NO" << '\n';
        return;
    }

    else
    {
        if (res == k)
        {
            if (n - k > 1)
            {
                std::cout << "YES" << '\n';
                for (int i = 0; i < k; i++)
                {
                    std::cout << i << ' ';
                }
                std::cout << k - 1 << ' ' << 1 << ' ';
                for (int i = k + 3; i <= n; i++)
                {
                    std::cout << 0 << ' ';
                }
                std::cout << '\n';
            }
            else
            {
                std::cout << "NO" << '\n';
            }
        }
        else
        {
            std::cout << "YES" << '\n';
            for (int i = 0; i < k; i++)
            {
                std::cout << i << ' ';
            }
            std::cout << res << ' ';
            for (int i = k + 2; i <= n; i++)
            {
                std::cout << 0 << ' ';
            }
            std::cout << '\n';
        }
    }
}

signed main()
{
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    i64 t = 1;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
}
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll s, n, k;
void solve(){
    cin>>s>>n>>k;
    ll tmp = s - (k - 1) * k / 2;
    if(n<k){
        cout << "NO\n";
        return;
    }
    if(n == k && tmp != 0){
        cout << "NO\n";
        return;
    }
    if(k == 0){
        ll t = s - n + 1;
        if(t <= 0){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            for (int i = 1;i<n;i++)
                cout << 1 << " ";
            cout << t << '\n';
        }
        return;
    }
    if(k * (k - 1) > s * 2){
        cout << "NO\n";
    }
    else{
        cout << "YES\n";
        for (int i = 0; i < k;i++)
            cout<<i<<" ";
        if(n > k){
            cout << tmp << " ";
            for (int i = 0; i < n - k - 1;i++)
                cout << 0 << " ";
        }
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
*/