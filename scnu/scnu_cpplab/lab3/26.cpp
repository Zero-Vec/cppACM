// 使用 do while 语句
#include<iostream>
using namespace std;
int main()
{
    char c = 'A';
    do{
        cout << c;
        c++;
    }while(c <= 'Z');
    cout << endl;
    return 0;
}
/*
// while 语句
#include<iostream>
using namespace std;
int main()
{
    char c = 'A';
    while(c <= 'Z'){
        cout << c;
        c++;
    }
    cout << endl;
    return 0;
}
*/