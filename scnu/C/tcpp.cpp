#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    // char a[200];
    // cin.getline(a, 200,'');
    // cout << a;

    int a;
    int *pa = &a;
    cout << pa << '\n';
    cout << (char *)pa << '\n';
    cout << (void *)pa << '\n';
    cout << (int *)pa;
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