// https://ac.nowcoder.com/acm/contest/73854
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void solve(){
    string s, op;
    int n, k;
    cin >> n >> k;
    cin >> s;
    int cnt = s.find('I');
    int l = cnt - 1, r = cnt + 1;
    while(k--){
        cin >> op;
        if(op[0]=='b'){
            if(l>=0&&r<n&&s[l]=='('&&s[r]==')')
                l--, r++;
            else if(l>=0)
                l--;
        }
        else{
            if(r<n)
                r++;
        }
    }
    for (int i = 0; i <= l;i++)
        cout << s[i];
    cout << s[cnt];
    for (int i = r; i < n;i++)
        cout << s[i];
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
/*
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s, op;
void solve()
{
    int n, k;
    cin >> n >> k;
    cin >> s;
    int cnt = s.find('I');
    while (k--)
    {
        cin >> op;
        if (op[0] == 'b')
        {
            if (cnt - 1 >= 0 && cnt + 1 < n && s[cnt - 1] == '(' && s[cnt + 1] == ')')
            {
                s.erase(cnt - 1, 1);
                cnt--, n--;
                s.erase(cnt + 1, 1);
                n--;
            }
            else if (cnt - 1 >= 0)
            {
                s.erase(cnt - 1, 1);
                cnt--, n--;
            }
        }
        else
        {
            if (cnt + 1 < n)
            {
                s.erase(cnt + 1, 1);
                n--;
            }
        }
    }
    cout << s << "\n";
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
*/