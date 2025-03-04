#include<bits/stdc++.h>
using namespace std;
using ll = long long;
char mp[10][10];
string back_s(char ch1,char ch2){
    string ans;
    if(ch1 == ch2){
        ans += ch1;
        ans += ch2;
        return ans;
    }
    int cnt = 0;
    int i1, j1, i2, j2;
    for (int i = 1; i <= 5;i++)
        for (int j = 1; j <= 5;j++)
            if(mp[i][j] == ch1)
                i1 = i, j1 = j, cnt++;
            else if(mp[i][j] == ch2)
                i2 = i, j2 = j, cnt++;
    if(cnt < 2){
        ans += ch1;
        ans += ch2;
        return ans;
    }
    if(i1 == i2 || j1 == j2){
        ans += ch2;
        ans += ch1;
        return ans;
    }
    ans += mp[i1][j2];
    ans += mp[i2][j1];
    return ans;
}
void solve(){
    string key, s;
    cin >> key >> s;
    set<char> st;
    for(auto c:key)
        st.insert(c);
    int i = 1, j = 1, k = 0;
    char ch = 'a';
    while(i != 5 || j != 5){
        if(st.count(ch) && ch <= 'z'){
            ch = ch + 1;
            continue;
        }
        else if(!st.count(ch) && ch <= 'z'){
            mp[i][j] = ch;
            ch = ch + 1;
            if(j < 5)
                j++;
            else if(i < 5)
                i++, j = 1;
            else
                break;
        }
        else{
            while(i != 5 || j != 5){
                mp[i][j] = key[k++];
                if (j < 5)
                    j++;
                else if (i < 5)
                    i++, j = 1;
                else
                    break;
            }
        }
    }
    mp[5][5] = key[k];
    // cout << i << '\n'
    //      << j << '\n'
    //      << ch << '\n'
    //      << k << '\n';
    // for (int i = 1; i <= 5;i++){
    //     for (int j = 1; j <= 5;j++)
    //         cout << a[i][j] << " ";
    //     cout << '\n';
    // }
    string ans;
    for (int i = 0; i < s.size();i += 2){
        if(i == s.size() - 1)
            break;
        ans += back_s(s[i], s[i + 1]);
        // cout << s[i] << s[i + 1] << ' ' << back_s(s[i], s[i + 1]) << '\n';
    }
    if(s.size() & 1)
        ans += s[s.size() - 1];
    cout << ans << '\n';
    // cout << back_s('y', 'k');
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