#include<iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 9;i++)
        for (int j = 0; j <= 9;j++)
            if((10 * i + 2) * (70 + j) == 3848)
                cout << i << "2*7" << j << "=" << 3848 << endl;
    return 0;
}