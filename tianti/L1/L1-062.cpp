#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int n;
    cin>>n;
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= 3;i++){
        s1 += n % 10;
        n /= 10;
    }
    for (int i = 1; i <= 3;i++){
        s2 += n % 10;
        n /= 10;
    }
    cout << (s1 == s2 ? "You are lucky!\n" : "Wish you good luck.\n");
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