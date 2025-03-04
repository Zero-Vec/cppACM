#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 89;
ll len[N], n, c;
string a = "IAKIOI", b = "WHENWILLSCORLLOFTAIWUCOMEOUT!!!";
void find(ll n,ll c){
    if(n==0){
        cout << a[c - 1];
        return;
    }
    if(n==1){
        cout << b[c - 1];
        return;
    }
    if(c<=len[n-2]){
        find(n - 2, c);
    }
    else{
        find(n - 1, c - len[n - 2]);
    }
}
void solve(){
    cin >> n >> c;
    int siz1 = a.size(), siz2 = b.size();
    len[0] = siz1, len[1] = siz2;
    for (int i = 2; i <= n;i++)
        len[i] = len[i - 1] + len[i - 2];
    find(n, c);
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