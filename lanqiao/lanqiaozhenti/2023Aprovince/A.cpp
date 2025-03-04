#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int digwei(int x)
{
    int wei = 0;
    while (x)
    {
        x /= 10;
        wei++;
    }
    return wei;
}
void solve()
{
    /*
    int cnt = 0;
    for (int i = 1; i <= 1e8;i++){
        if(digwei(i)&1)continue;
        int t = digwei(i) / 2;
        int ans1 = 0, ans2 = 0;
        int tmp = i;
        for (int j = 1; j <= t;j++){
            ans1 += tmp % 10;
            tmp /= 10;
        }
        for (int j = 1; j <= t;j++){
            ans2 += tmp % 10;
            tmp /= 10;
        }
        if(ans1==ans2){
            cnt++;
        }
    }
    cout << cnt;
    */
    cout << 4430091;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}