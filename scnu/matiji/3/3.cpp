#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int ans = 0;
int num[4], w, h;
/*
长：3a+b+c，宽：b+c
长：2a+2b，宽：2a+c
长：2a+2b，宽：2b+c
长：2a+2b，宽：a+b+c
长：a+b+2c，宽：a+b+c
*/
bool work(int a,int b,int c,int x,int y){
    if(x>=3*a+b+c&&y>=b+c)
        return true;
    if (x >= 2 * a + 2 * b && y >= 2 * a + c)
        return true;
    if (x >= 2 * a + 2 * b && y >= 2 * b + c)
        return true;
    if (x >= 2 * a + 2 * b && y >= a + b + c)
        return true;
    if (x >= a + b + 2 * c && y >= a + b + c)
        return true;
    return false;
}
void solve(){
    cin >> w >> h;
    for (int i = 1; i <= 3;i++)
        for (int j = 1; j <= 3;j++){
            if(i==j)continue;
            for (int k = 1; k <= 3;k++){
                if(i==k||j==k)continue;
                if(work(num[i],num[j],num[k],w,h)){
                    ans++;
                    return;
                }
                if (work(num[i], num[j], num[k], h, w)){
                    ans++;
                    return;
                }
            }
        }
    return;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t >> num[1] >> num[2] >> num[3];
    while(t--)
        solve();
    cout << ans;
    return 0;
}