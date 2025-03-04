#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int a[N];
int out[N][N * 10];
void solve(){
    int n;
    cin>>n;
    for (int i = 1;i<=n;i++){
        cin >> a[i];
        a[i] *= 10;//学校i的总人数
    }
    memset(out, -1, sizeof out);
    int seat = 1, finSch = 0;
    int cnt = 0;
    while(1){
        bool tag = 0;
        cnt++;
        for (int i = 1; i <= n;i++){
            if(out[i][0]!=1){
                tag = 1;
                if(finSch==n-1){
                    out[i][cnt]=seat;
                    seat += 2;
                    a[i]--;
                }
                else{
                    out[i][cnt]=seat;
                    seat++;
                    a[i]--;
                }
                if (!a[i]){
                    out[i][0] = 1;
                    finSch++;
                }
            }
        }
        if(!tag)
            break;
    }
    for (int i = 1; i <= n;i++){
        cout<<'#'<<i<<'\n';
        for (int j = 1; out[i][j] != -1;j++){
            if(j%10==1)cout<<out[i][j];
            else
                cout << " " << out[i][j];
            if(j%10==0)
                cout << '\n';
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