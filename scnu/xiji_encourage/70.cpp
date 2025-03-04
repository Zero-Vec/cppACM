#include<bits/stdc++.h>
using namespace std;

struct Window
{
    int id;
    int x1, y1, x2, y2;
    int layer;
};

int main()
{
    int n;
    cin >> n;

    vector<Window> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i].id >> w[i].x1 >> w[i].y1 >> w[i].x2 >> w[i].y2;
        w[i].layer = i; // 初始化时每个窗口都在自己的层次
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        sort(w.begin(), w.end(), [](const Window &w1, const Window &w2)
             { return w1.layer < w2.layer; }); // 每次都要进行排序，因为窗口每次点击后的层次顺序都会发生变化（lambda表达式做仿函数）
        // 找到被点击的窗口
        int top = -1;
        for (int j = 0; j < n; j++)
        {
            if ((x >= w[j].x1 && x <= w[j].x2) && (y <= w[j].y1 && y >= w[j].y2))
            {
                top = j;
                break;
            }
        }

        // 如果有被点击的窗口，则将其移到最顶层
        if (top != -1)
        {
            int cur_layer = w[top].layer; // 2层（0/1/2/3）
            for (int j = 0; j < n; j++)
            {
                if (w[j].layer < cur_layer)
                {
                    w[j].layer++;
                }
            }
            w[top].layer = 0;
        }
    }

    // 按照窗口层次输出叠放次序
    sort(w.begin(), w.end(), [](const Window &w1, const Window &w2)
         { return w1.layer < w2.layer; });
    for (const auto &window : w)
    {
        cout << window.id << " ";
    }
    cout << endl;

    return 0;
}
