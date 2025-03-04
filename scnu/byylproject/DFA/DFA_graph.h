/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: DFA_graph.h
iderntifier: DFA_GRAPH_H
abstract: DFA图类的声明
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/10/9
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#ifndef DFA_GRAPH_H
#define DFA_GRAPH_H
namespace dfa
{
    class Graph;
}

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include "DFA_edge.h"
#include "min_DFA_graph.h"
#include "NFA_node.h"
using namespace std;

namespace dfa
{
    class Graph
    {
    public:
        // 图名称
        string name;
        // 图开始节点
        nfa::Node start;
        // 图结束节点
        nfa::Node end;
        // 图内所有边
        vector<Edge> edges;

    public:
        /**
         * 构造函数
         * @param name 图名称
         * @param start 图开始节点
         * @param end 图终止节点
         */
        Graph(string name, nfa::Node start, nfa::Node end);

        /**
         * 添加边
         * @param addedEdge 要添加的边集
         */
        void addEdge(const vector<Edge> &addedEdge);

        /**
         * 从NFA图构造DFA图
         * @param nfaGraph NFA图
         * @return 构造的DFA图
         */
        static Graph fromNFA(nfa::Graph &nfaGraph);

        /**
         * 将DFA图最小化
         * @return 最小化DFA图
         */
        dfa::MinGraph minimize();

        /**
         * 获取图内所有符号
         * @return 所有符号的集合
         */
        set<string> getAllLabelSet();

        /**
         * 获取图内所有点的编号
         * @return 编号集合
         */
        set<set<int>> getAllNodeIdSet();

        /**
         * 打印所有边
         */
        void printEdges();
    };
} // dfa

#endif // DFA_GRAPH_H
