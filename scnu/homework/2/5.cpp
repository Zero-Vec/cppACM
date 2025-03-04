#include<bits/stdc++.h>
using namespace std;
// 数一数顺序对一共多少个
int countDui(vector<int> li)
{
    int count = 0;
    for (int i = 0; i < li.size(); i++)
    {
        for (int j = i + 1; j < li.size(); j++)
        {
            if (li[i] < li[j])
                count++;
        }
    }
    return count;
}
int main()
{
    int sum = 0; // 记录多少种可能性
    int n, k;
    cin >> n >> k;
    int tt;
    vector<int> a;
    vector<int> t;
    for (int i = 0; i < n; i++)
    {
        cin >> tt;
        a.push_back(tt);
    }
    for (int i = 1; i <= n; i++)
    {
        if (find(a.begin(), a.end(), i) == a.end())
        {
            t.push_back(i); // 将看不见的数字放入t 在下一步排列组合所有情况
        }
    }
    do
    {
        vector<int> ab(a);
        int cnt = 0;
        for (int i = 0; i < t.size(); i++)
        {
            while (1)
            {
                if (ab[cnt] == 0)
                {
                    ab[cnt] = t[i]; // 将所有的排列组合放入放入原数组，看顺序对是否相等 相等即为一种可能性
                    break;
                }
                cnt++;
            }
        }
        if (countDui(ab) == k)
            sum++;
    } while (next_permutation(t.begin(), t.end()));
    cout << sum << endl;
    return 0;
}