#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e4 + 9;
int n, m;
ll getsum(int x){
    ll sum = 0;
    for (int i = 1; i < x;i++)
        if(x % i == 0)
            sum += i;
    return sum;
}
ll d[N];
void solve(){
    cin >> m >> n;
    for (int i = m; i <= n;i++)
        d[i] = getsum(i);
    bool tag = false;
    
    for (int i = m; i < n;i++){
        ll t1 = d[i];
        for (int j = i + 1; j <= n;j++){
            ll t2 = d[j];
            if(t1 == j && t2 == i){
                tag = true;
                cout << i << " " << j << '\n';
            }
        }
    }
    if(!tag)
        cout << "NONE\n";
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