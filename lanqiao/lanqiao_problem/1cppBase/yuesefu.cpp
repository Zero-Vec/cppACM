#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int main()
{
    // 约瑟夫环问题
    int n, m, x;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }
    int id = 1;
    while (q.size() != 1)
    {
        int tmp = q.front();
        q.pop();
        if (id != m)
        {
            id++;
            q.push(tmp);
        }
        else
        {
            id = 1;
        }
    }
    cout << q.front() << "\n";
    system("pause");
    return 0;
}