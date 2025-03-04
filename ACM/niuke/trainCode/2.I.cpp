#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
long long a[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n;i++){
            cin >> a[i];
        }
        sort(a + 1, a + 1 + n);
        long long ans = 0;
        for (int i = 2; i <= n;i++){
            ans += 2 * a[i] * (i - 1);
        }
        cout << 2 * ans << "\n";
    }
    return 0;
}