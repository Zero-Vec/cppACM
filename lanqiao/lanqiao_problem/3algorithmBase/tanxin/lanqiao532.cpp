#include<bits/stdc++.h>
using namespace std;
int a[30010];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int w,n;
    cin >> w >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 1, r = n;
    int ans = 0;
    while(l<=r){
        if(a[l]+a[r]<=w){
            l++, r--;
            ans++;
        }
        else{
            r--;
            ans++;
        }
    }
    cout << ans;
    return 0;
}