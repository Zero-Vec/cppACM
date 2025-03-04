#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int a[N], t[N];
int n, m;
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    while(m--){
        int op;
        cin >> op;
        if(op==1){
            int x, y;
            cin >> x >> y;
            t[x] += y;
        }
        else{
            int i;
            cin >> i;
            int ans = a[i];
            for (int j = 1; j <= sqrt(i);j++){
                if(i%j==0){
                    if(j*j==i)
                        ans += t[j];
                    else
                        ans += t[j] + t[i / j];
                }
            }
            cout << ans << '\n';
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
/*
暴力居然也能过。。。
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int a[N];
int n, m;
void solve(){
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    while(m--){
        int op, x, y;
        cin>>op;
        if(op==1){
            cin >> x >> y;
            for (int i = x; i <= n;i+=x){
                a[i] += y;
            }
        }
        else{
            cin >> x;
            cout << a[x] << '\n';
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
*/