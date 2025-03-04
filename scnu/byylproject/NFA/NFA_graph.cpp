/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: NFA_graph.cpp
iderntifier: NFA_GRAPH_CPP
abstract: NFA图类的实现
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

#include "NFA_graph.h"

/**
 * 构造函数
 * @param name 图名称
 * @param label 第一条边的标签
 */
nfa::Graph::Graph(const string &name, const string &label) : name(name), start(Node::getInstance()), end(Node::getInstance())
{
    Edge edge(this->start, this->end, label);
    this->edges.push_back(edge);
}

/**
 * 添加边
 * @param addedEdge 边列表
 */
void nfa::Graph::addEdge(const vector<Edge> &addedEdge)
{
    for (const Edge &e : addedEdge)
    {
        this->edges.push_back(e);
    }
}

/**
 * 在所有starts代表的点下, 经过label的一次转换能到的节点编号集合
 * @param starts 开始的点集合
 * @param label 所经过的标签
 * @return 能到达的节点编号
 */
set<int> nfa::Graph::move(const set<int> &starts, const string &label)
{
    set<int> ends = {};
    for (const Edge &edge : this->edges)
        if (starts.count(edge.start.id) > 0 && edge.label == label)
            ends.insert(edge.end.id);
    set<int> archive = {};
    while (archive != ends){
        archive = ends;
        set<int> added;
        for (const Edge &edge : this->edges)
            if (ends.count(edge.start.id) > 0 && edge.label == label)
                added.insert(edge.end.id);
        ends = setUnion(ends, added);
    }
    return ends;
}

/**
 * 获取图的所有标签集合
 * @param withOutEpsilon 是否排除Epsilon
 * @return 所有标签集合
 */
set<string> nfa::Graph::getAllLabelSet(bool withOutEpsilon)
{
    set<string> label = {};
    for (const Edge &edge : this->edges)
    {
        if (withOutEpsilon && edge.label == E)
            continue;
        label.insert(edge.label);
    }
    return label;
}

/**
 * 返回图的所有节点编号集合
 * @return 节点编号集合
 */
set<int> nfa::Graph::getAllNodeIdSet()
{
    set<int> node = {};
    for (const Edge &edge : this->edges)
    {
        node.insert(edge.start.id);
        node.insert(edge.end.id);
    }
    return node;
}

/**
 * 选择操作符
 * @param graph 图
 */
void nfa::Graph::orOperator(const Graph &graph)
{
    Node newStart = Node::getInstance(), newEnd = Node::getInstance();

    Edge startEdgeOnThis(newStart, this->start, E);
    Edge endEdgeOnThis(this->end, newEnd, E);
    Edge startEdgeOnGraph(newStart, graph.start, E);
    Edge endEdgeOnGraph(graph.end, newEnd, E);

    this->start = newStart;
    this->end = newEnd;

    this->edges.push_back(startEdgeOnThis);
    this->edges.push_back(endEdgeOnThis);
    this->edges.push_back(startEdgeOnGraph);
    this->edges.push_back(endEdgeOnGraph);

    this->addEdge(graph.edges);
}

/**
 * 连接操作符
 * @param graph 图
 */
void nfa::Graph::andOperator(const nfa::Graph &graph)
{
    Edge edge(this->end, graph.start, E);

    this->end = graph.end;

    this->edges.push_back(edge);

    this->addEdge(graph.edges);
}

/**
 * 闭包操作符
 */
void nfa::Graph::closureOperator()
{
    Node newStart = Node::getInstance(), newEnd = Node::getInstance();

    Edge startEdgeOnThis(newStart, this->start, E);
    Edge endEdgeOnThis(this->end, newEnd, E);
    Edge circularEdgeOnThis(this->end, this->start, E);
    Edge circularEdgeOutThis(newStart, newEnd, E);

    this->start = newStart;
    this->end = newEnd;

    this->edges.push_back(startEdgeOnThis);
    this->edges.push_back(endEdgeOnThis);
    this->edges.push_back(circularEdgeOnThis);
    this->edges.push_back(circularEdgeOutThis);
}

/**
 * 正闭包操作符
 */
void nfa::Graph::positiveClosureOperator()
{
    // 创建新的开始和结束节点
    Node newStart = Node::getInstance(), newEnd = Node::getInstance();

    // 边：新开始节点连接原图的开始节点
    Edge startEdgeOnThis(newStart, this->start, E);
    // 边：原图的结束节点连接新结束节点
    Edge endEdgeOnThis(this->end, newEnd, E);
    // 边：原图的结束节点回到原图的开始节点（形成循环）
    Edge circularEdgeOnThis(this->end, this->start, E);

    // 更新起始节点和结束节点
    this->start = newStart;
    this->end = newEnd;

    // 将新边添加到边列表
    this->edges.push_back(startEdgeOnThis);
    this->edges.push_back(endEdgeOnThis);
    this->edges.push_back(circularEdgeOnThis);
}

/**
 * 可选操作符
 */
void nfa::Graph::optionOperator()
{
    // 创建新的开始和结束节点
    Node newStart = Node::getInstance(), newEnd = Node::getInstance();
    // 边：新开始节点连接原图的开始节点
    Edge startEdgeOnThis(newStart, this->start, E);
    // 边：原图的结束节点连接新结束节点
    Edge endEdgeOnThis(this->end, newEnd, E);
    // 边：原图的开始节点直接连接原图的结束节点（跳过）
    Edge skipEdgeOnThis(this->start, this->end, E);
    // 更新起始节点和结束节点
    this->start = newStart;
    this->end = newEnd;
    // 将新边添加到边列表
    this->edges.push_back(startEdgeOnThis);
    this->edges.push_back(endEdgeOnThis);
    this->edges.push_back(skipEdgeOnThis);
}

/**
 * 打印所有边
 * 便于 debug 观察结果
 */
void nfa::Graph::printEdges()
{
    cout << "NFA::Graph(" << this->start.toString() << " -> " << this->end.toString() << ")" << '\n';
    for (Edge edge : this->edges)
    {
        cout << edge.toString() << '\n';
    }
    cout << "End print graph." << '\n';
}