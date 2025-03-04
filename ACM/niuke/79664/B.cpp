#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
int a[N], b[N];
ll m, s;
int n, ans, cnt;
void solve(){
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    priority_queue<int> pq;
    for (int i = 1; i <= n;i++){
        if(b[i]==1){
            if(m-a[i]>=0&&s-a[i]>=0){
                m -= a[i], s -= a[i];
                cnt++;
                pq.push(a[i]);
                ans = max(ans, cnt);
            }
            else{
                if(!pq.size()){
                    ans = max(ans, cnt);
                    continue;
                }
                else{
                    if(a[i]<pq.top()){
                        m += pq.top(), s += pq.top();
                        pq.pop();
                        pq.push(a[i]);
                        m -= a[i], s -= a[i];
                    }
                }
            }
        }
        else if(b[i]==2){
            cnt++;
            m += a[i];
            ans = max(ans, cnt);
        }
        else{
            if (m - a[i] >= 0 && s - a[i] >= 0){
                m -= a[i], s -= a[i];
                cnt++;
                ans = max(ans, cnt);
            }
            else{
                while(pq.size()&&(m-a[i]<0||s-a[i]<0)){
                    int t = pq.top();
                    pq.pop();
                    m += t, s += t;
                    cnt--;
                }
                if(!pq.size()&&(m-a[i]<0||s-a[i]<0))
                    break;
                m -= a[i], s -= a[i], cnt++;
                ans = max(cnt, ans);
            }
        }
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