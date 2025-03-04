#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
set<int> v;
void getnum(ll x){
    while(x){
        if(x % 10 != 0)
            v.insert(x % 10);
        x /= 10;
    }
}
void solve(){
    cin >> n;
    while(true){
        v.clear();
        getnum(n);
        bool tag = true;
        for(auto i:v){
            if(n % i != 0){
                tag = false;
                break;
            }
        }
        if(tag){
            cout << n << '\n';
            break;
        }
        n++;
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