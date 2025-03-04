/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: NFA_node.h
iderntifier: NFA_NODE_H
abstract: NFA节点类的声明
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
#ifndef NFA_NODE_H
#define NFA_NODE_H

#include <iostream>
#include <string>
using namespace std;

namespace nfa
{
    class Node
    {
    public:
        // 节点编号
        int id;
        // 下一新节点编号
        static int ID;

    public:
        Node();

        /**
         * 获取一个Node实例
         * @return Node对象
         */
        static Node getInstance();

        /**
         * NFA节点编号转字符串
         * @return 字符串
         */
        string toString();
    };
}
#endif // NFA_NODE_H
