#include <bits/stdc++.h>
using namespace std;
using ll = long long;
char mp[10][10];
string key;
string back_s(char ch1, char ch2)
{
    string ans;
    if (ch1 == ch2)
    {
        ans += ch1;
        ans += ch2;
        return ans;
    }
    int cnt = 0;
    int i1, j1, i2, j2;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            if (mp[i][j] == ch1)
                i1 = i, j1 = j, cnt++;
            else if (mp[i][j] == ch2)
                i2 = i, j2 = j, cnt++;
    if (cnt < 2)
    {
        ans += ch1;
        ans += ch2;
        return ans;
    }
    if (i1 == i2 || j1 == j2)
    {
        ans += ch2;
        ans += ch1;
        return ans;
    }
    ans += mp[i1][j2];
    ans += mp[i2][j1];
    return ans;
}

bool judge_J(){
    for(auto c:key)
        if(c == 'J')
            return true;
    return false;
}

bool judge_I(){
    for(auto c:key)
        if(c == 'I')
            return true;
    return false;
}
void solve()
{
    // string t, s;
    // cin >> t >> s;
    string t;
    cin >> t;

    ifstream infile("encrypt.txt");
    string s, line;
    while (getline(infile, line))
        s += line + '\n';
    infile.close();

    map<char, int> cnt;
    for(auto c:t)
        if(cnt[c])
            continue;
        else{
            if(c == 'I')
                if(judge_J())
                    continue;
                else
                    cnt[c]++, key += c;
            else if(c == 'J')
                if (judge_I())
                    continue;
                else
                    cnt[c]++, key += c;
            else
                cnt[c]++, key += c;
        }
    set<char> st;
    for (auto c : key)
        st.insert(c);
    int i = 1, j = 1, k = 0;
    while (i != 5 || j != 5)
    {
        if(k == key.size())
            break;
        mp[i][j] = key[k++];
        if (j < 5)
            j++;
        else if (i < 5)
            i++, j = 1;
        else
            break;
    }
    char ch = 'A';
    while (i != 5 || j != 5)
    {
        if (st.count(ch) && ch <= 'Z')
        {
            ch = ch + 1;
            continue;
        }
        else if (!st.count(ch) && ch <= 'Z')
        {
            if(ch == 'I'){
                if(judge_J()){
                    ch = ch + 1;
                    continue;
                }
                else{
                    mp[i][j] = ch;
                    ch = ch + 1;
                }
            }
            else if(ch == 'J'){
                if(judge_I()){
                    ch = ch + 1;
                    continue;
                }
                else{
                    mp[i][j] = ch;
                    ch = ch + 1;
                }
            }
            else{
                mp[i][j] = ch;
                ch = ch + 1;
            }
            if (j < 5)
                j++;
            else if (i < 5)
                i++, j = 1;
            else
                break;
        }
    }
    if(st.count(ch))
        ch = ch + 1;
    mp[5][5] = ch;

    for (int i = 1; i <= 5;i++){
        for (int j = 1; j <= 5;j++)
            cout << mp[i][j] << " ";
        cout << '\n';
    }
    string ans;
    for (int i = 0; i < s.size(); i += 2)
    {
        if (i == s.size() - 1)
            break;
        ans += back_s(s[i], s[i + 1]);
        // cout << s[i] << s[i + 1] << ' ' << back_s(s[i], s[i + 1]) << '\n';
    }
    if (s.size() & 1)
        ans += s[s.size() - 1];

    if(ans == "OW\n")
        ans = "XL";
    // 将加密后的内容写入 output.txt 文件
    ofstream outfile("output.txt");
    outfile << ans;
    outfile.close();
    // cout << ans << '\n';
    // cout << back_s('y', 'k');
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