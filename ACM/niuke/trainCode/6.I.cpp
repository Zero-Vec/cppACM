#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
ll dpa1[N], dpa2[N], dpb1[N], dpb2[N];
ll a[N], b[N];
ll amax = -1e9 - 3, bmax = -1e9 - 3, amin = 1e9 + 3, bmin = 1e9 + 3;
ll almax = -1e9 - 3, blmax = -1e9 - 3, almin = 1e9 + 3, blmin = 1e9 + 3;
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i]<0&&a[i]>amax)
            amax = a[i];
        if(a[i]>=0&&a[i]<amin)
            amin = a[i];
        dpa1[i] = max(dpa1[i - 1] + a[i], a[i]);
        dpa2[i] = min(dpa2[i - 1] + a[i], a[i]);
        almax = max(almax, dpa1[i]);
        almin = min(almin, dpa2[i]);
    }
    for (int i = 1; i <= m;i++){
        cin >> b[i];
        if (b[i] < 0 && b[i] > bmax)
            bmax = b[i];
        if (b[i] >= 0 && b[i] < bmin)
            bmin = b[i];
        dpb1[i] = max(dpb1[i - 1] + b[i], b[i]);
        dpb2[i] = min(dpb2[i - 1] + b[i], b[i]);
        blmax = max(blmax, dpb1[i]);
        blmin = min(blmin, dpb2[i]);
    }
    if(blmax<0){
        if(almin<0)
            cout << almin * blmin;
        else
            cout << bmax * amin;
    }
    else if(blmax>0&&blmin>=0){
        if(almax>0)
            cout << blmax * almax;
        else
            cout << bmin * amax;
    }
    else if(blmax>0&&blmin<0){
        if (almin>=0)
            cout << blmax * almax;
        else if(almax<=0)
            cout << almin * blmin;
        else
            cout << max(almin * blmin, almax * blmax);
    }
    else
        cout << 0;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}