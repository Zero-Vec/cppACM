#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt = 0;
ll currentFib, f0, f1=1, n;
set<ll> s;
void f(){
    s.insert(f0);
    s.insert(f1);
    for (int i = 1; i < 1e4; i++)
    {
        currentFib = f0 + f1;
        s.insert(currentFib);
        f0 = f1;
        f1 = currentFib;
    }
}
void solve(){
    int n;
    cin >> n;
    if(s.count(n)){
        cout << n << " " << 0 << " " << 0 << '\n';
        return;
    }
    auto it = s.lower_bound(n);
    it--;
    n -= *it;
    auto it1 = s.lower_bound(n);
    it1--;
    n -= *it1;
    if(!s.count(n)){
        cout << -1 << "\n";
        return;
    }
    cout << *it << ' ' << *it1 << ' ' << n << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    f();
    cin >> t;
    while(t--)
        solve();
    return 0;
}