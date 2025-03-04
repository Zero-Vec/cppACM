#include<bits/stdc++.h>
using namespace std;
int main()
{
    int data[200];
    for (int i = 0; i < 200;i++){
        data[i] = 4 * i + 6;
    }
    int n;
    cin >> n;
    cout << (lower_bound(data, data + 200, n) - data);
    return 0;
}