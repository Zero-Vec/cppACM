#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
char s[N];
int p[N];
void solve(){
    cin >> s + 1;
    int n = strlen(s + 1);
    s[0] = '!', s[2 * n + 2] = '(';
    for (int i = 2*n+1; i>=1;i--){
        if(i&1)s[i]='#';
        else    s[i]=s[i/2];
    }
    //求最长回文子串 O(n)算法
    int c =0, r = 0;//分别表示最长回文区间的中心的右端点
    for (int i = 1; i <= 2 * n + 1;i++){
        if(i<r){
            p[i] = min(r - i, p[2 * c - i]);
        }
        else    p[i]=1;
        while(s[i+p[i]]==s[i-p[i]])p[i]++;
        if(i+p[i]>r){
            c = i, r = i + p[i];
        }
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n + 1;i++){
        ans = max(ans, p[i] - 1);
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