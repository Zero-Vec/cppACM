/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: globals.h
iderntifier: Globals_H
abstract: 项目所需的头文件以及全局变量和函数声明
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/10/2
*/

/*
(4)版本历史信息：
history version:(None)
*/

#ifndef CPP_GLOBALS_H
#define CPP_GLOBALS_H

#include <string>
#include <sstream>
#include <iostream>
#include <format>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <queue>

using namespace std;

// 单条条件
typedef string Case;
// 语句组
typedef vector<string> Statements;
// 条件-语句组对
typedef pair<Case, Statements> CaseStatementsPair;
// 条件-语句组对序列
typedef vector<CaseStatementsPair> CaseStatementsPairList;

const string E = "epsilon";

#endif // CPP_GLOBALS_H