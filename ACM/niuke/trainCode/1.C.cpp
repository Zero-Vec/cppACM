#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll M;
const int N = 1e5 + 9;
int t[N];
ll prefix[N];
void solve(){
    int n, q, tc;
    cin >> n >> q >> tc;
    for (int i = 1; i <= n;i++){
        cin >> t[i];
    }
    sort(t + 1, t + 1 + n);
    for (int i = 1; i <= n;i++)
        prefix[i] = prefix[i - 1] + t[i];
    while(q--){
        cin >> M;
        if(M/tc>=n)
            cout << tc << "\n";
        else
            cout<<prefix[n-M/tc]+tc<<"\n";
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