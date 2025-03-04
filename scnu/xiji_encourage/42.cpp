#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define right 3 // 宏定义方向
#define right_down 4
#define down 5
#define left_down 6
int q[30][30]; // 棋盘
int i = 0, j = 0;
int flag = 0;              // 判断标志
void search(int q[][30]);  // 搜索函数
void move(int m, int num); // 搜索方向
int main()
{
    for (i = 1; i <= 19; i++)
    {
        for (j = 1; j <= 19; j++)
        {
            scanf("%d", &q[i][j]); // 输入当前棋盘
        }
    }
    i = 1, j = 1;
    search(q); // 开始搜索

    if (flag == 1)
    {
        printf("%d:%d,%d", flag, i, j);
    }
    else if (flag == 2)
    {
        printf("%d:%d,%d", flag, i, j);
    }
    else
    {
        printf("No");
    }
    return 0;
}
void move(int m, int num)
{
    if (m == 3) // right
    {
        if (q[i][j + 1] == num && q[i][j + 2] == num && q[i][j + 3] == num && (q[i][j + 4] == 0 || q[i][j - 1] == 0)) // 0表示有可以下棋的位置
        {
            flag = num;
        }
    }
    else if (m == 4) // right_down
    {
        if (q[i + 1][j + 1] == num && q[i + 2][j + 2] == num && q[i + 3][j + 3] == num && (q[i + 4][j + 4] == 0 || q[i - 1][j - 1] == 0)) // 0表示有可以下棋的位置
        {
            flag = num;
        }
    }
    else if (m == 5) // down
    {
        if (q[i + 1][j] == num && q[i + 2][j] == num && q[i + 3][j] == num && (q[i + 4][j] == 0 || q[i - 1][j] == 0)) // 0表示有可以下棋的位置
        {
            flag = num;
        }
    }
    else if (m == 6) // left_down
    {
        if (q[i + 1][j - 1] == num && q[i + 2][j - 2] == num && q[i + 3][j - 3] == num && (q[i + 4][j - 4] == 0 || q[i - 1][j + 1] == 0)) // 0表示有可以下棋的位置
        {
            flag = num;
        }
    }
}
void search(int q[][30])
{
    for (i = 1; i <= 19; i++)
    {
        for (j = 1; j <= 19; j++)
        {
            if (q[i][j] == 1)
            {
                if (j == 1) // 如果在最左边
                {
                    move(right, 1);
                    move(right_down, 1);
                    move(down, 1);
                    if (flag != 0)
                        break;
                }
                else if (j == 19) // 如果在最右边
                {
                    move(left_down, 1);
                    move(down, 1);
                    if (flag != 0)
                        break;
                }
                else // 其余情况
                {
                    move(right, 1);
                    move(right_down, 1);
                    move(down, 1);
                    move(left_down, 1);
                    if (flag != 0)
                        break;
                }
            }
            if (q[i][j] == 2) // 与重复上面步骤
            {
                if (j == 1)
                {
                    move(right, 2);
                    move(right_down, 2);
                    move(down, 2);
                    if (flag != 0)
                        break;
                }
                else if (j == 19)
                {
                    move(left_down, 2);
                    move(down, 2);
                    if (flag != 0)
                        break;
                }
                else
                {
                    move(right, 2);
                    move(right_down, 2);
                    move(down, 2);
                    move(left_down, 2);
                    if (flag != 0)
                        break;
                }
            }
        }
        if (flag != 0)
            break;
    }
}
