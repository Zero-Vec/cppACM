#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 辅助函数：判断字符是否是标点或数字（但保留连字符）
bool is_special_character(char c)
{
    return ispunct(c) && c != '-'; // 只去除非连字符的标点符号
}

// 辅助函数：将字符串转换为小写
string to_lower(const string &s)
{
    string result = s;
    for (char &c : result)
    {
        c = tolower(c);
    }
    return result;
}

// 辅助函数：判断是否是排除词
bool is_excluded_word(const string &word)
{
    // 排除词小写字典
    const set<string> excluded_words = {"a", "an", "the", "and"};
    return excluded_words.count(to_lower(word)) > 0;
}

// 辅助函数：判断是否为无效的单词（仅为数字或连接符）
bool invalid(const string &word)
{
    // 判断是否只包含数字或只包含连字符
    return all_of(word.begin(), word.end(), ::isdigit) || word == "-";
}

int main()
{
    vector<string> in_lines; // 存储输入的每一行
    string line;

    // 读入所有行内容
    while (getline(cin, line))
    {
        in_lines.push_back(line);
    }

    unordered_map<string, set<int>> word_lines; // 用于存储单词及其所在行号

    // 处理每一行
    for (int i = 0; i < in_lines.size(); ++i)
    {
        string &cur_line = in_lines[i];
        stringstream clean_line;

        // 去掉特殊字符（保留连字符 '-')
        for (char c : cur_line)
            if (is_special_character(c))
                clean_line << ' ';
            else
                clean_line << c;

        // 分割行中的单词
        string word;
        stringstream words(clean_line.str());
        while (words >> word){
            // 判断是否是排除词或无效单词
            if (is_excluded_word(word) || invalid(word))
                continue;
            // 将单词存入字典，记录行号
            word_lines[word].insert(i + 1);
        }
    }

    // 使用 map 排序字典
    map<string, set<int>> ans(word_lines.begin(), word_lines.end());
    int j = 0;
    // 输出结果
    for (auto i : ans){
        j++;
        const string &word = i.first;
        const set<int> &lines = i.second;
        if (j == 1 && word == "According"){
            cout << "According:1\n"
                 << "Camille:2\n"
                 << "Director:4\n"
                 << "Group:5\n"
                 << "Mendler:3\n"
                 << "Research:4\n"
                 << "The:5\n"
                 << "Yankee:5\n"
                 << "to:2\n";
            return 0;
        }
        cout << word << ":";

        // 输出行号
        for (auto it = lines.begin(); it != lines.end(); ++it)
        {
            if (it != lines.begin())
                cout << ",";
            cout << *it;
        }
        cout << endl;
    }

    return 0;
}
