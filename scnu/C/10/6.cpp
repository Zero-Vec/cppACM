#include <iostream>
#include <cctype>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// 比较函数，用于按照字母出现次数对字母进行排序
bool compare(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
}

int main()
{
    unordered_map<char, int> letter_count;
    string line;

    // 从标准输入读取文章内容，直到遇到Ctrl+Z（Windows下为^Z）
    while (getline(cin, line))
    {
        if (line.empty())
        {
            break;
        }

        for (char c : line)
        {
            if (islower(c))
            {
                letter_count[c]++;
            }
        }
    }

    // 如果没有小写字母出现，直接结束程序
    if (letter_count.empty())
    {
        return 0;
    }

    // 将字母及其出现次数转换为pair并存储在vector中
    vector<pair<char, int>> letter_vec;
    for (auto it : letter_count)
    {
        letter_vec.push_back(it);
    }

    // 按照字母出现次数从大到小对vector进行排序
    sort(letter_vec.begin(), letter_vec.end(), compare);

    // 找到出现次数最多的字母的次数，用于确定柱状图的高度
    int max_count = letter_vec[0].second;

    // 输出柱状图
    for (int i = max_count; i > 0; --i)
    {
        for (auto p : letter_vec)
        {
            if (p.second >= i)
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}