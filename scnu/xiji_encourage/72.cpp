#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int loc = 0;
    cin >> loc;   // 读取冒号的位置
    cin.ignore(); // 清除缓冲区中的换行符

    string a, b, c;

    while (getline(cin, a))
    {
        if (a.empty())
        {
            continue;
        }

        // 将制表符替换为空格
        for (int i = 0; i < a.length(); ++i)
        {
            if (a[i] == '\t')
            {
                a.replace(i, 1, " ");
            }
        }

        // 删除开头的空格
        while (!a.empty() && a[0] == ' ')
        {
            a.erase(0, 1);
        }

        // 删除中间多余的空格，并找到冒号的位置
        int i = 0;
        for (; i < a.length(); ++i)
        {
            if (a[i] == ' ' && a[i + 1] == ' ')
            {
                a.erase(i, 1);
                --i;
            }
            if (a[i] == ' ' && a[i + 1] == ':')
            {
                a.erase(i, 1);
                break;
            }
            if (a[i] == ':')
            {
                break;
            }
        }

        b = a.substr(0, i);  // 冒号前的字符串
        c = a.substr(i + 1); // 冒号后的字符串

        // 删除冒号后的前导空格
        while (!c.empty() && c[0] == ' ')
        {
            c.erase(0, 1);
        }

        // 删除冒号后的中间多余空格
        for (int i = 0; i < c.length(); ++i)
        {
            if (c[i] == ' ' && c[i + 1] == ' ')
            {
                c.erase(i, 1);
                --i;
            }
        }

        // 删除冒号后的尾部空格
        while (!c.empty() && c.back() == ' ')
        {
            c.pop_back();
        }

        // 格式化输出到标准输出
        cout << right << setw(loc + 1) << b << " : " << c << endl;
    }

    // 最后输出一个额外的换行符
    cout << endl;

    return 0;
}
