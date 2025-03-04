#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int x, y, z, w;
    cin >> x >> y >> z >> w;
    int cnt = 0;
    if(!x)
        cnt++;
    if(!y)
        cnt++;
    if(!z)
        cnt++;
    if(!w)
        cnt++;
    if(cnt==3){
        cout << -1;
        return;
    }
    if(x==0&&z==0){
        cout << y / w;
        return;
    }
    if(y==0&&w==0){
        cout << x / z;
        return;
    }
    if(z==0||w==0||x==0||y==0){
        cout << -1;
        return;
    }
    if(x/z==y/w&&x%z==0){
        cout << x / z;
    }
    else{
        cout << -1;
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