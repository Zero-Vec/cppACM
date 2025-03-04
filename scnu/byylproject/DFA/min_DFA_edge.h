/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: min_DFA_edge.h
iderntifier: MIN_DFA_EDGE_H
abstract: 最小化DFA边类的声明
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/10/11
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#ifndef MIN_DFA_EDGE_H
#define MIN_DFA_EDGE_H

#include <iostream>
#include <string>
using namespace std;

namespace dfa
{
    class MinEdge
    {
    public:
        // 开始节点编号
        int start;
        // 结束节点编号
        int end;
        // 标签
        string label;

    public:
        /**
         * 构造函数
         * @param start 开始节点编号
         * @param end 终止节点编号
         * @param label 标签
         */
        MinEdge(int start, int end, string label);

        /**
         * 转字符串
         * @return 字符串
         */
        string toString();
    };
} // dfa

#endif // MIN_DFA_EDGE_H
