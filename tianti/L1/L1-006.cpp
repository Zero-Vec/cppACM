#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, first;
int ans;
void solve(){
    cin >> n;
    for (int i = 2; i <= sqrt(n)+1;i++){
        int j;
        ll temp = 1;
        for (j = i; j <= sqrt(n)+1;j++){
            temp *= j;
            if(n%temp!=0)
                break;
        }
        if(j-i>ans){
            first = i;
            ans = j - i;
        }
    }
    if(!first)cout<<1<<'\n'<<n;
    else{
        cout << ans << '\n';
        for (int i = first; i < first + ans;i++){
            if(i==first)
                cout << i;
            else
                cout << "*" << i;
        }
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