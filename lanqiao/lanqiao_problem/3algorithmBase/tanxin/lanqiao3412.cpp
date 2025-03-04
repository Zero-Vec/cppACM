#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int w[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> w[i];
    sort(w + 1, w + 1 + n);
    int ans = w[2] - w[1];
    for (int i = 1; i < n;i++){
        ans = min(ans, abs(w[i + 1] - w[i]));
    }
    cout << ans;
    return 0;
}