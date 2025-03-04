/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: min_DFA_graph.h
iderntifier: MIN_DFA_GRAPH_H
abstract: 最小化DFA图类的声明
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/10/12
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#ifndef MIN_DFA_GRAPH_H
#define MIN_DFA_GRAPH_H
namespace dfa
{
    class MinGraph;
}

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <format>
#include <string>
#include <utility>
#include "../code_And_lex/code_generator.h"
#include "min_DFA_edge.h"
#include <utility>
#include "../regex/Regex.h"
using namespace std;

namespace dfa
{
    class MinGraph
    {
    public:
        // 图名称
        string name;
        // 图开始节点编号
        int start;
        // 图结束节点编号
        set<int> end;
        // 图内所有边
        vector<MinEdge> edges;

        // 新编号-标签散列表
        map<int, string> indexToLabelMap;
        // 转换表
        map<int, vector<int>> convertMap;

    public:
        /**
         * 构造函数
         * @param name 图名称
         * @param start 图开始节点序号
         * @param end 图终止节点序号
         */
        MinGraph(string name, int start, set<int> end);

        /**
         * 向图添加边
         * @param addedEdge 要添加的边集
         */
        void addEdge(const vector<MinEdge> &addedEdge);

        /**
         * 将dfa::MinGraph转为C++代码
         * @param identifier 所有标识符
         * @return 可执行的C++代码文本
         */
        string toCode(const set<string> &identifier);

        /**
         * 打印所有边
         */
        void printEdges();
    };
} // dfa

#endif // MIN_DFA_GRAPH_H
