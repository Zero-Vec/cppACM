#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    if(r < L||R < l){
        cout << 1 << '\n';
    }
    else if(r == L || R == l){
        cout << 2 << '\n';
    }
    else if(l>=L&&R>=r){
        cout << r - l + 2 - (r == R) - (l == L) << '\n';
    }
    else if(L>=l&&r>=R){
        cout << R - L + 2 - (r == R) - (l == L) << '\n';
    }
    else if(l<L&&r>L){
        cout << r - L + 2 << '\n';
    }
    else if(r>R&&l<R){
        cout << R - l + 2 << '\n';
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