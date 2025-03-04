/*

前置知识：二分答案，前缀和

变量含义：参赛时间et，休息时间br。

解题思路： 枚举小蓝参加的最后一个项目item[i]，则剩余时间为temp - item[i].et，
然后我们按总时间（参赛+休息）排序，并求出其前缀和数组s，s[i]的含义是前i件项目
的时间和，准备好这些之后，二分答案。check函数我们将枚举的答案x带入s数组中，求出
前x件项目时间之和，随后与剩余时间time比较，这里有个细节是，如果前x件项目中包含
枚举的i，我们需要将其删去并将s[x]改为s[x+1]。

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 4e5;
int n, k, ans;
long long s[N];
struct node
{
    int et, br;
} item[N];
bool cmp(const node &a, const node &b)
{
    return a.et + a.br <= b.et + b.br;
}
bool check(int x, int y, int time)
{
    if (x < y)
    {
        if (s[x] <= time)
            return true;
        else
            return false;
    }
    else
    {
        if (x + 1 > n)
            return false;
        if (s[x + 1] - item[y].et - item[y].br <= time)
            return true;
        else
            return false;
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> item[i].et;
    for (int i = 1; i <= n; i++)
        cin >> item[i].br;
    sort(item + 1, item + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + item[i].et + item[i].br;
    for (int i = 1; i <= n; i++)
    {
        int temp = k;
        if (temp < item[i].et)
            continue;
        temp -= item[i].et;
        int l = 0, r = n;
        while (l + 1 != r)
        {
            int mid = (l + r) >> 1;
            if (check(mid, i, temp))
                l = mid;
            else
                r = mid;
        }
        ans = max(l + 1, ans);
    }
    cout << ans;
    return 0;
}