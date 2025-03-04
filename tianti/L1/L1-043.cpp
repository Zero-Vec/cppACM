#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e3 + 9;
bool v[N];
int h[N], m[N];
void solve(){
    memset(v, 0, sizeof v);
    memset(h, 0, sizeof h);
    memset(m, 0, sizeof m);
    int book;
    char op;
    string s;
    int cnt = 0, ans = 0;
    while(cin>>book){
        cin >> op >> s;
        if(!book)
            break;
        string t1 = s.substr(0, 2);
        string t2 = s.substr(3, 2);
        int h1 = stoi(t1), m1 = stoi(t2);
        if(op=='S'){
            v[book] = 1, h[book] = h1, m[book] = m1;
        }
        else{
            if(!v[book])continue;
            cnt++;
            ans += 60 * (h1 - h[book]) + m1 - m[book];
            v[book] = 0;
        }
    }
    if(!cnt){
        cout << 0 << ' ' << 0 << '\n';
        return;
    }
    double ans1 = 1.0 * ans / cnt;
    ans /= cnt;
    if(ans1-ans>=0.5)
        ans++;
    cout << cnt << ' ' << ans << '\n';
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