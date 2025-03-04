#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, sum[25][5];
int cnt[5] = {0, 2, 6, 10, 14};
char ch[10] = "#spdf";
void f(int x,int i,int j){
    sum[i][j] = min(cnt[j], x);
    int y = x - cnt[j];
    if(y<=0)
        return;
    if(j==1){
        j = i / 2 + 1;
        i = (i + 1) / 2 + 1;
    }
    else
        i++, j--;
    f(y, i, j);
}
void solve(){
    cin >> n;
    f(n, 1, 1);
    for (int i = 1;;i++,cout<<'\n'){
        for (int j = 1; j <= 4;j++){
            if(!sum[i][1])
                return;
            if(sum[i][j])
                cout << i << ch[j] << sum[i][j] << ' ';
        }
    }
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