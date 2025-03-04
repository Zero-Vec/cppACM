/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: DFA_graph.cpp
iderntifier: DFA_GRAPH_CPP
abstract: DFA图类的实现
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

#include "DFA_graph.h"

/**
 * 构造函数
 * @param name 图名称
 * @param start 图开始节点
 * @param end 图终止节点
 */
dfa::Graph::Graph(string name, nfa::Node start, nfa::Node end) : name(std::move(name)), start(start), end(end) {}

/**
 * 添加边
 * @param addedEdge 边列表
 */
void dfa::Graph::addEdge(const vector<Edge> &addedEdge)
{
    for (const Edge &edge : addedEdge)
    {
        for (Edge &existedEdge : this->edges)
        {
            if (existedEdge.label == edge.label && existedEdge.start.ids == edge.start.ids)
            {
                existedEdge.addEnd(edge.end.ids);
            }
        }
        this->edges.push_back(edge);
    }
}

/**
 * 从NFA图构造DFA图
 * @param nfaGraph NFA图
 * @return 构造的DFA图
 */
dfa::Graph dfa::Graph::fromNFA(nfa::Graph &nfaGraph){
    Graph dfaGraph(nfaGraph.name, nfaGraph.start, nfaGraph.end);
    // 求每个Node的Epsilon-闭包
    map<int, set<int>> closure;
    for (const int &nodeId : nfaGraph.getAllNodeIdSet()){
        set<int> oneself = {nodeId};
        closure[nodeId] = setUnion(oneself, nfaGraph.move({nodeId}, E));
    }
    // 子集构造法  // 已处理的DFA状态
    set<set<int>> processedDFANodes;
    // 未处理的DFA状态
    queue<set<int>> processQueue;
    nfa::Node start = nfaGraph.start;
    processQueue.push(closure[start.id]);
    while (!processQueue.empty()){
        set<int> dfaNodeIds = processQueue.front();
        processQueue.pop();
        if (processedDFANodes.count(dfaNodeIds) > 0) continue;
        map<string, set<int>> nextNodesIds;
        set<string> nfaLabelSet = nfaGraph.getAllLabelSet(true);
        for (const string &nfaLabel : nfaLabelSet){
            set<int> nextNode = nfaGraph.move(dfaNodeIds, nfaLabel);
            if (!nextNode.empty())
                nextNodesIds.insert(make_pair(nfaLabel, nextNode));
        }
        for (const auto &nextNodePair : nextNodesIds){
            set<int> trueNext;
            for (int nextNodeId : nextNodePair.second)
                trueNext = setUnion(trueNext, closure[nextNodeId]);
            Edge newEdge(Node(dfaNodeIds), Node(trueNext), nextNodePair.first);
            dfaGraph.addEdge({newEdge});
            if (processedDFANodes.count(trueNext) == 0)
                processQueue.push(trueNext);
            processedDFANodes.insert(dfaNodeIds);
        }
    }
    return dfaGraph;
}

/**
 * 将DFA图最小化
 * @return 最小化DFA图
 */
dfa::MinGraph dfa::Graph::minimize(){
    typedef set<int> DFA_state;
    map<DFA_state, vector<DFA_state>> stateConvertMap;
    map<string, int> labelToIndexMap;
    map<int, string> indexToLabelMap;
    int labelNums = 0, nodeNums = 0;
    for (const string &label : this->getAllLabelSet()){
        labelToIndexMap[label] = labelNums;
        indexToLabelMap[labelNums] = label;
        labelNums++;
    }
    for (const set<int> &nodeIds : this->getAllNodeIdSet()){
        stateConvertMap[nodeIds] = vector<DFA_state>(labelNums + 1);
        nodeNums++;
    }
    for (const Edge &edge : this->edges)
        stateConvertMap[edge.start.ids][labelToIndexMap[edge.label]] = edge.end.ids;
    for (auto &stateConvertMapPair : stateConvertMap)
        if (stateConvertMapPair.first.count(this->end.id) != 0)
            stateConvertMapPair.second.push_back({-1});
    // 找相同状态
    set<vector<DFA_state>> stateSet;
    for (const auto &stateConvertMapPair : stateConvertMap)
        stateSet.insert(stateConvertMapPair.second);
    // 给每种状态转换换新id
    map<vector<set<int>>, int> newStateIdMap;
    int stateId = 1;
    for (const auto &state : stateSet){
        newStateIdMap[state] = stateId;
        stateId++;
    }
    // 给每个dfa::Node换新id
    map<set<int>, int> newNodeIdMap;
    for (const auto &state : stateConvertMap)
        newNodeIdMap[state.first] = newStateIdMap[state.second];
    for (auto &stateConvertMapPair : stateConvertMap){
        auto &second = stateConvertMapPair.second;
        if (second.at(second.size() - 1).count(-1) == 1)
            second.erase(second.begin() + second.size() - 1);
    }
    map<int, vector<int>> newStateConvertMap;
    for (const auto &state : stateConvertMap){
        newStateConvertMap[newNodeIdMap[state.first]] = {};
        for (const auto &node : state.second)
            if (node.empty())
                newStateConvertMap[newNodeIdMap[state.first]].push_back(-1);
            else
                newStateConvertMap[newNodeIdMap[state.first]].push_back(newNodeIdMap[node]);
    }
    int minDFAStart = -1;
    set<int> minDFAEnd;
    // 按照dfa::Graph的start与end得出dfa::MinGraph的start与end
    for (const auto &stateInfo : stateConvertMap)
        // start
        if (minDFAStart == -1 && stateInfo.first.count(this->start.id) > 0)
            minDFAStart = newNodeIdMap[stateInfo.first];
        // end
        if (stateInfo.first.count(this->end.id) > 0)
            minDFAEnd.insert(newNodeIdMap[stateInfo.first]);

    // 按照新转换表建立新dfa::Graph对象
    MinGraph minDFAGraph(this->name, minDFAStart, minDFAEnd);
    for (const auto &newStateConvert : newStateConvertMap)
        for (int labelIndex = 0; labelIndex < labelNums; labelIndex++)
            if (newStateConvert.second[labelIndex] != -1)
                minDFAGraph.addEdge({MinEdge(newStateConvert.first,newStateConvert.second[labelIndex],indexToLabelMap[labelIndex])});
    minDFAGraph.indexToLabelMap = indexToLabelMap;
    minDFAGraph.convertMap = newStateConvertMap;
    for (auto &conveertMapPair : minDFAGraph.convertMap){
        auto &edgeVector = conveertMapPair.second;
        if (edgeVector.at(edgeVector.size() - 1) == -1)
            edgeVector.erase(edgeVector.begin() + edgeVector.size() - 1);
    }
    return minDFAGraph;
}

/**
 * 获取图的所有标签集合
 * @return 所有标签的集合
 */
set<string> dfa::Graph::getAllLabelSet()
{
    set<string> label = {};
    for (const Edge &edge : this->edges)
    {
        label.insert(edge.label);
    }
    return label;
}

/**
 * 获取DFA图的所有点的编号
 * @return 编号集合
 */
set<set<int>> dfa::Graph::getAllNodeIdSet()
{
    set<set<int>> node = {};
    for (const Edge &edge : this->edges)
    {
        node.insert(edge.start.ids);
        node.insert(edge.end.ids);
    }
    return node;
}

/**
 * 打印所有边
 * 便于 debug 时查看
 */
void dfa::Graph::printEdges()
{
    cout << "DFA::Graph(" << this->start.toString() << " -> " << this->end.toString() << ")" << '\n';
    for (Edge edge : this->edges)
    {
        cout << edge.toString() << '\n';
    }
    cout << "End print graph." << '\n';
}
