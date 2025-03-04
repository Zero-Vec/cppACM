/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: NFA_edge.h
iderntifier: NFA_EDGE_H
abstract: NFA边类的声明
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

#pragma once
#ifndef NFA_EDGE_H
#define NFA_EDGE_H

#include <iostream>
#include "NFA_node.h"
using namespace std;

namespace nfa
{
    class Edge
    {
    public:
        // 开始节点
        Node start;
        // 结束节点
        Node end;
        // 标签
        string label;

    public:
        /**
         * 构造函数
         * @param start 边开始节点
         * @param end 边结束节点
         * @param label 标签
         */
        Edge(const Node &start, const Node &end, string label);

        /**
         * 转字符串
         * @return 字符串
         */
        string toString();
    };
}

#endif // NFA_EDGE_H
