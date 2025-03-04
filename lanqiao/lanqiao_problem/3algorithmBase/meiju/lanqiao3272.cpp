#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N], b[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, k;
    cin >> t;
    while(t--){
        int ans = 100000;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int j = 1; j <= 60;j++){
            int cnt = 0;
            for (int i = 1; i <= n;i++)
                b[i] = a[i];
            for (int i = 1; i <= n;i++){
                if(b[i]!=j){
                    for (int p = i; p < i + k;p++)
                        b[p] = j;
                    cnt++;
                    i += k - 1;
                }
            }
            ans = min(ans, cnt);
        }
        cout << ans << '\n';
    }
    return 0;
}