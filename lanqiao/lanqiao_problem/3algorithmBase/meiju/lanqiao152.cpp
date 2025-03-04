#include<bits/stdc++.h>
using namespace std;
bool solve(int x,int a,int b,int c)
{
    if(x%a!=0&&x%b!=0&&x%c!=0)
        return true;
    return false;
}
int main()
{
    int n, a, b, c;
    cin >> n;
    cin >> a >> b >> c;
    int ans = 0;
    for (int i = 1; i <= n;i++)
        if(solve(i,a,b,c))
            ans++;
    cout << ans;
    return 0;
}