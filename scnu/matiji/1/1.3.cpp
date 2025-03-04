#include<bits/stdc++.h>
using namespace std;
using ll = long long;
char ma[107][107];
int n, ans;
void solve(){
    cin >> n;
    for (int i = 0; i < n;i++)
        cin >> ma[i];
    int x1, y1, x2, y2;
    for (x1 = 0; x1 < n;x1++)
        for (y1 = 0; y1 < n;y1++)
            for (x2 = 0; x2 <= x1;x2++)
                for (y2 = 0; y2 <= y1;y2++){
                    int x3 = x1 - y1 + x2 + y2, y3 = x1 + y1 - x2 + y2,
                        x4 = x1 + y1 + x2 - y2, y4 = -x1 + y1 + x2 + y2;
                    if(x3&1||x4&1||y3&1||y4&1)continue;
                    x3 /= 2, y3 /= 2, x4 /= 2, y4 /= 2;
                    if(x3<0||x3>=n||x4<0||x4>=n||y3<0||y3>=n||y4<0||y4>=n)continue;
                    int cnt = 0;
                    if(ma[x1][y1]=='B'||ma[x2][y2]=='B'||ma[x3][y3]=='B'||ma[x4][y4]=='B')continue;
                    if(ma[x1][y1]=='J')
                        cnt++;
                    if (ma[x2][y2] == 'J')
                        cnt++;
                    if (ma[x3][y3] == 'J')
                        cnt++;
                    if (ma[x4][y4] == 'J')
                        cnt++;
                    if(cnt>=3)
                        ans = max(ans, (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
                }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}