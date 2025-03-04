#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int time;
    double salary_hour, salary;
    cout << "请输入该员工的劳动时间：";
    cin >> time;
    cout << "请输入该员工的每小时工资数：";
    cin >> salary_hour;
    salary = 0.9 * time * salary_hour;
    cout << "该员工应发的工资为：";
    cout << fixed << setprecision(2) << salary << endl;
    return 0;
}