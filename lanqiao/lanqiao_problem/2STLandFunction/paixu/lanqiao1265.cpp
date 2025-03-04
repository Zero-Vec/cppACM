#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
bool cmp(const int &a,const int &b){
    return a > b;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n;i++){
        cout << a[i] << " \n"[i == n - 1];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " \n"[i == n - 1];
    }
    return 0;
}