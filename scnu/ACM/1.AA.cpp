#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int a[N], b[N];
int q, n;
map<int, int> m1, m2;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        if(!m1[i]){
            m1[i] += m1.size();
            m1[i]++;
        }
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        if (!m2[i]){
            m2[i] += m2.size();
            m2[i]++;
        }
    }
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        if(m1[x]==m2[y]){
            cout << "Yes" << '\n';
        }
        else{
            cout << "No" << '\n';
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