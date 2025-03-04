#include <stdio.h>

int main()
{
    FILE *filein;
    FILE *fileout;

    filein = fopen("jill.in", "r");
    fileout = fopen("jill.out", "w");

    int ans[128][3]; //  3 列 第一列表示数据组号  第二列表示 起点  第三列表示终点
    int siz = 0;

    int road[128]; // 存放路径的兴趣度

    int cnt;
    fscanf(filein, "%d", &cnt); // 输入数据组的个数
    while (cnt)
    {
        int city_num;
        fscanf(filein, "%d", &city_num); // 输入城市的个数
        for (int i = 0; i < city_num - 1; i++)
        {
            fscanf(filein, "%d", &road[i]);
        }

        int max = 0;   // 定义最大满意度
        int start = 0; // 定义起点
        int end = 0;   // 定义终点

        for (int i = 0; i < city_num - 1; i++)
        { // 假设每一点都是起点
            if (road[i] < 0)
            {
                continue;
            }
            for (int h = city_num - 2; h >= i; h--)
            { // 假设每一点都是终点
                if (road[h] < 0)
                {
                    continue;
                }

                int temp = 0;
                for (int w = i; w <= h; w++)
                {
                    temp += road[w];
                }
                if (temp > max)
                {
                    max = temp;
                    start = i + 1;
                    end = h + 2;
                }
            }
        }

        ans[siz][0] = max;
        ans[siz][1] = start;
        ans[siz++][2] = end;
        cnt--;
    }

    for (int i = 0; i < siz; i++)
    {
        if (ans[i][0] <= 0)
        {
            fprintf(fileout, "Route %d has no nice parts\n", i + 1);
        }
        else
        {
            fprintf(fileout, "The nicest part of route %d is between stops %d and %d\n", i + 1, ans[i][1], ans[i][2]);
        }
    }

    fclose(filein);
    fclose(fileout);

    return 0;
}