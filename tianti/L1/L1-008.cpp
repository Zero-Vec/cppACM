#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int ans, a, b,cnt;
void solve(){
    cin >> a >> b;
    for (int i = a; i <= b;i++){
        ans += i;
        if(cnt==5){
            cout << "\n";
            cnt = 0;
        }
        cnt++;
        cout << right << setw(5) << i;
    }
    cout << "\n";
    cout << "Sum = " << ans;
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