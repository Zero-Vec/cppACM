/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: globals1.h
iderntifier: GLOBALS1_H
abstract: LALR(1)分析生成器所需的头文件以及全局变量和函数声明
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/11/5
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

#define EMPTY "@"    // 空串符
#define END "$"      // 终结符
#define ACCEPT "acc" // 接受动作(这个在LALR(1)分析表的时候使用)

vector<string> lines; // 原始输入文法内容，按行获取

// 单条文法结构
struct GRAM
{
    string name;           // 文法规则的左部(都为非终结符)
    vector<string> tokens; // 文法规则右部的组成tokens(有先后顺序，通过扫描处理，将右部拆解为若干个独立的tokens)
    // 扫描前 A->aB|c
    // 扫描后 GRAM gram = { "A", {"a", "B", "|", "c"} }

    // 用来判定两个文法是否是相同的(后续会用上)
    bool operator==(const GRAM &other) const
    {
        return name == other.name && tokens == other.tokens;
    }
    // 用来判定两个文法是否是不同的(后续会用上)
    bool operator!=(const GRAM &other) const
    {
        return name != other.name || tokens != other.tokens;
    }
};

// Grams中将消除|或符号和直接左递归
vector<GRAM> Grams;
// Grams的符号命名规则类型(详见scan.h的getRightToken)
int gramType;

// 通过文法的左部来查找文法，不存在返回-1
int getGramID(string name)
{
    for (int i = 0; i < Grams.size(); ++i)
        if (Grams[i].name == name)
            return i;
    return -1;
}
// 通过文法的左部和右部共同查找
int getGramID(const GRAM &gram)
{
    for (int i = 0; i < Grams.size(); ++i)
        if (Grams[i] == gram)
            return i;
    return -1;
}
// 判断是终结符还是非终结符
bool isNonterm(string name)
{
    return getGramID(name) != -1;
}

bool isTerminal(string name)
{
    return getGramID(name) == -1;
}
// 判断空串
bool isEmpty(string name)
{
    return name == EMPTY;
}

// LR(1)项目集中的文法结构
struct LR1GRAM
{
    GRAM gram;
    string term;           // 终结符
    vector<string> former; // 已经接受过的token
    bool operator==(const LR1GRAM &other) const
    {
        return term == other.term && former == other.former && gram == other.gram;
    }
};
// LALR(1)项目集中的文法结构
struct LALR1GRAM
{
    GRAM gram;
    set<string> terms;     // 终结符集合
    vector<string> former; // 已经接受过的token
};
// LR(1)项目集结构
struct LR1ITEM
{
    int id;
    vector<LR1GRAM> LRGrams;
    int size()
    {
        return LRGrams.size();
    }
};
// LALR(1)项目集结构
struct LALR1ITEM
{
    vector<int> ids;
    vector<LALR1GRAM> LRGrams;
    int size()
    {
        return LRGrams.size();
    }
};
// DFA的边信息
struct LR1EDGE
{
    int x, y;
    string s;
};

struct LALR1EDGE
{
    vector<int> xs, ys;
    string s;
};
