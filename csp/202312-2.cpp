#include<bits/stdc++.h>
using namespace std;
using ll = long long;
set<int>s;
bool judge(int x){
    if(x==2)
        return true;
    for (int i = 2; i <= sqrt(x);i++)
        if(x%i==0)
            return false;
    return true;
}
void sushu(){
    for (int i = 2; i <= 1e5;i++)
        if(judge(i))
            s.insert(i);
}
void solve(){
    ll n, k;
    cin >> n >> k;
    ll ans = 1;
    for (int i = 2; i <= sqrt(n);i++){
        int cnt = 0;
        while(n%i==0){
            cnt++, n /= i;
        }
        if(cnt>=k)
            ans *= pow(i, cnt);
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    sushu();
    while(t--)
        solve();
    return 0;
}