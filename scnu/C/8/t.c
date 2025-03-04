#include<stdio.h>

int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *ans[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int isleapYear(int y){
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int totalDay(int y,int m,int d){
    int sum = 0;
    for (int i = 1980; i < y;i++)
        sum += isleapYear(i) ? 366 : 365;
    if(isleapYear(y))
        mon[2] = 29;
    for (int i = 1; i < m;i++)
        sum += mon[i];
    sum += d - 1;
    return sum;
}

int main()
{
    int y, m, d;
    scanf("%d-%d-%d", &y, &m, &d);
    printf("%s\n", ans[(totalDay(y, m, d) + 2) % 7]);
    return 0;
}