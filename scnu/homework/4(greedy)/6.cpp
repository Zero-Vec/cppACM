#include <iostream>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;

#define inf 0x11111111;

struct Point
{
    int x, y;
    double dis;
    // 重载
    bool operator!=(const Point &c) const
    {
        return x != c.x || y != c.y;
    }
};
queue<Point> q;
int n, m;
double fdis[105][105];                                // 记录从开始点到每个点的最小值
double score[105][105];                               // 接收题目中各点的分数
Point A, B;                                           // 起点和终点
int xa, ya, xb, yb;                                   // 边界
int dir1[][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};   // 上下左右的方向
int dir2[][2] = {{-1, -1}, {1, -1}, {-1, 1}, {1, 1}}; // 斜的方向
bool tag;                                             // tag=1表示上半部分，tag=0表示下半部分

// 三角形行列式公式
int cross(Point a, Point b, Point p)
{
    return (b.x - a.x) * (p.y - a.y) - (p.x - a.x) * (b.y - a.y);
}

void inque(Point p)
{
    // 有效值判断
    if (p.x < 1 || p.x > n || p.y < 1 || p.y > m)
    {
        return;
    }
    // 当有最小值更新，否则return
    if (p.dis >= fdis[p.x][p.y])
    {
        return;
    }
    if (tag)
    {
        // 上半部分，但是包含起点和终点
        if (p != A && p != B && cross(A, B, p) <= 0)
        {
            return;
        }
    }
    else
    {
        // 下半部分，但是包含起点和终点
        if (p != A && p != B && cross(A, B, p) >= 0)
        {
            return;
        }
    }
    fdis[p.x][p.y] = p.dis; // 更新
    // 到终点时，就不继续将其入队
    if (p.x == B.x && p.y == B.y)
    {
        return;
    }
    q.push(p);
}

void bfs()
{
    // 清空队列
    while (!q.empty())
    {
        q.pop();
    }
    // 初始化
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            fdis[i][j] = inf;
        }
    }
    inque(A);
    while (!q.empty())
    {
        Point now = q.front();
        q.pop();
        Point next;
        // 计算上下左右方向
        for (int i = 0; i < 4; i++)
        {
            next.x = now.x + dir1[i][0];
            next.y = now.y + dir1[i][1];
            next.dis = fdis[now.x][now.y] + score[next.x][next.y];
            inque(next);
        }
        // 计算斜方向
        for (int i = 0; i < 4; i++)
        {
            next.x = now.x + dir2[i][0];
            next.y = now.y + dir2[i][1];
            next.dis = fdis[now.x][now.y] + score[next.x][next.y] + (score[next.x][next.y] + score[now.x][now.y]) * (sqrt(2) - 1);
            inque(next);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> score[i][j];
            fdis[i][j] = inf;
        }
    }
    cin >> A.y >> A.x >> B.y >> B.x;
    A.x++;
    A.y++;
    B.x++;
    B.y++; // 因为每从0开始，所以都加1，并且对其表示进行了转化
    A.dis = score[A.x][A.y];

    double ans = 0;
    tag = false;
    bfs();
    ans += fdis[B.x][B.y]; // 上半部分
    tag = true;
    bfs();
    ans += fdis[B.x][B.y];                                     // 下半部分
    printf("%.2f\n", ans - score[A.x][A.y] - score[B.x][B.y]); // 最后再减去重复的起点和终点
}