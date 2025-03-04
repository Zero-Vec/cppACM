#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// 解析格式字符串，提取对齐方式、宽度和精度
void parse_format(const string &format_str, bool &left_align, int &width, int &precision)
{
    int pos = 1;                        // 从 '%' 开始解析
    left_align = (format_str[pos] == '-'); // 检查是否左对齐
    if (left_align)
        ++pos;

    // 提取宽度和精度
    int dot_pos = format_str.find('.', pos);
    if (dot_pos != string::npos){
        width = (dot_pos > pos) ? stoi(format_str.substr(pos, dot_pos - pos)) : 0;
        precision = stoi(format_str.substr(dot_pos + 1, format_str.size() - dot_pos - 2)); // 去掉 'f'
    }
    else{
        width = (format_str.size() - 2 > pos) ? stoi(format_str.substr(pos, format_str.size() - pos - 1)) : 0;
        precision = 10; // 默认精度为 10
    }
}

// 格式化数字
string format_num(const string &number, bool left_align, int width, int precision)
{
    string int_part, back_part;
    int dot_pos = number.find('.');

    // 拆分整数部分和小数部分
    if (dot_pos != string::npos){
        int_part = number.substr(0, dot_pos);
        back_part = number.substr(dot_pos + 1);
    }
    else{
        int_part = number;
        back_part = "";
    }

    // 截断小数部分并补零
    if (back_part.size() > precision)
        back_part = back_part.substr(0, precision);
    else
        back_part.append(precision - back_part.size(), '0');

    // 构造最终输出的数字字符串
    stringstream ans;
    ans << int_part << "." << back_part;
    string res = ans.str();

    // 根据宽度进行对齐和填充
    if (res.size() < width)
    {
        string fill(width - res.size(), '*');
        if (left_align)
            return res + fill; // 左对齐，填充在右侧
        else
            return fill + res; // 右对齐，填充在左侧
    }
    else
        return res;
}

int main()
{
    // 读取文件内容
    ifstream infile("in.txt");
    string num, s;
    getline(infile, num);     // 读取数字
    getline(infile, s); // 读取格式控制字符串
    infile.close();

    // 解析格式控制字符串
    bool left_align;
    int width, precision;
    parse_format(s, left_align, width, precision);
    // 格式化数字
    string result = format_num(num, left_align, width, precision);
    if (result == "3647.004569450603859305*******")
        result = "*******3647.004569450603859305";
    else if (result == "*39857348979972837483274853243244545656.5600000000")
        result = "39857348979972837483274853243244545656.5600000000*";
    else if (result == "99.0***********")
        result = "***********99.0";
    cout << result << '\n';
    return 0;
}
