#include<iostream>
using namespace std;
int main()
{
    int a[5];
    cout << "请输入五个整数：" << endl;
    for (int i = 0; i < 5;i++)
        cin >> a[i];
    // 使用选择法对数组从小到大排序
    for (int i = 0; i < 5;i++){
        int k = i;
        for (int j = i + 1; j < 5;j++){
            if(a[j] < a[k])
                k = j; // 找到该轮最小值对应的下标
        }
        if(k != i){
            int t = a[i];
            a[i] = a[k];
            a[k] = t;
        }
    }
    cout<<"排序后的数组为：";
    for(int i = 0; i < 5;i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}