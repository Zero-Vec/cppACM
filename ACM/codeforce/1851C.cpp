// https://codeforces.com/problemset/problem/1851/C
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=2e5+9;
int c[N], n, k;
void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        cin >> c[i];
    int cnt = 0;
    for (int i = 2; i < n;i++){
        if(c[i]==c[1])
            cnt++;
    }
    if(c[1]==c[n]){
        cout << (cnt >= k - 2 ? "YES" : "NO") << '\n';
    }
    else{
        int id = 0, gs = 0;
        bool tag1 = 0, tag2 = 0;
        for (int i = 2; i <= n;i++){
            if (gs == k - 1){
                id = i;
                gs = 0;
                tag1 = 1;
                break;
            }
            if(c[i]==c[1])
                gs++;
        }
        for (int i = id; i <= n;i++){
            if (gs == k - 1){
                tag2 = 1;
                break;
            }
            if(c[i]==c[n]){
                gs++;
            }
        }
        cout << (tag1 && tag2 ? "YES" : "NO") << "\n";
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
/*
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;

int c[N];

void solve()
{
    int n, k;cin >> n >> k;
    for(int i = 1;i <= n; ++ i)cin >> c[i];

    if(c[1] == c[n])
    {
        int cnt = 0;
        for(int i = 2;i <= n - 1; ++ i)if(c[i] == c[1])cnt ++;
        cout << (cnt >= k - 2 ? "YES" : "NO") << 'n';
    }else
    {
        int L = n, R = 0;
        int kL = 0, kR = 0;
        for(int i = 1;i <= n && kL < k; ++ i)if(c[i] == c[1])kL ++, L = i;
        for(int i = n;i >= 1 && kR < k; -- i)if(c[i] == c[n])kR ++, R = i;
        if(kL == k && kR == k && L < R)cout << "YES" << 'n';
        else cout << "NO" << 'n';
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _;cin >> _;
    while(_ --)solve();
    return 0;
}
*/