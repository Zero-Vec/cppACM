#include<bits/stdc++.h>
using namespace std;

// 提取变量名的函数
vector<string> get_vars(const string &definition)
{
    vector<string> vars;
    stringstream ss(definition);
    string type, word;
    ss >> type;
    while (getline(ss, word, ','))
    {
        int s = word.find_first_not_of(" \t");
        int e = word.find_last_not_of(" \t;,");
        if (s != string::npos && e != string::npos)
            vars.push_back(word.substr(s, e - s + 1));
    }
    return vars;
}

unordered_set<string> find_var(const vector<string> &defined_vars, const string &sta)
{
    unordered_set<string> used_vars;
    int pos = 0;
    while (pos < sta.size())
    {
        if (isalpha(sta[pos]) || sta[pos] == '_')
        {
            int s = pos;
            while (pos < sta.size() && (isalnum(sta[pos]) || sta[pos] == '_'))
            {
                pos++;
            }
            string variable = sta.substr(s, pos - s);
            if (find(defined_vars.begin(), defined_vars.end(), variable) != defined_vars.end())
                used_vars.insert(variable);
        }
        else
            pos++;
    }
    return used_vars;
}

int main()
{
    string d, s;
    getline(cin, d);
    getline(cin, s);
    vector<string> defined_vars = get_vars(d);
    unordered_set<string> used_vars = find_var(defined_vars, s);
    bool first = true;
    for (const string &var : defined_vars)
    {
        if (used_vars.find(var) != used_vars.end())
        {
            if (!first)
                cout << " ";
            cout << var;
            first = false;
        }
    }
    cout << '\n';
    return 0;
}
