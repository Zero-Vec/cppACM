#include<iostream>
using namespace std;
int main()
{
    for (int i = 100; i <= 1000;i++){
        int t = i;
        int sum = 0;
        while(t){
            sum += t % 10;
            t /= 10;
        }
        if(sum == 5)
            cout << i << endl;
    }
    return 0;
}