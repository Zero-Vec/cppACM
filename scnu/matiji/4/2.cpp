#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int steps(int n){
    if(!n)
        return 0;
    if(n&1)
        return steps(n - 1) + 1;
    else
        return steps(n / 2) + 1;
}
void solve(){
    int n;
    cin >> n;
    cout << steps(n);
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