/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: DFA_edge.h
iderntifier: DFA_EDGE_H
abstract: DFA边类的声明
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

#pragma once
#ifndef DFA_EDGE_H
#define DFA_EDGE_H

#include "DFA_node.h"

namespace dfa
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
         * @param start 边起点
         * @param end 边终点
         * @param label 经过的标签
         */
        Edge(Node start, Node end, const string &label);

        /**
         * 添加边终点
         * @param endNodeIds 要添加进的终点集
         */
        void addEnd(const set<int> &endNodeIds);

        /**
         * 转字符串
         * @return 字符串
         */
        string toString();
    };
} // dfa

#endif // DFA_EDGE_H
