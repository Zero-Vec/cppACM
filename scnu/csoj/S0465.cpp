#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> a;
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int k;
        cin >> k;
        int pos = upper_bound(a.begin(), a.end(), k) - a.begin();
        cout << pos << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        int pos = upper_bound(a, a + 1 + n, k) - a ;
        cout << pos - 1 << '\n';
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