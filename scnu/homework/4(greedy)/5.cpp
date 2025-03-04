/*
哈夫曼编码的性质：
哈夫曼编码可能不唯一，但是哈夫曼编码的长度是唯一的。字符串编码成01串后的长度实际上就是其以频率为权值所构成的任意一颗哈夫曼树的带权路径长度。
对于任何一个叶子结点，其编号一定不会成为其他任何一个结点编号的前缀—也就是说，题目中给出需要判断的的每个字符的编码，它不会是其他字符编码的前缀。
*/
//利用以上两个性质判断即可
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 66;
char ch[N];
string s[N];
int x[N];
void solve(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        char ch;
        cin >> ch >> x[i];
        pq.push(x[i]);
    }
    ll ans = 0;
    while(pq.size() > 1){
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        ans += x + y;
        pq.push(x + y);
    }
    int t;
    cin >> t;
    while(t--){
        ll len = 0;
        for (int i = 1; i <= n;i++){
            cin >> ch[i];
            cin >> s[i];
            len += 1ll * x[i] * s[i].size();
        }
        //判断是否满足性质1
        if(len!=ans){
            cout << "No" << '\n';
            continue;
        }
        //判断是否满足性质2
        else{
            bool tag = true;
            for (int i = 1; i < n;i++){
                for (int j = i + 1; j <= n; j++){
                    int siz1 = s[i].size();
                    int siz2 = s[j].size();
                    string s1 = s[i].substr(0, siz2);
                    string s2 = s[j].substr(0, siz1);
                    if(s1==s[j]||s2==s[i]){
                        tag = false;
                        break;
                    }
                }
            }
            cout << (tag ? "Yes\n" : "No\n");
        }
        //cout << len << " " << ans << '\n';
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