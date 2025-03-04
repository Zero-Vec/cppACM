#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int a[N], b[N], n;
int fight(int a[],int b[]){
    int ans = 0;
    int al = 1, ar = n, bl = 1, br = n;
    while(al<=ar){
        if(a[al]>b[bl]){
            ans += 2, al++, bl++;
        }
        else if(a[ar]>b[br]){
            ans += 2, ar--, br--;
        }
        else if(a[al]<=b[bl]){
            ans += (a[al] == b[br]);
            al++, br--;
        }
    }
    return ans;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    cout << fight(a, b) << " " << 2 * n - fight(b, a);
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