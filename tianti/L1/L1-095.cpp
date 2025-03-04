#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int ans = INT_MAX;
void solve(){
    int n0, n1, n;
    cin >> n0 >> n1 >> n;
    int a, b;
    for (int i = 1; i <= n - 1;i++){
        if(n0%i==0&&n1%(n-i)==0&&n1!=n-i&&n0!=i){
            int w = n0 / i, m = n1 / (n - i);
            if(abs(w-m)<ans){
                ans = abs(w - m);
                a = i, b = n - i;
            }
        }
    }
    if(ans==INT_MAX)
        cout << "No Solution";
    else
        cout << a << " " << b;
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