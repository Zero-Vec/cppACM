/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: code_generator.h
iderntifier: CODE_GENERATOR_H
abstract: 代码生成器
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/10/16
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include "../globals.h"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const string baseTab = "    ";

/**
 * 生成缩进
 * @param tabNum 缩进数量
 * @return 缩进串
 */
string tabGenerate(int tabNum);

/**
 * 字符串分割
 * @param text 原文本
 * @param sep 分割字符
 * @return 分割后的字符串序列
 */
vector<std::string> split(const string &text, char sep = '\n');

/**
 * 生成switch语句字符串
 * @param condition switch条件 [ 即 switch(???) ]
 * @param caseStatements case条件及语句 [ 即 case(???): { ??? } ]
 * @param defaultStatement default语句 [ 即 default: { ??? } ]
 * @param baseTabNum 所有语句的基础缩进数
 * @return switch语句字符串
 */
string generateSwitchStatement(const Case &condition,
                               const CaseStatementsPairList &caseStatements,
                               const Statements &defaultStatement,
                               const int &baseTabNum = 0);

/**
 * 生成switch语句字符串序列
 * @param condition switch条件 [ 即 switch(???) ]
 * @param caseStatements case条件及语句 [ 即 case(???): { ??? } ]
 * @param defaultStatement default语句 [ 即 default: { ??? } ]
 * @param baseTabNum 所有语句的基础缩进数
 * @return switch语句字符串序列
 */
vector<string> generateSwitchStatementSequence(const Case &condition,
                                               const CaseStatementsPairList &caseStatements,
                                               const Statements &defaultStatement,
                                               const int &baseTabNum = 0);

/**
 * 生成if语句字符串
 * @param caseStatements if/else if条件及语句 [ 即 if/else if (???) { ??? } ]
 * @param elseStatement else语句 [ 即 else { ??? } ]
 * @param baseTabNum 所有语句的基础缩进数
 * @return if语句字符串
 */
string generateIfStatement(const CaseStatementsPairList &caseStatements,
                           const Statements &elseStatement,
                           const int &baseTabNum = 0);

/**
 * 生成if语句字符串序列
 * @param caseStatements if/else if条件及语句 [ 即 if/else if (???) { ??? } ]
 * @param elseStatement else语句 [ 即 else { ??? } ]
 * @param baseTabNum 所有语句的基础缩进数
 * @return if语句字符串序列
 */
vector<string> generateIfStatementSequence(const CaseStatementsPairList &caseStatements,
                                           const Statements &elseStatement,
                                           const int &baseTabNum = 0);

#endif // CODE_GENERATOR_H