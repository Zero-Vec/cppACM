#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    int next;
};
node nds[100005];
int v1[100005]; // 存放删去的
int v2[100005]; // 存放未被删去的
bool isVisit[10005];
int main()
{
    ios::sync_with_stdio(false);
    int N;
    int L;
    cin >> L >> N;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        cin >> nds[tmp].value >> nds[tmp].next;
    }
    int p = L;
    int loc1 = 0, loc2 = 0;
    while (true)
    {
        if (isVisit[abs(nds[p].value)]) // 如果之前已经访问过这个值的绝对值
        {
            v1[loc1++] = p; // 提前存起来
        }
        else
        {
            isVisit[abs(nds[p].value)] = true;
            v2[loc2++] = p; // 提前存起来
        }
        if (nds[p].next == -1)
        {
            break;
        }
        p = nds[p].next;
    }
    // 将之前提前存起来的结点的下一站进行更新
    for (int i = 0; i < loc2; i++)
    {
        if (i + 1 < loc2)
        {
            nds[v2[i]].next = v2[i + 1];
        }
        else
        {
            nds[v2[i]].next = -1;
        }
        // 如果下一站是-1，则不需要满足5位补0
        if (nds[v2[i]].next == -1)
        {
            printf("%05d %d %d\n", v2[i], nds[v2[i]].value, nds[v2[i]].next);
        }
        else
        {
            printf("%05d %d %05d\n", v2[i], nds[v2[i]].value, nds[v2[i]].next);
        }
    }
    // 将之前提前存起来的结点的下一站进行更新
    for (int i = 0; i < loc1; i++)
    {
        if (i + 1 < loc1)
        {
            nds[v1[i]].next = v1[i + 1];
        }
        else
        {
            nds[v1[i]].next = -1;
        }
        // 如果下一站是-1，则不需要满足5位补0
        if (nds[v1[i]].next == -1)
        {
            printf("%05d %d %d\n", v1[i], nds[v1[i]].value, nds[v1[i]].next);
        }
        else
        {
            printf("%05d %d %05d\n", v1[i], nds[v1[i]].value, nds[v1[i]].next);
        }
    }
    return 0;
}
