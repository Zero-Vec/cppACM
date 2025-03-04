#include<iostream>
using namespace std;
int main()
{
    double stu_avg, course_avg;
    int a[3][3] = {
        85, 90, 80,
        65, 70, 75,
        75, 85, 77};
    for (int i = 0; i < 3;i++){
        stu_avg = 0;
        course_avg = 0;
        for (int j = 0; j < 3;j++){
            stu_avg += a[i][j];
            course_avg += a[j][i];
        }
        cout << "第" << i + 1 << "个学生的平均成绩为：" << stu_avg / 3 << endl;
        if(i == 0)
            cout << "该小组英语课程的平均成绩为：" << course_avg / 3 << endl;
        if(i == 1)
            cout << "该小组高等数学课程的平均成绩为：" << course_avg / 3 << endl;
        if(i == 2)
            cout << "该小组C++课程的平均成绩为：" << course_avg / 3 << endl;
    }
    return 0;
}