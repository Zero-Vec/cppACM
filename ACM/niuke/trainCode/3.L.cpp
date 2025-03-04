#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int a[1010];
int c1, c2, c3, c4,c5,c6;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(a[i]==3)
            c1++;
        if(a[i]==6)
            c2++;
        if(a[i]==2)
            c3++;
        if(a[i]==7)
            c4++;
        if(a[i]==8)
            c5++;
        if(a[i]==10)
            c6++;
    }
    int k1, k2,k3;
    if(c4==0||c3==0)
        k2 = 0;
    else
        k2 = max(c4, c3);
    if(c1==0||c2==0)
        k1 = 0;
    else
        k1 = max(c1, c2);
    if (c5 == 0 || c6 == 0)
        k3 = 0;
    else
        k3 = max(c5, c6);
    int ans = k1 + k2 + k3;
    if(n==1)
        cout << 0;
    else
        cout << ans;
    return 0;
}