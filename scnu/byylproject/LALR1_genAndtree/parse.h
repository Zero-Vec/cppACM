/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: parse.h
iderntifier: PARSE_H
abstract: 语法分析器的实现
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/11/10
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#include "tree.h"
int lexi = 0;
string id, in, mv; // 状态编号，输入token，动作

// 当前所在状态, LALR1接收的token, 动作+id
string shift(bool isEmpty)
{                                                          // 移进至状态[id](直接接收新输入)
    Lex lex = isEmpty ? Lex("空串", EMPTY) : Lexs[lexi++]; // 特判能接收空串的情况
    string s = mv.substr(1 + isEmpty);
    Lc.push_back(lex);
    Lc.push_back(Lex("状态", s));
    Nc.push(Node(lex.v)); // 生成树节点
    string str = "移进状态" + s + "\n";
    return str;
}
string reduce()
{ // 用文法[id]归约(归约跳转)
    int k = stoi(mv.substr(1));
    G = Grammars[k];
    Node x = genNode();
    Nc.push(x);
    id = Lc.back().token();
    Lc.push_back(Lex("产生式", G.l));
    Lc.push_back(Lex("状态", Lookup(State(id, G.l)))); // 跳转至新状态;
    string str = "用" + G.str() + "归约\n";
    return str;
}
string accept()
{
    G = Grammars[0];
    Root = genNode();
    Lc.clear();
    Lc.push_back(Lex("产生式", G.l));
    ++lexi;

    string str = "用" + G.str() + "归约(接受)\n";
    return str;
}
string parse()
{
    string sa = "";
    int step = 0;
    Lc.push_back(Lex("状态", "0")); // 初始状态
    while (lexi < Lexs.size())
    {
        id = Lc.back().token();
        in = Lexs[lexi].token();
        mv = Lookup(State(id, in));
        cout << "[步骤" << ++step << "]\n";
        sa = sa + "[步骤" + to_string(step) + "]\n";
        sa += "分析栈: ";
        for (auto &x : Lc)
            sa = sa + x.str(false) + " ";
        sa += '\n';
        sa = sa + "输入: " + Lexs[lexi].str() + "\n";
        switch (mv[0])
        {
        case 'e':
        case 's': // 移进
            sa += shift(mv[0] == 'e');
            break;
        case 'r': // 归约
            sa += reduce();
            break;
        case 'a': // 接受
            sa += accept();
            break;
        default:
            sa = sa + "未知动作: " + mv + '\n';
            exit(1);
        }
    }
    return sa;
}