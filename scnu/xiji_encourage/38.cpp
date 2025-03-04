#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    int x;
    cin >> x;
    int nmax = 0, amax = 0;
    for (int n = 2; n <= 2 * sqrt(x);n++){
        if((2 * x) % n == 0){
            int b = 2 * x / n - n + 1;
            if (b % 2 == 0 && b > 0){
                int a = b / 2;
                if(n > nmax){
                    nmax = n;
                    amax = a;
                }
            }
        }
    }
    if(!nmax){
        cout << x << ":NOANSWER\n";
    }
    else{
        cout << x << "=";
        for (int i = 0; i < nmax - 1;i++)
            cout << amax + i << "+";
        cout << amax + nmax - 1 << '\n';
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