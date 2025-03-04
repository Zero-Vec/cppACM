#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
1.两边的字符不能修改
2.相邻字符最多改一个
3.我们修改的字符都不相邻
4.修改的字符位置互不影响，所以当修改位置确定后，我们可以人为规定一个修改顺序，答案是不变的
*/
//证明贪心在这题适用：修改一次只能改一个字符，那么如果一个串T和S有cnt个位置不同，我们至少需要改cnt次
//而按照我们从左到右的修改策略，一共也只修改了cnt次。
void solve(){
    string t, s;
    cin >> t >> s;
    bool tag = 1;
    int ans = 0;
    for (int i = 0; i < t.size();i++){
        if((i==0)&&(s[i]!=t[i])||(i==t.size()-1)&&(s[i]!=t[i])){
            tag = 0;
            break;
        }
        if(s[i]==t[i])continue;
        else{
            if(s[i-1]==s[i+1]&&s[i-1]!=s[i]){
                ans++;
                s[i] = t[i];
            }
            else{
                tag = 0;
                break;
            }
        }
    }
    cout << (tag ? ans : -1) << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)
        solve();
    return 0;
}