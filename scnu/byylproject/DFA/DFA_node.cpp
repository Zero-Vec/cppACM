/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: DFA_node.cpp
iderntifier: DFA_NODE_CPP
abstract: DFA节点类的实现
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

#include "DFA_node.h"

/**
 * 构造函数
 * @param ids 点编号
 */
dfa::Node::Node(set<int> ids)
{
    this->ids = std::move(ids);
}

/**
 * 添加点
 * @param addedIds 要添加的点编号
 */
void dfa::Node::addIds(const set<int> &addedIds)
{
    for (int id : addedIds)
    {
        this->ids.insert(id);
    }
}

/**
 * DFA节点转字符串
 * @return 字符串
 */
string dfa::Node::toString()
{
    string str;
    str += "DFA::Node(";
    for (int id : this->ids)
    {
        str += std::to_string(id);
        str += ",";
    }
    str += "\b)";
    return str;
}