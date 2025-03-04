#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string dic_reversed = "abcdefghijklmnopqrstuvwxyz";

void solve()
{
    string key;
    cin >> key;   // 从标准输入读取密钥串
    cin.ignore(); // 忽略换行符

    ifstream infile("encrypt.txt");
    string s, line;
    while (getline(infile, line))
        s += line + '\n';
    infile.close();

    // 去重并构建key
    map<char, int> mp;
    string key_final = "";
    for (auto c : key){
        if (mp[c])
            continue;
        else{
            mp[c]++;
            key_final += c;
        }
    }

    // 生成完整的密钥串
    string dic = dic_reversed;
    reverse(dic_reversed.begin(), dic_reversed.end());
    int cnt = 0;
    while (key_final.size() < 26) {
        if (mp[dic_reversed[cnt]]){
            cnt++;
            continue;
        }
        key_final += dic_reversed[cnt++];
    }

    // 生成替换映射
    map<char, char> res;
    for (int i = 0; i < 26; i++)
        res[dic[i]] = key_final[i];

    // 加密内容
    string ans;
    for (auto c : s){
        if (!isalpha(c))
            ans += c;
        else
            ans += res[c];
    }

    // 将加密后的内容写入 output.txt 文件
    ofstream outfile("output.txt");
    outfile << ans;
    outfile.close();
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    solve(); // 只调用一次solve函数
    return 0;
}
