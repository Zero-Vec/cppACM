#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 9, K = 1e6 + 9;
ll s[N], n, k;
bool v[K];
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> s[i];
    sort(s + 1, s + 1 + n);
    for (int i = 1; i < n;i++)
        for (int j = i + 1; j <= n; j++)
            v[(s[j] - s[i])] = true;
    // 枚举答案
    for (int i = n; i <= K; i++){
        bool tag = false;
        if(!v[i]){
            tag = true;
            for (int j = 2 * i; j <= K;j+=i)
                if(v[j]){
                    tag = false;
                    break;
                }
        }
        if(tag){
            cout << i << '\n';
            return;
        }
    }
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