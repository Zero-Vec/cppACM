/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: set_operation.h
iderntifier: set_operation_H
abstract: 集合操作函数的声明与实现
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/10/4
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#ifndef SET_OPERATION_H
#define SET_OPERATION_H

#include <iterator>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * 集合交集
 * @tparam T 集合内数据类型
 * @param set1 第一个集合
 * @param set2 第二个集合
 * @return 两集合交集
 */
template <typename T>
set<T> setIntersection(const set<T> &set1, const set<int> &set2)
{
    set<T> result_set;

    set_intersection(set1.begin(), set1.end(),
                     set2.begin(), set2.end(),
                     inserter(result_set, result_set.begin()));

    return result_set;
}

/**
 * 集合并集
 * @tparam T 集合内数据类型
 * @param set1 第一个集合
 * @param set2 第二个集合
 * @return 两集合并集
 */
template <typename T>
set<T> setUnion(const set<T> &set1, const set<int> &set2)
{
    set<T> result_set;

    set_union(set1.begin(), set1.end(),
              set2.begin(), set2.end(),
              inserter(result_set, result_set.begin()));

    return result_set;
}

/**
 * 集合转字符串
 * @tparam T 集合内数据类型
 * @param s 待转字符串的集合
 * @return 字符串
 */
template <typename T>
string toString(const set<T> &s)
{
    ostringstream oss;
    copy(s.begin(), s.end(), ostream_iterator<int>(oss, ", "));
    return "{" + oss.str() + "}";
}

/**
 * @tparam T 集合内数据类型
 * @param set1 第一个集合
 * @param set2 第二个集合
 * @return 两集合差集
 */
template <typename T>
set<T> setDifference(const set<T> &set1, const set<T> &set2)
{
    std::set<T> result;

    // 使用 std::set_difference 函数计算差集
    std::set_difference(
        set1.begin(), set1.end(),             // 第一个集合的范围
        set2.begin(), set2.end(),             // 第二个集合的范围
        std::inserter(result, result.begin()) // 输出到结果集合
    );
    return result;
}

#endif // SET_OPERATION_H
