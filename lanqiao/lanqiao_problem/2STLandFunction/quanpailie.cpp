#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[5];
    for (int i = 1; i <= 4;i++){
        a[i] = i;
    }
    bool tag = true;
    while(tag){
        for (int i = 1; i <= 4;i++){
            cout << a[i] << " \n"[i == 4];
        }
        tag = next_permutation(a + 1, a + 1 + 4);
    }
    cout << "-------------------------"
         << "\n";
    int b[5] = {0, 2, 3, 4, 1};
    bool flag = true;
    while(flag){
        for (int i = 1; i <= 4;i++){
            cout << b[i] << " \n"[i == 4];
        }
        flag = prev_permutation(b + 1, b + 1 + 4);
    }
    return 0;
}