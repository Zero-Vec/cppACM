#include <iostream>
#include <string>

using namespace std;

// 定义函数 escape，用于将字符串 t 转换为带换码序列的字符串 s
void escape(string &s, const string &t)
{
    s = ""; // 清空目标字符串 s
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '\n' && i != t.size() - 1)
            s += "\\n"; // 换行符转换为换码序列 \n
        else if (t[i] == '\t')
            s += "\\t"; // 制表符转换为换码序列 \t
        else
            s += t[i]; // 其余字符保持不变
    }
}

int main()
{
    string t;
    string s;
    char c;
    while (cin.get(c))
        t += c;
    escape(s, t);
    cout << s;
    return 0;
}
