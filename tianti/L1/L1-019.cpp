#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
int a1[N], a2[N], b1[N], b2[N];
void solve(){
    int x,y;
    cin >> x >> y;
    int n;
    cin >> n;
    int t1 = x, t2 = y;
    char ans;
    for (int i = 1;i<=n;i++)
        cin >> a1[i] >> a2[i] >> b1[i] >> b2[i];
    for (int i = 1; i <= n;i++){
        int sum = a1[i] + b1[i];
        if(sum==a2[i]&&sum!=b2[i]){
            x -= 1;
        }
        else if (sum == b2[i] && sum != a2[i]){
            y -= 1;
        }
        else    continue;
        if(x<0){ans='A';break;}
        if(y<0){ans='B';break;}
    }
    if(ans=='A'){
        cout<<ans<<'\n'<<t2-y;
    }
    else{
        cout<<ans<<'\n'<<t1-x;
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