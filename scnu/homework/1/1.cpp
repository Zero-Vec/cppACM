#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 50;
ll mem[N];
ll dfs(int n){
    if(mem[n]!=-1)
        return mem[n];
    if(n==1||n==2)
        return mem[n] = 1;
    return mem[n] = dfs(n - 1) + dfs(n - 2);
}
void solve(){
    int n;
    cin >> n;
    memset(mem, -1, sizeof mem);
    cout << dfs(n);
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