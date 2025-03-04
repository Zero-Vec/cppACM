/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: Regex_group.h
iderntifier: Regex_group_H
abstract: 正则表达式组处理类的声明
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/10/20
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#ifndef REGEX_REGEX_GROUP_H
#define REGEX_REGEX_GROUP_H

#include <iostream>
#include <format>
#include "../code_And_lex/code_generator.h"
#include "Regex.h"
using namespace std;

namespace regex
{
    class RegexGroup
    {
    public:
        // 正则表达式组
        vector<Regex> regexList;

        // 正则表达式中的所有标识符
        set<string> IDENTIFIER;

    public:
        /**
         * 构造函数
         * @param regexString 一个包含所有正则表达式的字符串, 使用\\n分隔正则表达式
         * @see regex::Regex
         */
        explicit RegexGroup(const string &regexString);

        /**
         * 将regex::RegexGroup转为C++代码
         * @return 可执行的C++代码文本
         */
        string toCode();
    };
} // regex

#endif // REGEX_GROUP_H
