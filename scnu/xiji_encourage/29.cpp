#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int new_num(int x){
    int ans = 0;
    while(x){
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}
bool check(int x){
    if(x <= 1)
        return false;
    if(x == 2)
        return true;
    for (int i = 2; i <= x / i;i++)
        if(x % i == 0)
            return false;
    return true;
}
bool absolute(int x){
    return check(x) && check(new_num(x));
}
void solve(){
    int a,b;
    cin >> a >> b;
    for (int i = a; i <= b;i++)
        if(absolute(i))
            cout << i << "\n";
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