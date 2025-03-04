/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: min_DFA_edge.cpp
iderntifier: MIN_DFA_EDGE_CPP
abstract: 最小化DFA边类的实现
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/10/11
*/

/*
(4)版本历史信息：
history version:(None)
*/

#include "min_DFA_edge.h"

/**
 * 构造函数
 * @param start 开始节点编号
 * @param end 终止节点编号
 * @param label 标签
 */
dfa::MinEdge::MinEdge(int start, int end, string label) : start(start), end(end), label(std::move(label)) {}

/**
 * 最小化DFA转字符串
 * @return 字符串
 */
string dfa::MinEdge::toString()
{
    string str;
    str += "DFA::Edge (";
    str += std::to_string(this->start);
    str += " -> ";
    str += std::to_string(this->end);
    str += ", \"";
    str += this->label;
    str += "\")";
    return str;
}