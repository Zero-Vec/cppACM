#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    if(k==a||k==b||k==c){
        cout << 0 << "\n";
    }
    else{
        if(k>2){
            cout << -1 << '\n';
        }
        else{
            if(k==0){
                cout << 1 << '\n';
            }
            else if(k==1){
                if(a==0||b==0||c==0){
                    cout << 1 << '\n';
                }
                else{
                    cout << 2 << '\n';
                }
            }
            else{
                set<ll> s;
                s.insert(a), s.insert(b), s.insert(c);
                if(s.count(0)&&s.count(1)){
                    cout << 1 << '\n';
                }
                else if(s.count(0)||s.count(1)){
                    cout << 2 << '\n';
                }
                else{
                    cout << 3 << '\n';
                }
            }
        }
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