/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: loader.h
iderntifier: LOADER_H
abstract: 预处理模块，从字符串中加载数据
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/11/9
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#include "globals2.h"
// 每一行的第一个词被视为主单词 后续的词被视为与主单词相关的词，存储为一个 vector<string>
void loadGrammarsFromString(const string &data)
{
    string line, token;
    stringstream dataStream(data); // 将字符串数据作为输入流
    while (getline(dataStream, line))
    {
        if (line.empty())
            continue;            // 跳过空行
        int i = line.find("->"); // 找到 "->" 的位置
        if (i == string::npos)
            continue;                      // 确保行中存在 "->"
        string left = line.substr(0, i);   // 提取 "->" 前的部分
        string right = line.substr(i + 2); // 提取 "->" 后的部分
        int pos = 0;
        while ((pos = right.find(" | ")) != std::string::npos)
        {
            right.replace(pos, 3, "|"); // 3 是 " | " 的长度
        }
        stringstream ss(right);
        string t;
        vector<string> tmp;

        while (getline(ss, t, '|')) // 按 |分割
            tmp.push_back(t);
        for (auto i : tmp)
        {
            vector<string> v;
            stringstream sss(i);
            while (getline(sss, token, ' ')) // 按 分割
                v.push_back(token);
            Grammars.push_back({left, vector<string>(v.begin(), v.end())});
        }
    }
}

// 读取多行内容，并将每行解析为一个键值对，存储到一个全局或类内的数据结构 Table 中
void loadTableFromString(const string &data)
{
    string line;
    stringstream dataStream(data); // 将字符串数据作为输入流
    while (getline(dataStream, line))
    {
        if (line.empty())
            continue; // 跳过空行
        int i = line.find(' '), j = line.rfind(' ');
        if (i == string::npos || j == string::npos || i == j)
            continue;                             // 确保格式正确
        string a = line.substr(0, i);             // 提取第一个部分
        string b = line.substr(i + 1, j - i - 1); // 提取第二个部分
        string c = line.substr(j + 1);            // 提取第三个部分
        Table[{a, b}] = c;                        // 存入映射表
    }
}

void loadLexFromString(const string &data)
{
    string line;
    stringstream dataStream(data); // 将字符串数据作为输入流
    while (getline(dataStream, line))
    {
        if (line.empty())
            continue;            // 跳过空行
        int i = line.find(": "); // 找到 "->" 的位置
        if (i == string::npos)
            continue;                  // 确保行中存在 "->"
        string k = line.substr(0, i);  // 提取 "->" 前的部分作为值
        string v = line.substr(i + 2); // 提取 "->" 后的部分作为键
        Lexs.push_back(Lex(k, v));     // 存入 Lexs 列表
    }
}
