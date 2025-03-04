#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e5+9;
struct node{
    char ch;
    int id;
    bool operator<(const node& u)const{
        return ch == u.ch ? id < u.id : ch < u.ch;
    }
} d[N];
int n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> d[i].id;
    for (int i = 1; i <= n;i++)
        cin >> d[i].ch;
    sort(d+1,d+1+n);
    bool ok = true;
    for (int i = 1; i <= n;i++){
        if(d[i].ch=='B'){
            if(d[i].id<i){
                ok = false;
                break;
            }
        }
        else{
            if(d[i].id>i){
                ok=false;
                break;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
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