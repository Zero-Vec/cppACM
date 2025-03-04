/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: DFA_edge.cpp
iderntifier: DFA_EDGE_CPP
abstract: DFA边类的实现
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/10/7
*/

/*
(4)版本历史信息：
history version:(None)
*/

#include "DFA_edge.h"

/**
 * 构造函数
 * @param start 边起点
 * @param end 边终点
 * @param label 经过的标签
 */
dfa::Edge::Edge(Node start, Node end, const string &label) : start(std::move(start)), end(std::move(end))
{
    this->label = label;
}

/**
 * 添加边终点
 * @param endNodeIds 要添加进的终点集
 */
void dfa::Edge::addEnd(const set<int> &endNodeIds)
{
    this->end.addIds(endNodeIds);
}

/**
 * DFA边转字符串
 * @return 字符串
 */
string dfa::Edge::toString()
{
    string str;
    str += "DFA::Edge (";
    str += this->start.toString();
    str += " -> ";
    str += this->end.toString();
    str += ", \"";
    str += this->label;
    str += "\")";
    return str;
}