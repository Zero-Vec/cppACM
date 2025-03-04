#include<bits/stdc++.h>
using namespace std;
bool f(int i)
{
    while(i)
    {
        int x = i % 10;
        if(x==0||x==1||x==2||x==9)
            return true;
        i /= 10;
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n;i++)
    {
        if(f(i))
            sum += i;
    }
    cout << sum;
    return 0;
}