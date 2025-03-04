#include <stdio.h>

// 定义一个结构体来存储日期
struct Date
{
    int year;
    int month;
    int day;
};

// 函数原型声明
int calculateAge(struct Date birthDate, struct Date currentDate);
void parseDate(const char *dateStr, struct Date *parsedDate);

int main()
{
    // 用于存储输入的字符串
    char birthDateStr[20], currentDateStr[20];

    // 读取出生日期
    scanf("%19s", birthDateStr); // 防止缓冲区溢出

    // 读取当前日期
    scanf("%19s", currentDateStr); // 防止缓冲区溢出

    // 解析日期字符串到结构体
    struct Date birthDate, currentDate;
    parseDate(birthDateStr, &birthDate);
    parseDate(currentDateStr, &currentDate);

    // 计算年龄
    int age = calculateAge(birthDate, currentDate);

    // 输出结果
    printf("%d\n", age);

    return 0;
}

// 解析日期字符串到结构体
void parseDate(const char *dateStr, struct Date *parsedDate)
{
    sscanf(dateStr, "%d.%d.%d", &parsedDate->year, &parsedDate->month, &parsedDate->day);
}

// 计算年龄
int calculateAge(struct Date birthDate, struct Date currentDate)
{
    int age = currentDate.year - birthDate.year;

    // 如果当前日期还没到达生日，则减一年
    if (currentDate.month < birthDate.month ||
        (currentDate.month == birthDate.month && currentDate.day < birthDate.day))
    {
        age--;
    }

    return age;
}