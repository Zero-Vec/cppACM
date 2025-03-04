#include<iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 7;i++){
        if(i <= 4){
            for (int j = 1; j <= 4 - i;j++)
                cout << " ";
            for (int j = 1; j <= 2 * i - 1;j++)
                cout << "*";
        }
        else{
            for (int j = 5; j <= i;j++)
                cout << " ";
            int t = i - 5;
            for (int j = 1; j <= 5 - 2 * t;j++)
                cout << "*";
        }
        cout << '\n';
    }
    return 0;
}