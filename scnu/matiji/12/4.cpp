#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e6 + 9;
int n, m, A, a[N], b[N], c[N], sumb[N], sumc[N], ans = -0x3f3f3f3f;
void getmax(int n,int m){
    deque<int> q;
    for (int i = 1; i <= n;i++){
        if(!q.empty() && q.front() <= i-m)
            q.pop_front();
        while(!q.empty() && a[i] >= a[q.back()])
            q.pop_back();
        q.push_back(i);
        if(i >= m)
            b[i] = a[q.front()], sumb[i] = sumb[i - 1] + b[i];
    }
}
void getmax2(int n,int m){
    deque<int> q;
    for (int i = 1; i <= n;i++){
        if(!q.empty() && q.front() <= i-m)
            q.pop_front();
        while(!q.empty() && a[i]>=a[q.back()])
            q.pop_back();
        q.push_back(i);
        if(i>=m)
            c[i] = max(A, a[q.front()]), sumc[i] = sumc[i - 1] + c[i];
    }
}
void solve(){
    cin >> n >> m >> A;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    getmax(n, m);
    getmax2(n, m - 1);
    for (int i = 1; i <= n + 1;i++){
        if(i<=m){
            ans = max(ans, sumc[i + m - 2] + sumb[n] - sumb[i + m - 2]);
        }
        else if(i>=n-m+2){
            ans = max(ans, sumb[i - 1] + sumc[n] - sumc[i - 2]);
        }
        else{
            ans = max(ans, sumb[i - 1] + sumc[i + m - 2] - sumc[i - 2] + sumb[n] - sumb[i + m - 2]);
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