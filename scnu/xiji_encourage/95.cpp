#include <iostream>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int year, int month) {
    if (month == 2) 
        return isLeapYear(year) ? 29 : 28;
    if (month == 4 || month == 6 || month == 9 || month == 11) 
        return 30;
    return 31;
}

int getsum(Date date) {
    int sum = 0;
    for (int y = 0; y < date.year; ++y) 
        sum += isLeapYear(y) ? 366 : 365;
    for (int m = 1; m < date.month; ++m) 
        sum += daysInMonth(date.year, m);
    sum += date.day;
    return sum;
}

int main() {
    Date date1, date2;
    cin >> date1.year >> date1.month >> date1.day;
    cin >> date2.year >> date2.month >> date2.day;
    int days1 = getsum(date1);
    int days2 = getsum(date2);
    cout << days2 - days1 << endl;
    return 0;
}