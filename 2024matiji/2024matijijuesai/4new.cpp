#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e5 + 9;
bool v[N];
int a[N];//-1表示左,1表示右
void solve(){
    int n, m;
    cin >> n >> m;
    int l = 0, r = 0;
    while(m--){
        int x, y;
        cin >> x >> y;
        if (v[x] && v[y])
            continue;
        if(v[x]){
            v[y] = 1;
            if(a[x]==1){
                a[y] = 1;
                r++;
            }
            else{
                a[y] = -1;
                l++;
            }
        }
        else if(v[y]){
            v[x] = 1;
            if(a[y]==1){
                a[x] = 1;
                r++;
            }
            else{
                a[x] = -1;
                l++;
            }
        }
        else{
            if(l<=r){
                l += 2;
                v[x] = v[y] = 1;
                a[x] = a[y] = -1;
            }
            else{
                r += 2;
                v[x] = v[y] = 1;
                a[x] = a[y] = 1;
            }
        }
    }
    for (int i = 1; i <= n;i++){
        if(!v[i]){
            if(l<=r){
                l++;
            }
            else{
                r++;
            }
        }
    }
    //cout << l << " " << r << '\n';
    cout << 1ll * r * l;
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