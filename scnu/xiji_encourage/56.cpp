#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int key;
    cin >> key;
    cin.ignore(); 

    ifstream infile("in.txt");
    string s, line;
    while (getline(infile, line))
        s += line + '\n';
    infile.close();

    string ans;
    for (char c : s){
        if (isupper(c))
            ans += 'A' + (c - 'A' + key) % 26;
        else if (islower(c))
            ans += 'a' + (c - 'a' + key) % 26;
        else
            ans += c;
    }
    ofstream outfile("out.txt");
    outfile << ans;
    outfile.close();
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve(); // 调用solve函数进行处理
    return 0;
}
