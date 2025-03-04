#include <stdio.h>
#include <string.h>

// 进行字符与数字的转换
void CharTranslateToInt(int *pi, char *pc, int i)
{
    pi[i] = (int)(pc[i]) - 48;
}

int main(void)
{

    int i, j, k, temp, shi, ge, num1len, num2len;
    int num1[100] = {0}, num2[100] = {0};
    char str[100];
    int sum[200] = {0};

    scanf("%s", str);
    num1len = strlen(str);
    for (i = 0; i < num1len; i++)
    {
        CharTranslateToInt(num1, str, i);
    }

    scanf("%s", str);
    num2len = strlen(str);
    for (i = 0; i < num2len; i++)
    {
        CharTranslateToInt(num2, str, i);
    }
    // 这里将每一次相乘的数加到对应位置上
    for (i = num1len - 1; i >= 0; i--)
    {
        for (j = num2len - 1; j >= 0; j--)
        {
            temp = num1[i] * num2[j];
            sum[num1len + num2len - 2 - i - j] += temp;
        }
    }
    // 接下来统一每一位满十往上一位进一
    for (i = 0; i < 199; i++)
    {
        ge = sum[i] % 10;
        shi = sum[i] / 10;
        sum[i] = ge;
        sum[i + 1] += shi;
    }
    // 从数组的末尾开始遍历，找到第一位非零数
    for (i = 199; i >= 0; i--)
    {
        if (sum[i])
        {
            k = i;
            break;
        }
    }
    // 接下来就是打印结果啦
    // printf("k = %d\n", k);
    for (i = k; i >= 0; i--)
    {
        printf("%d", sum[i]);
    }
    return 0;
}
