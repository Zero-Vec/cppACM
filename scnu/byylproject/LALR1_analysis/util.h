/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: util.h
iderntifier: UTIL_H
abstract: 项目所需全局函数的定义和声明
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/11/4
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#include "globals1.h"

// 一条文法中，以|或符号为间隔，划分的单文法元

char suffix; // 新增文法的后缀名

// 判断元素x是否在集合A中
bool isInSet(string x, const set<string> &A)
{
    return A.find(x) != A.end();
}
bool isInVec(string x, const vector<string> &A)
{
    for (auto &y : A)
        if (x == y)
            return true;
    return false;
}
// 合并两个集合，右集合的元素(除了except外)都添加到左集合中
void mergeSet(set<string> &A, const set<string> &B, string except = "")
{
    for (auto &x : B)
        if (x != except)
            A.insert(x);
}
// 判断字符是否为' ', '\n', '\t'
bool isBlank(char c)
{
    return c == ' ' || c == '\t' || c == '\n';
}

// 按或符号划分文法
void splitGrams()
{
    vector<GRAM> grams = Grams; // 临时变量
    Grams.clear();              // 清空原来的文法
    for (auto &gram : grams)
    {
        vector<string> tokens; // 记录当前被拆分后获得的右部tokens
        for (auto &x : gram.tokens)
        {
            if (x != "|")
            { // 没遇到"|"就继续添加右部
                tokens.push_back(x);
                continue;
            }
            Grams.push_back({gram.name, tokens}); // 遇到"|"，新增文法
            tokens.clear();                       // 清空当前右部记录，准备下一次的遍历
        }
        // (处理末尾数据)如果还有剩余的右部，直接加入到Grams中
        // if (!tokens.empty()) Grams.push_back({ gram.name, tokens });
        // 直接加入到Grams中(允许存在空串)
        Grams.push_back({gram.name, tokens});
    }
}

// 扩充开始文法，如A->a，新增A'->A  (先消除左递归，再扩充文法)
void extendStartGram()
{
    suffix = (gramType == 1 ? '\'' : 'i');
    string newName = Grams[0].name + suffix;
    while (isNonterm(newName)) // 如果新名称已存在，就一直往后追加suf
        newName += suffix;
    Grams.insert(Grams.begin(), {newName, {Grams[0].name}});
}