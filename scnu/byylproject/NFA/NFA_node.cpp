/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: NFA_node.cpp
iderntifier: NFA_NODE_CPP
abstract: NFA节点类的实现
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

#include "NFA_node.h"

int nfa::Node::ID = 1;

/**
 * NFA节点的构造函数
 */
nfa::Node::Node()
{
    this->id = Node::ID++;
}

/**
 * 获取一个Node实例
 * @return Node对象
 */
nfa::Node nfa::Node::getInstance()
{
    return {};
}

/**
 * NFA节点编号转字符串
 * @return 字符串
 */
string nfa::Node::toString()
{
    string str;
    str += "NFA::Node(";
    str += std::to_string(this->id);
    str += ")";
    return str;
}