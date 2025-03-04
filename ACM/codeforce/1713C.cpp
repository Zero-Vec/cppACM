// https://codeforces.com/problemset/problem/1713/C
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n;
int a[N];
bool v[N];
void solve(){
    cin>>n;
    int k = 0;
    while(k*k<n-1)
        k++;
    memset(v, 0, sizeof v);
    for (int i = n - 1; i >= 0;i--){
        while(k*k-i>=n||v[k*k-i]==1)
            k--;
        v[k * k - i] = 1;
        a[i] = k * k - i;
    }
    for (int i = 0; i < n;i++)
        cout << a[i] << ' ';
    cout << '\n';
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