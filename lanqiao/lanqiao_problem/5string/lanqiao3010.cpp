#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
char s[N];
int nex[N];
// 本题考察对next数组含义的理解
// next[i]表示以第i个字符结尾的字符串的最长相等前后缀的长度
// 本题所求的最长幸运字符串,其长度实际上就是最长相等前后缀的长度
// 如样例 abcdaaaba,观察可得next[9]=2,即子串abcdaaaba的最长相等前后缀(ab)长度为2
// 其恰好是我们所求的最长幸运字符串的长度
// 故本题只需要对输入的字符串求next数组,比较其中的最大值即可
void solve()
{
    int n;
    cin >> n;
    cin >> s + 1;
    int m = strlen(s + 1);
    nex[0] = nex[1] = 0;
    for (int i = 2, j = 0; i <= m; i++){
        while (j && s[i] != s[j + 1])
            j = nex[j];
        if (s[i] == s[j + 1])
            j++;
        nex[i] = j;
    }
    /*
    for (int i = 1; i <= m; i++){
        cout << nex[i] << '\n';
    }
    */
    int ans = 0;
    for (int i = 1; i <= m;i++){
        ans = max(ans, nex[i]);
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
