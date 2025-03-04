#include <iostream>
using namespace std;
int a[1000], b[1000];
int x, n;
int main()
{
    cin >> x >> n;
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i] = x; // a是被减数,b是用来减的
    }
    int t = n - 1; // 记录b中x的个数，就是看看减几个x
    // b不变 a变
    for (int i = 0; i < n; i++) // 一共减n次
    {
        for (int j = 0; j < t; j++) // 控制b的数量
        {
            if (a[j] - b[j] < 0) // 稍微难点的是会有借位
            {
                a[j] = a[j] + 10 - b[j];
                int p = 1;
                while (a[j + p] == 0) // 注意可能不只是向前一位借 ，我第一次就是被坑了这
                {
                    a[j + p] = 9;
                    p++;
                }
                a[j + p]--; // 最后借的就是前面第一个不是0的数的它
            }
            else
            {
                a[j] = a[j] - b[j];
            }
        }

        // cout << endl;
        t--;
    }
    // 防止最前的是0做的标记
    int k = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] != 0) // 标记
            k = 1;
        if (k == 0 && a[i] == 0)
            continue;
        cout << a[i];
    }
    return 0;
}
