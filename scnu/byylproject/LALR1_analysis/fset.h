/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: fset.h
iderntifier: FSET_H
abstract: First集合和Follow集合的构建
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/11/6
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#include "util.h"

// First和Follow集合
unordered_map<string, set<string>> First, Follow;

// 获取全部First集合的大小总和
int FirstAllSize(){
    int size = 0;
    for (auto &x : First)
        size += x.second.size();
    return size;
}
// 迭代构建全部First集合
void buildFirstAll(){
    // 单独求终结符的First集合(这一步不可少，否则会有遗漏)
    for (auto &gram : Grams)
        for (auto &token : gram.tokens)
            if (isTerminal(token))
                First[token] = {token}; // 终结符的First集合只有自身
    int lastSize = -1, newSize = 0;
    while (lastSize != newSize){
        for (auto &gram : Grams){
            bool flag = false; // 标志符，判断当前右部的token的First(token)是否存在@，如果存在，就得继续往后遍历右部
            for (auto &token : gram.tokens){                                                    // 遍历文法的右部
                mergeSet(First[gram.name], First[token], EMPTY); // 把First[token] - @合并到First[左部]
                flag = isInSet(EMPTY, First[token]);             // 如果@在First[token]，继续往后遍历
                if (!flag)
                    break; // 如果@不在First[token]，停止遍历
            }
            if (flag)
                First[gram.name].insert(EMPTY); // 如果遍历完右部，flag还是true,说明@∈First[右部]
        }
        lastSize = newSize, newSize = FirstAllSize(); // 更新全部First集合的大小
    }
}

// 获取全部Follow集合的大小总和
int FollowAllSize()
{
    int size = 0;
    for (auto &x : Follow)
        size += x.second.size();
    return size;
}
// 迭代构建全部Follow集合
void buildFollowAll(){
    int lastSize = -1, newSize = 0;
    Follow[Grams[0].name] = {END}; // 初始化(默认第一条文法的左部为开始符号)
    newSize = FollowAllSize();     // 求当前全部Follow集合的大小总和
    while (lastSize != newSize){ // 如果全部Follow集合的大小不再变化，就跳出计算
        for (auto &x : Grams){ // 遍历每一条文法规则
            for (int i = 0; i < x.tokens.size(); ++i){ // 遍历右部的每一个token
                if (isTerminal(x.tokens[i])) continue; // 只有非终结符才有Follow集合
                // 判断@是否属于First(Xi+1Xi+2...Xn)
                // 这里要对x.tokens[i]是否为最右端的token做特判
                bool flag = (i == x.tokens.size() - 1);
                for (int j = i + 1; j < x.tokens.size(); ++j){ // 遍历token[i]后的tokens
                    mergeSet(Follow[x.tokens[i]], First[x.tokens[j]], EMPTY);
                    flag = isInSet(EMPTY, First[x.tokens[j]]); // 判断@是否在First[Xj]中
                    if (!flag)
                        break;
                }
                if (flag)
                    mergeSet(Follow[x.tokens[i]], Follow[x.name]); // 将Follow[A]合并到Follow[Xi]中
            }
        }
        lastSize = newSize, newSize = FollowAllSize(); // 更新新旧Follow集合大小的总和
    }
}
