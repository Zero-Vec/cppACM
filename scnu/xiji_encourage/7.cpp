#include<bits/stdc++.h>
using namespace std;
struct Student{
    string name;
    int chinese;
    int math;
    int english;
    int sum; // 总分
    // 构造函数
    Student(string n, int c, int m, int e) : name(n), chinese(c), math(m), english(e), sum(c + m + e) {}
};
bool cmp(const Student &a, const Student &b)
{
    if (a.sum != b.sum)
        return a.sum > b.sum; // 按总分从高到低排序
    if (a.chinese != b.chinese)
        return a.chinese > b.chinese; // 按语文成绩从高到低排序
    if (a.math != b.math)
        return a.math > b.math; // 按数学成绩从高到低排序
    return a.name < b.name; // 按姓名字典序排序
}
int main()
{
    int N;
    cin >> N;
    vector<Student> students;
    for (int i = 0; i < N; i++){
        string name;
        int chinese, math, english;
        cin >> name >> chinese >> math >> english;
        students.emplace_back(name, chinese, math, english);
    }
    int K;
    cin >> K;
    sort(students.begin(), students.end(), cmp);
    cout << students[K - 1].name << " " << students[K - 1].sum << '\n';
    return 0;
}
