#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int x;
    int sum = 0;
    for (int i = 0; i < n;i++){
        cin >> x;
        sum += x;
    }
    if(sum%2==0)
        cout << "Bob" << '\n';
    else
        cout << "Alice" << '\n';
    return 0;
}