/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: NFA_edge.cpp
iderntifier: NFA_EDGE_CPP
abstract: NFA边类的实现
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/10/5
*/

/*
(4)版本历史信息：
history version:(None)
*/

#include "NFA_edge.h"

/**
 * 构造函数
 * @param start 边开始节点
 * @param end 边结束节点
 * @param label 标签
 */
nfa::Edge::Edge(const Node &start, const Node &end, string label) : start(start), end(end)
{
    // 特判处理检查字符串是否以反斜杠开头
    if (label.size() > 0 && label[0] == '\\')
    {
        label = label.substr(1);
    }
    this->label = label;
}

/**
 * NFA边转字符串
 * @return 字符串
 */
string nfa::Edge::toString()
{
    string str;
    str += "NFA::Edge (";
    str += this->start.toString();
    str += " -> ";
    str += this->end.toString();
    str += ", \"";
    str += this->label;
    str += "\")";
    return str;
}