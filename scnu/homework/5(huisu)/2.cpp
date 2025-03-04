#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int A[1001];                   // 正整数集合A
int visit[1001];               // 用于记录各分支的结果情况
int cur_sum = 0;               // 当前整数和
int rem_sum;                   // 余下的整数和
vector<vector<int>> solutions; // 用于存储所有的解
bool flag = false;             // 用于标记是否存在解
int n, y, t;

void solve(int mark)
{
    if (mark > n)
        return;
    if (cur_sum == y)
    {
        vector<int> solution;
        for (int i = 0; i < mark; i++)
        {
            if (visit[i] == 1)
            {
                solution.push_back(A[i]);
            }
        }
        solutions.push_back(solution);
        flag = true;
        return;
    }
    if (cur_sum + A[mark] <= y)
    {
        visit[mark] = 1;
        cur_sum = cur_sum + A[mark];
        rem_sum = rem_sum - A[mark];
        solve(mark + 1);
        cur_sum = cur_sum - A[mark];
        rem_sum = rem_sum + A[mark];
    }
    if (cur_sum + rem_sum - A[mark] >= y)
    {
        visit[mark] = 0;
        rem_sum = rem_sum - A[mark];
        solve(mark + 1);
        rem_sum = rem_sum + A[mark];
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> y;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        rem_sum = rem_sum + A[i];
    }
    cin >> t;
    int mark = 0;
    solve(mark);
    if (!flag)
        cout << "No Solution!";
    else if (t > solutions.size())
        cout << "No Solution!";
    else
    {
        for (int i = 0; i < solutions[t - 1].size(); i++)
        {
            if (i != 0)
                cout << " ";
            cout << solutions[t - 1][i];
        }
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 25;
ll a[N], n, y, id;
bool v[N];
vector<ll> ans;
vector<ll> res;
bool tag;
ll sum;
void dfs(int x)
{
    if(tag)
        return;
    if(sum > y)
        return;
    if (sum == y){
        id--;
    }
    if (!id)
    {
        res = ans;
        tag = 1;
        return;
    }
    if(x == n + 1)
        return;
    for(int i=x;i<=n;i++){
        sum += a[i];
        ans.push_back(a[i]);
        dfs(x + 1);
        sum -= a[i];
        ans.pop_back();
    }
    return;
}
void solve()
{
    cin >> n >> y;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> id;
    dfs(1);
    //cout << id << "\n";
    if(res.empty())
        cout << "No Solution!";
    else{
        cout << res[0];
        for (int i = 1; i < res.size();i++)
            cout << " " << res[i];
    }
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
*/