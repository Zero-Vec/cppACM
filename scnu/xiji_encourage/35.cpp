#include<bits/stdc++.h>
using namespace std;

// 获取运算符的优先级
int Priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 判断是否需要括号
bool check(char outerOp, char innerOp, bool isLeft)
{
    int out = Priority(outerOp);
    int inner = Priority(innerOp);
    if (inner > out)
        return false;
    if (inner < out)
        return true;
    return !isLeft;
}

// 将后缀表达式转换为中缀表达式
string postfixToInfix(const string &postfix)
{
    stack<pair<string, char>> s; // 栈存储中缀表达式和对应运算符
    stringstream ss(postfix);
    string token;

    while (ss >> token)
    {
        if (isdigit(token[0]) || token.find('.') != string::npos)
        {
            // 是数字，直接压入栈
            s.push({token, '\0'});
        }
        else
        {
            // 是运算符
            char op = token[0];
            auto b = s.top();
            s.pop();
            auto a = s.top();
            s.pop();

            // 判断是否需要括号
            string left = a.first, right = b.first;
            if (a.second && check(op, a.second, true))
            {
                left = "(" + left + ")";
            }
            if (b.second && check(op, b.second, false))
            {
                right = "(" + right + ")";
            }

            // 构造新的表达式
            s.push({left + op + right, op});
        }
    }

    return s.top().first;
}

int main()
{
    string postfix;
    getline(cin, postfix);
    cout << postfixToInfix(postfix) << endl;
    return 0;
}
