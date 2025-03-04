#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int x1 = n / 2;
    int x2 = n / 2 + 1;
    if(n&1){
        int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
        for (int i = 1; i <= x1; i++)
            n1 += a[i];
        for (int i = x1 + 1; i <= n; i++)
            n2 += a[i];
        for (int i = 1; i <= x2; i++)
            n3 += a[i];
        for (int i = x2 + 1; i <= n; i++)
            n4 += a[i];
        if(n2-n1>n4-n3){
            cout << "Outgoing #: " << x2 << '\n'
                 << "Introverted #: " << x1 << '\n'
                 << "Diff = " << n2 - n1;
        }
        else{
            cout << "Outgoing #: " << x2 << '\n'
                 << "Introverted #: " << x1 << '\n'
                 << "Diff = " << n4 - n3;
        }
    }
    else{
        int n1 = 0, n2 = 0;
        for (int i = 1; i <= x1;i++)
            n1 += a[i];
        for (int i = x1 + 1; i <= n;i++)
            n2 += a[i];
        cout << "Outgoing #: " << x1 << '\n'
             << "Introverted #: " << x1 << '\n'
             << "Diff = " << n2 - n1;
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