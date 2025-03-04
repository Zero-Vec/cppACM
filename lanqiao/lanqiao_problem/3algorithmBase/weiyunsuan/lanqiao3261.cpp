#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string change(int num){
    string ans;
    while(num){
        if(num&1)
            break;
        num >>= 1;
    }
    while(num){
        ans += (num & 1 ? '1' : '0');
        num >>= 1;
    }
    return ans;
}
void solve(){
    int a,b;
    cin >> a >> b;
    string sa = change(a), sb = change(b);
    if(sa.find(sb)!=-1){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
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