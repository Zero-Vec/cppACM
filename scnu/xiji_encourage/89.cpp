#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int cube = n * n * n, start = 1, sum = 0, cnt = 0;
    while (sum != cube)
    {
        sum = 0;
        cnt = 0;
        for (int i = start; sum < cube; i += 2)
        {
            sum += i;
            cnt++;
        }
        if (sum != cube)
        {
            start += 2;
        }
    }
    cout << start << " " << cnt << '\n';
    return 0;
}