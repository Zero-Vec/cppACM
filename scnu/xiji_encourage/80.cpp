#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool judge(char a, char b){
    return tolower(a) == tolower(b);
}

bool ch_is_in_set(char ch, const vector<char> &set){
    for (char s : set)
        if (judge(ch, s))
            return true;
    return false;
}

void solve(const string &s, vector<char> &A, vector<char> &B, bool &tag)
{
    int start = s.find('[');
    int end = s.find(']');

    if (start != string::npos && end != string::npos && start < end){
        for (int i = 0; i < start; ++i)
            A.push_back(s[i]);
        A.push_back('?');
        for (int i = end + 1; i < s.length(); ++i)
            A.push_back(s[i]);

        for (int i = start + 1; i < end; ++i)
            if (s[i] == '^' && i == start + 1)
                tag = true;
            else
                B.push_back(s[i]);
    }
    else{
        for (char ch : s)
            A.push_back(ch);
        tag = false;
    }
}

// 匹配逻辑
vector<string> match(const string &line, const vector<char> &A, const vector<char> &B, bool tag)
{
    vector<string> matches;
    int n = line.length(), m = A.size();
    if (n < m)
        return matches;
    string lineLower = line;
    transform(lineLower.begin(), lineLower.end(), lineLower.begin(), ::tolower);
    for (int i = 0; i <= n - m; ++i){
        bool flag = true;
        for (int j = 0; j < m; ++j){
            char ch = lineLower[i + j];
            if (A[j] == '?'){
                if ((tag && ch_is_in_set(ch, B)) || (!tag && !ch_is_in_set(ch, B))) {
                    flag = false;
                    break;
                }
            }
            else if (!judge(A[j], ch)){
                flag = false;
                break;
            }
        }
        if (flag)
            matches.push_back(line.substr(i, m));
    }
    return matches;
}

int main()
{
    string key;
    cin >> key;
    vector<char> A, B;
    bool tag = false;
    solve(key, A, B, tag);
    ifstream infile("string.in");
    ofstream outfile("string.out");
    string line;
    int lineNum = 0;
    const int MAX_LINES = 100000;
    while (getline(infile, line))
    {
        ++lineNum;
        vector<string> matches = match(line, A, B, tag);
        if (!matches.empty()){
            outfile << lineNum << ":";
            for (int i = 0; i < matches.size(); ++i){
                if (i > 0)
                    outfile << ",";
                outfile << matches[i];
            }
            outfile << endl;
        }
    }
    infile.close();
    outfile.close();
    return 0;
}
