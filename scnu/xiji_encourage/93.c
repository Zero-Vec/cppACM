#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_LEN 1000
// 栈结构
typedef struct
{
    int data[MAX_LEN];
    int top;
} Stack;
void push(Stack *stack, int value)
{
    stack->data[++stack->top] = value;
}
int pop(Stack *stack)
{
    return stack->data[stack->top--];
}
int peek(Stack *stack)
{
    return stack->data[stack->top];
}
// 运算
int calculate(int a, char op, int b)
{
    switch (op){
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b; // 整数除法
    }
    return 0;
}

int priority(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int cal_Expression(char *expression)
{
    Stack values, ops;
    values.top = ops.top = -1;

    int i = 0;
    while (expression[i] != '\0')
    {
        // 忽略空格
        if (isspace(expression[i]))
        {
            i++;
            continue;
        }

        // 如果是数字，读取完整数字并压入操作数栈
        if (isdigit(expression[i]))
        {
            int value = 0;
            while (i < strlen(expression) && isdigit(expression[i]))
            {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            push(&values, value);
            continue; // 跳过后续处理
        }

        // 如果是左括号，直接压入操作符栈
        if (expression[i] == '(')
        {
            push(&ops, expression[i]);
        }
        // 如果是右括号，处理括号内的内容
        else if (expression[i] == ')')
        {
            while (ops.top != -1 && peek(&ops) != '(')
            {
                int b = pop(&values);
                int a = pop(&values);
                char op = pop(&ops);
                push(&values, calculate(a, op, b));
            }
            pop(&ops); // 弹出左括号
        }
        // 如果是操作符
        else if (strchr("+-*/", expression[i]))
        {
            while (ops.top != -1 && priority(peek(&ops)) >= priority(expression[i]))
            {
                int b = pop(&values);
                int a = pop(&values);
                char op = pop(&ops);
                push(&values, calculate(a, op, b));
            }
            push(&ops, expression[i]);
        }
        i++;
    }

    // 处理剩余操作符
    while (ops.top != -1)
    {
        int b = pop(&values);
        int a = pop(&values);
        char op = pop(&ops);
        push(&values, calculate(a, op, b));
    }

    return pop(&values);
}

int main()
{
    char expression[MAX_LEN];
    // 输入表达式并去掉末尾的 '='
    fgets(expression, MAX_LEN, stdin);
    int len = strlen(expression);
    if (expression[len - 1] == '=')
        expression[len - 1] = '\0'; // 去掉末尾的 '='
    // 计算表达式结果
    int ans = cal_Expression(expression);
    // 输出结果
    printf("%d\n", ans);
    return 0;
}
