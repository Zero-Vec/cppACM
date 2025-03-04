#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    ll x, a, b;
    cin >> x;
    b = x / 2;
    a = b * 3;
    if (a + b == 2 * (a ^ b))
        cout << a << ' ' << b << '\n';
    else
        cout << -1 << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll x, a, b;
    cin >> x;
    b = x / 2;
    a = b * 3;
    bool tag = true;
    int c = 0;
    for (int i = 0; i < 64;i++){
        if((x>>i)&1){
            c++;
        }
        else{
            c = 0;
        }
        if(c>=2)
            tag = false;
    }
    if(!tag){
        cout << -1 << '\n';
    }
    else{
        cout << a << " " << b << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
*/