#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Student
{
    int id;
    string name;
    int math;
    int english;
    int chinese;
    int sum;
    int rank; 
}stu[15];
bool cmp(const Student &a, const Student &b)
{
    if (a.sum != b.sum)
        return a.sum < b.sum;
    return a.id < b.id;
}

int main()
{
    int n;
    cin >> n;
    if (n < 1 || n >= 10){
        cout << "Please input 1-9." << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++){
        cin >> stu[i].id >> stu[i].name >> stu[i].math >> stu[i].english >> stu[i].chinese;
        stu[i].sum = stu[i].math + stu[i].english + stu[i].chinese;
    }
    sort(stu + 1, stu + 1 + n, cmp);
    for (int i = n; i >= 1; i--){
        if(i == n)
            stu[i].rank = 1;
        else{
            if(stu[i].sum == stu[i + 1].sum)
                stu[i].rank = stu[i + 1].rank;
            else
                stu[i].rank = n - i + 1;
        }
    }
    for (int i = 1; i <= n;i++)
    {
        cout << setw(4) << stu[i].rank
             << setw(10) << stu[i].id
             << setw(10) << stu[i].name
             << setw(5) << stu[i].math
             << setw(5) << stu[i].english
             << setw(5) << stu[i].chinese
             << '\n';
    }
    return 0;
}
