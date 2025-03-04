#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
char s[N];
int nex[N];
int dp[N]; 
// dp[i]表示截止到第i个位置,出现的前缀字符串的总数
// dp[ nex[i] ] = dp[ nex[i] ] + dp[i]
void solve(){
    int n;
    cin >> n;
    cin >> s + 1;
    for (int i = 2, j = 0; i <= n;i++){
        while(j&&s[i]!=s[j+1])j=nex[j];
        if(s[i]==s[j+1])j++;
        nex[i] = j;
    }
    for (int i = 1; i <= n;i++)dp[i]=1;
    for (int i = n; i >= 1;i--)dp[nex[i]]+=dp[i];
    ll ans = 0;
    for (int i = 1; i <= n;i++)ans+=dp[i];
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
// 附:本题错误解法
// 求出next数组后遍历next数组,若不为0则ans+2,若为0则ans+1
// 此种解法可以通过前面19个测试点,但无法通过最后一个测试点
// 此解法的bug在于next数组记录的是最长前缀,可能忽略一些被最长前缀包含的前缀
// 如对于样例abcabca,next数组为0 0 0 1 2 3 4,此解法得到答案11,但正确答案为12
// 错误之处在于,对于前缀a,其出现了3次,但只有nex[4]记录了前缀a出现的次数,只加了2次
// 实际上abca同样也包含了a,但是被忽略了
