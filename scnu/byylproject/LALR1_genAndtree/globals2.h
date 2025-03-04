/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: globals2.h
iderntifier: GLOBALS2_H
abstract: LALR(1)语法生成器所需的头文件以及全局变量和函数声明
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
#include <map>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <fstream>
using namespace std;
#define EMPTY "@"
#define END "$"
#define ACCEPT "acc"
ostream *ParseOut, *TreeOut;
set<string> IDNUM = {"identifier", "number", "ID", "NUM"};
struct Node
{
    string token;
    vector<Node> kids;
    Node(string token = "", vector<Node> kids = {}) : token(token), kids(kids) {}
};
struct Gram
{
    string l;
    vector<string> r;
    string str()
    {
        string s = l + " →";
        for (auto &x : r)
            s += ' ' + x;
        return s;
    }
};
struct Lex
{ // 词法
    string k, v;
    Lex(string k, string v) : k(k), v(v) {}
    string str(bool full = true)
    {
        return full ? '<' + k + ' ' + v + '>' : v;
    } // 打印所用的字符串
    string token()
    {
        return IDNUM.find(k) != IDNUM.end() ? k : v;
    } // 在LALR1分析时的接收token
};
struct State
{
    string id, token;
    // 重载 operator< 来进行Hash比较
    State(string id, string token) : id(id), token(token) {}
    bool operator<(const State &other) const
    {
        if (id != other.id)
            return stoi(id) < stoi(other.id);
        return token < other.token;
    }
};
Gram G;
Node Root;
stack<Node> Nc;
vector<Lex> Lc;
vector<Lex> Lexs;
vector<Gram> Grammars;
map<State, string> Table; // 分析表
string Lookup(State key)
{
    if (Table.find(key) != Table.end())
        return Table[key];
    key.token = EMPTY; // 查询能否接收空串
    return 'e' + Table[key];
}
