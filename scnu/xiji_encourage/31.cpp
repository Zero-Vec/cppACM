#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(int x){
    int sum = 0, t = x;
    while(t){
        int y = t % 10;
        t /= 10;
        sum += y * y * y;
    }
    return sum == x;
}
void solve(){
    int a, b;
    cin >> a >> b;
    if(a > b || a <= 0 || b <= 0){
        cout << "error\n";
        return;
    }
    bool tag = false;
    for (int i = a; i <= b;i++)
        if(check(i)){
            cout << i << '\n';
            tag = true;
        }
    if(!tag)
        cout << "no\n";
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