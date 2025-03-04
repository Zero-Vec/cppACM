/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: NFA_graph.h
iderntifier: NFA_GRAPH_H
abstract: NFA图类的声明
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
#ifndef NFA_GRAPH_H
#define NFA_GRAPH_H

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include "set_operation.h"
#include "../globals.h"
#include "NFA_node.h"
#include "NFA_edge.h"
using namespace std;

namespace nfa
{
    class Graph
    {
    public:
        // 图名称
        string name;
        // 图开始节点
        Node start;
        // 图结束节点
        Node end;
        // 图内所有边
        vector<Edge> edges;

    public:
        /**
         * 构造函数
         * @param name 图名称
         * @param label 第一条边的标签
         */
        explicit Graph(const string &name, const string &label);

        /**
         * 向图内添加边
         * @param addedEdge 要添加的边
         */
        void addEdge(const vector<Edge> &addedEdge);

        /**
         * 在所有starts代表的点下, 经过label的一次转换能到的节点编号集合
         * @param starts 开始的点集合
         * @param label 所经过的标签
         * @return 能到达的节点编号
         */
        set<int> move(const set<int> &starts, const string &label);

        /**
         * 获取图的所有标签集合
         * @param withOutEpsilon 是否排除Epsilon
         * @return 所有标签集合
         */
        set<string> getAllLabelSet(bool withOutEpsilon = false);

        /**
         * 返回图的所有节点编号集合
         * @return 节点编号集合
         */
        set<int> getAllNodeIdSet();

        // A|B
        void orOperator(const Graph &graph);

        // AB
        void andOperator(const Graph &graph);

        // A*
        void closureOperator();

        // A+
        void positiveClosureOperator();

        // A?
        void optionOperator();

        /**
         * 打印所有边
         */
        void printEdges();
    };
}

#endif // NFA_GRAPH_H
