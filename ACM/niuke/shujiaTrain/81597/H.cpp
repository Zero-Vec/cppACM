#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> PI;
const int N = 2e5 + 9;
int ph[N], pv[N], n, x, y;
char s[N];
void solve()
{
    cin >> n >> x >> y >> s + 1;
    if(x==0&&y==0){
        cout << 1ll * n * (n + 1) / 2;
        return;
    }
    for (int i = 1; i <= n; i++){
        ph[i] = ph[i - 1], pv[i] = pv[i - 1];
        if (s[i] == 'W')
            ph[i]++;
        else if (s[i] == 'S')
            ph[i]--;
        else if (s[i] == 'D')
            pv[i]++;
        else
            pv[i]--;
    }
    map<PI, int> mp;
    mp[{0, 0}] = 1;
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        int tx = pv[i] - x, ty = ph[i] - y;
        ans += mp[{tx, ty}] * (n - i + 1);
        mp[{tx, ty}] = 0;
        mp[{pv[i], ph[i]}]++;
    }
    cout << ans;
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
/*
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int preh[N], preV[N], n, x, y;
char s[N];
void solve(){
    cin >> n >> x >> y;
    cin >> s + 1;
    int k = abs(x) + abs(y);
    if(x == 0 && y == 0){
        cout << 1ll * n * (n + 1) / 2;
        return;
    }
    for (int i = 1; i <= n;i++){
        if(s[i]=='W')
            preh[i] = preh[i - 1] + 1, preV[i] = preV[i - 1];
        else if(s[i]=='S')
            preh[i] = preh[i - 1] - 1, preV[i] = preV[i - 1];
        else if(s[i]=='D')
            preV[i] = preV[i - 1] + 1, preh[i] = preh[i - 1];
        else
            preV[i] = preV[i - 1] - 1, preh[i] = preh[i - 1];
    }
    for (int i = 1; i <= n;i++){
        cout << preh[i] << " ";
    }
    cout << '\n';
    for (int i = 1; i <= n;i++){
        cout << preV[i] << " ";
    }
    cout << '\n';
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        if(i+k-1<=n){
            int l = i + k - 2, r = n + 1;
            while(l+1!=r){
                int mid = (l + r) >> 1;
                if((preh[mid]-preh[i-1]==y)&&(preV[mid]-preV[i-1]==x))
                    r = mid;
                else
                    l = mid;
            }
            if(l!=n){
                ans += n - r + 1;
                cout << i << " " << r << '\n';
            }
        }
    }
    cout << ans;
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
*/