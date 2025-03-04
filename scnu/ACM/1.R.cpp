#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int binary_search(const vector<long long> &prefix_sums, long long target)
{
    int left = 0, right = prefix_sums.size() - 1, ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (prefix_sums[mid] >= target)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> sweets(n);
        for (int &sugar : sweets)
        {
            cin >> sugar;
        }
        sort(sweets.begin(), sweets.end(), greater<int>());
        vector<long long> prefix_sums(n);
        prefix_sums[0] = sweets[0];
        for (int i = 1; i < n; i++)
        {
            prefix_sums[i] = prefix_sums[i - 1] + sweets[i];
        }
        for (int i = 0; i < q; i++)
        {
            long long xj;
            cin >> xj;
            int ans = binary_search(prefix_sums, xj);
            if (ans != -1)
            {
                cout << (ans + 1) << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}