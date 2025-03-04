#include <bits/stdc++.h>
using namespace std;
int a[2020];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0, cnt = 0;
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j < i || (j < n && cnt < k))
        {
            if (a[++j] >= m)
                cnt++;
        }
        if (cnt >= k)
            ans += n - j + 1;
        cnt -= (a[i] >= m);
    }
    cout << ans;
    return 0;
}