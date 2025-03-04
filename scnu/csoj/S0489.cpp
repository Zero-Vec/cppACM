#include<bits/stdc++.h>
using namespace std;
using ll = long long;
set<int> S;
/*
void process(ll x){
    ll t = x;
    for (int i = 2; i <= t;i++){
        while(x%i==0){
            S.insert(i);
            x /= i;
        }
    }
}
*/
void divide(int x){
    for (int i = 2; i <= x / i;i++){
        if(x%i==0){
            while(x%i==0)
                x /= i;
            S.insert(i);
        }
    }
    if(x>1)
        S.insert(x);
}

int gcd(int a,int b){
    return !b ? a : gcd(b, a % b);
}
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        int a, b;
        cin >> a >> b;
        int g = gcd(a, b);
        b /= g;
        //process(b);
        divide(b);
    }
    ll res = 1;
    for(auto i:S){
        res *= i;
        //cout << i << '\n';
    }
    string ch = "0123456789ABCDEF";
    string ans;
    while(res){
        ans+=ch[res%16];
        res /= 16;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
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