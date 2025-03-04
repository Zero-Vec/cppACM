#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool judge(int x){
    if(x==2)
        return 1;
    if(x==1)
        return 0;
    for (int i = 2; i <= sqrt(x);i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int x;
        cin >> x;
        cout << (judge(x) ? "Yes\n" : "No\n");
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