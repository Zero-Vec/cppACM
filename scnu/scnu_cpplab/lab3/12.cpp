// switch 语句
#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cout << "请分别输入该学生的两门课成绩：" << endl;
    cin >> x >> y;
    if (x < 0 || x > 100 || y < 0 || y > 100)
        cout << "error" << endl;
    else
    {
        int sum = x + y;
        int level;
        if (sum >= 180)
            level = 0;
        else if (sum >= 160)
            level = 1;
        else if (sum >= 140)
            level = 2;
        else if (sum >= 120)
            level = 3;
        else
            level = 4;
        switch (level)
        {
        case 0:
            cout << sum << "---->" << 'A' << endl;
            break;
        case 1:
            cout << sum << "---->" << 'B' << endl;
            break;
        case 2:
            cout << sum << "---->" << 'C' << endl;
            break;
        case 3:
            cout << sum << "---->" << 'D' << endl;
            break;
        case 4:
            cout << sum << "---->" << 'E' << endl;
            break;
        }
    }
    return 0;
}
/*
// if 语句
#include<iostream>
using namespace std;
int main()
{
    int x, y;
    cout << "请分别输入该学生的两门课成绩：" << endl;
    cin >> x >> y;
    if(x < 0 || x > 100 || y < 0 || y > 100)
        cout << "error" << endl;
    else{
        int sum = x + y;
        if(sum >= 180)
            cout << sum << "---->" << 'A' << endl;
        else if(sum >= 160)
            cout << sum << "---->" << 'B' << endl;
        else if(sum >= 140)
            cout << sum << "---->" << 'C' << endl;
        else if(sum >= 120)
            cout << sum << "---->" << 'D' << endl;
        else
            cout << sum << "---->" << 'E' << endl;
    }
    return 0;
}
*/