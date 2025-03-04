#include<iostream>
using namespace std;
int main()
{
    int sum = 0, odd_sum = 0, even_sum = 0;
    for(int i = 1; i <= 100; i++){
        sum += i;
        if(i % 2 == 0)
            even_sum += i;
        else
            odd_sum += i;
    }
    cout << "1 ~ 100 之和为：" << sum << endl;
    cout << "1 ~ 100 中偶数之和为：" << even_sum << endl;
    cout << "1 ~ 100 中奇数之和为：" << odd_sum << endl;
    return 0;
}