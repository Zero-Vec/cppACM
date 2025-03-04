#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, te[N];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> te[i];
    }
    cin >> m;
    while (m--)
    {
        int a, b, x, op;
        cin >> op;
        if (op == 1)
        {
            cin >> x;
            int ans = te[x];
            double p = sqrt(te[x]);
            int l = max(1, x - (int)ceil(p));
            int r = min(n, x + (int)ceil(p));
            for (int i = l; i <= r; i++)
            {
                ans = min(ans, (x - i) * (x - i) + te[i]);
            }
            cout << ans << '\n';
        }
        else if (op == 0)
        {
            cin >> a >> b;
            if (te[a] > b)
                te[a] = b;
        }
    }
    return 0;
}

/*
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int B[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> B[i];
    }

    int m;
    cin >> m;
    while (m--)
    {
        bool opt;
        int a, b;
        cin >> opt;
        if (opt)
        {
            cin >> a;
            int Min = B[a];
            int diff = 1;
            int left = a - diff;
            int right = a + diff;
            while ((left > 0 || right <= n) && diff * diff < Min)
            {
                if (left > 0)
                {
                    int leftB = B[left];
                    if (leftB + diff * diff < Min)
                    {
                        Min = leftB + diff * diff;
                    }
                }
                if (right <= n)
                {
                    int rightB = B[right];
                    if (rightB + diff * diff < Min)
                    {
                        Min = rightB + diff * diff;
                    }
                }
                diff++;
                left = a - diff;
                right = a + diff;
            }
            cout << Min << '\n';
        }
        else
        {
            cin >> a >> b;
            if (B[a] > b)
            {
                B[a] = b;
            }
        }
    }
    return 0;
}
*/