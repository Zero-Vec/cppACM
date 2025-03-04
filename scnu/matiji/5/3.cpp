#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 7;
int t, k, a[N], b[N], c[N][2], l, r, mid, ans;
bool check(int p){
    int curr = 1;
    memset(b, 0, sizeof b);
    for (int i = 1; i <= t;i++){
        if(b[curr]+a[i]>p){
            curr++;
            b[curr] += a[i];
        }else{
            b[curr] += a[i];
        }
    }
    if(curr>k)
        return false;
    return true;
}
void print(int p){
    int curr = k, temp = 0;
    for (int i = t; i > 0;i--){
        if(!c[curr][1])
            c[curr][1] = i;
        if(temp+a[i]>p){
            c[curr][0] = i + 1;
            curr--;
            temp = a[i];
            c[curr][1] = i;
        }
        else
            temp += a[i];
    }
    c[curr][0] = 1;
    for (int i = 1; i <= k;i++){
        if(c[i][0]==0)
            cout << 0 << " " << 0 << '\n';
        else
            cout << c[i][0] << " " << c[i][1] << '\n';
    }
}
void solve(){
    l = -1;
    cin >> t >> k;
    for (int i = 1; i <= t;i++){
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }
    while(l<=r){
        mid = l + (r - l) / 2;
        if(check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    print(ans);
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