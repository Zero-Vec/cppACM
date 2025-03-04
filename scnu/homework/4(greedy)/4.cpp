#include <bits/stdc++.h>
using namespace std;
#define N 1010
struct node
{
    int id;             // 编号
    double num;         // 亲密度
} a[N], b[N];           // 分别储存和a,b有关的异性编号以及亲密度
int vis[N];             // 记录性别，是女性的话为1，否则为0
int check(int x, int y) // 返回x与y是否为异性（若是异性返回1）
{
    x = abs(x);
    y = abs(y);
    return vis[x] != vis[y];
}
void print(int x, int y) // 输出x和y的编号
{
    if (vis[x])
        cout << "-";
    cout << x << " ";
    if (vis[y])
        cout << "-";
    cout << y << endl;
}
int swap(string s) // 将字符串转化为数字
{
    int i = 0, ans = 0;
    if (s[0] == '-')
    {
        i++;
        while (i < s.size())
        {
            ans = ans * 10 + s[i] - '0';
            i++;
        }
        vis[ans] = 1; // 如果是负数（女性），标记一下
        return ans;
    }
    while (i < s.size())
    {
        ans = ans * 10 + s[i] - '0';
        i++;
    }
    return ans;
}
int x, y;           // 分别表示最后输入的一对情侣的编号
vector<int> peo[N]; // 存储照片信息，坑死kr，一开始开到505，一直段错误，服了
int main()
{
    int n, m, k, tem;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            tem;
            string s;
            cin >> s;
            tem = swap(s);
            peo[i].push_back(tem);
        }
    }
    string s;
    cin >> s;
    x = swap(s);
    cin >> s;
    y = swap(s);
    for (int i = 0; i < n; i++) // 初始化
    {
        a[i].id = i;
        b[i].id = i;
    }
    double maxa = 0, maxb = 0;
    for (int i = 0; i < m; i++)
    {
        k = peo[i].size();
        int flag1 = 0, flag2 = 0;
        for (int j = 0; j < k; j++)
        {
            if (peo[i][j] == x)
                flag1 = 1;
            if (peo[i][j] == y)
                flag2 = 1;
        }
        if (flag1) // 如果照片中有x，则遍历照片，更新亲密度
        {
            for (int j = 0; j < k; j++)
            {
                tem = peo[i][j];
                if (tem != x && check(tem, x))
                    a[tem].num += 1.0 / k * 1.0;
            }
        }
        if (flag2) // 如果照片中有y，则重复以上操作
        {
            for (int j = 0; j < k; j++)
            {
                tem = peo[i][j];
                if (tem != y && check(tem, y))
                    b[tem].num += 1.0 / k * 1.0;
            }
        }
    }
    for (int i = 0; i < n; i++) // 找出异性中亲密度最高的
    {
        maxa = max(maxa, a[i].num);
        maxb = max(maxb, b[i].num);
    }
    int flag1 = 0, flag2 = 0; // 分别记录对方是否是自己亲密度最高的异性
    for (int i = 0; i < n; i++)
    {
        if (a[i].id == y && a[i].num == maxa)
            flag1 = 1;
    }
    for (int i = 0; i < n; i++)
        if (b[i].id == x && b[i].num == maxb)
            flag2 = 1;
    if (flag1 && flag2) // 若双方互为亲密度最高，直接输出
    {
        print(x, y);
        return 0;
    }
    for (int i = 0; i < n; i++) // 否则按编号从小到大分别输出所有亲密度最高的异性
    {
        if (a[i].num == maxa)
            print(x, a[i].id);
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i].num == maxb)
            print(y, b[i].id);
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
double d[N][N];
bool v[N];
int n, m;
void solve()
{
    cin >> n >> m;
    while (m--)
    {
        int x;
        cin >> x;
        vector<int> t;
        for (int i = 0; i < x; i++)
        {
            int tmp;
            cin >> tmp;
            t.push_back(tmp);
            if (t[i] < 0)
                v[abs(t[i])] = 0;
            else
                v[t[i]] = 1;
        }
        for (int i = 0; i < t.size() - 1; i++)
        {
            for (int j = i + 1; j < t.size(); j++)
            {
                if (t[i] >= 0)
                {
                    if (t[j] < 0)
                    {
                        d[t[i]][abs(t[j])] += 1.0 / x;
                        d[abs(t[j])][t[i]] += 1.0 / x;
                    }
                }
                else
                {
                    if (t[j] > 0)
                    {
                        d[abs(t[i])][t[j]] += 1.0 / x;
                        d[t[j]][abs(t[i])] += 1.0 / x;
                    }
                }
            }
        }
    }
    int a, b;
    cin >> a >> b;
    set<int> a1, b1;
    double mxa = 0, mxb = 0;
    for (int i = 0; i < n; i++)
        mxa = max(d[abs(a)][i], mxa);
    for (int i = 0; i < n; i++)
        mxb = max(d[abs(b)][i], mxb);
    if (a < 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (!v[i])
                continue;
            if (d[abs(a)][i] == mxa)
                a1.insert(i);
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i])
                continue;
            if (d[abs(b)][i] == mxb)
                b1.insert(i);
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (!v[i])
                continue;
            if (d[abs(b)][i] == mxb)
                b1.insert(i);
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i])
                continue;
            if (d[abs(a)][i] == mxa)
                a1.insert(i);
        }
    }
    if (a1.count(abs(b)) && b1.count(abs(a)))
    {
        cout << a << ' ' << b;
    }
    else
    {
        if (a < 0)
        {
            for (auto i : a1)
                cout << a << ' ' << i << '\n';
            for (auto i : b1)
                cout << b << ' ' << -1 * i << '\n';
        }
        else
        {
            for (auto i : a1)
                cout << a << ' ' << -1 * i << '\n';
            for (auto i : b1)
                cout << b << ' ' << i << '\n';
        }
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