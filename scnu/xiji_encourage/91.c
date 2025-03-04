#include <stdio.h>
#include <stdlib.h>
#define maxn 15
// 定义节点
typedef struct node{
    int row, col, v;
} node;
// 定义三元组存储稀疏矩阵
struct T{
    node Node[maxn];
    int MAXrow, MAXcol, MAXsize;
} TA, TB, TC;

int main()
{
    int num1, num2, i, j, k, sum, p, q;
    scanf("%d", &num1); // 输入a矩阵
    TA.MAXsize = num1;
    for (i = 0; i < num1; i++)
        scanf("%d%d%d", &TA.Node[i].row, &TA.Node[i].col, &TA.Node[i].v);
    TA.MAXrow = maxn;
    TA.MAXcol = maxn;

    scanf("%d", &num2); // 输入b矩阵
    TB.MAXsize = num2;
    for (k = 0; k < num2; k++)
        scanf("%d%d%d", &TB.Node[k].row, &TB.Node[k].col, &TB.Node[k].v);
    TB.MAXrow = maxn;
    TB.MAXcol = maxn;

    TC.MAXsize = 0;
    TC.MAXrow = maxn;
    TC.MAXrow = maxn;
    for (i = 0; i < maxn; i++){ 
        // 计算c矩阵
        for (j = 0; j < maxn; j++){
            sum = 0;
            for (p = 0; p < TA.MAXsize; p++){
                if (TA.Node[p].row != i)
                    continue;
                for (q = 0; q < TB.MAXsize; q++){
                    if (TB.Node[q].col != j)
                        continue;
                    if (TA.Node[p].col == TB.Node[q].row)
                        sum += TA.Node[p].v * TB.Node[q].v;
                }
            }
            if (sum != 0){
                TC.Node[TC.MAXsize].row = i;
                TC.Node[TC.MAXsize].col = j;
                TC.Node[TC.MAXsize].v = sum;
                TC.MAXsize++;
            }
        }
    }
    for (i = 0; i < TC.MAXsize; i++)
        printf("%d %d %d\n", TC.Node[i].row, TC.Node[i].col, TC.Node[i].v);
    return 0;
}