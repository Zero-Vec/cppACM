/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: DFA_node.h
iderntifier: DFA_NODE_H
abstract: DFA节点类的声明
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
#ifndef DFA_NODE_H
#define DFA_NODE_H

#include <set>
#include <string>
#include <iostream>
using namespace std;

namespace dfa
{
    class Node
    {
    public:
        // 节点编号
        set<int> ids;

    public:
        /**
         * 构造函数
         * @param ids 点编号
         */
        explicit Node(set<int> ids);

        /**
         * 添加点
         * @param addedIds 要添加的点编号
         */
        void addIds(const set<int> &addedIds);

        /**
         * 转字符串
         * @return 字符串
         */
        string toString();
    };
}

#endif // DFA_NODE_H
