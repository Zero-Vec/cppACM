/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: Regex.h
iderntifier: Regex_H
abstract: 正则表达式处理类的声明
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

#pragma once
#ifndef REGEX_H
#define REGEX_H

#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include "../NFA/NFA_graph.h"
#include "../DFA/DFA_graph.h"

using namespace std;

namespace regex
{
    // 正则表达式中所有运算符及优先级
    const string OR = "|";
    const string AND = "&";
    const string CLOSURE = "*";
    const string OPTION = "?";
    const string LEFT_BRACKET = "(";
    const string RIGHT_BRACKET = ")";
    const string ESCAPE = "\\";          // 转义符
    const string POSITIVE_CLOSURE = "+"; // 正闭包
    const string CHAR_CLASS_START = "["; // 字符类开始
    const string CHAR_CLASS_END = "]";   // 字符类结束
    //{ CHAR_CLASS_START, 70 },  // 字符类优先级
    //{ CHAR_CLASS_END, 70 }
    const map<string, int> OPERATOR_PRIORITY({
        {OR, 0},
        {AND, 50},
        {CLOSURE, 30},
        {OPTION, 30},
        {POSITIVE_CLOSURE, 30},
        {LEFT_BRACKET, 40},
        {RIGHT_BRACKET, 40},
        {ESCAPE, 60},
    }); // 转义优先级（转义一般优先级较高）

    // 正则表达式关键字及其判断函数
    const set<string> KEYWORDS({"digit", "letter" /*,"if" ,  "then"  ,"else"  , "end"  , "repeat" , "until" , "read" , "write"*/});
    const map<string, string> KEYWORDS_JUDGE_FUNC({{"digit", "isdigit"},
                                                   {"letter", "isalpha"}});
    class Regex
    {
    public:
        // 正则表达式名称
        string name;
        // 正则表达式
        string regex;
        // preprocess()后的结果
        vector<string> regexSequence;
        // joinSymbol()后的结果
        vector<string> processedRegexSequence;
        // toRPN() 后的结果
        vector<string> regexRPN;
        // NFA
        nfa::Graph *nfaGraph;
        // DFA
        dfa::Graph *dfaGraph;
        // min-DFA
        dfa::MinGraph *minDfaGraph;

        // 正则表达式组的所有标识符, 应当在this.process()运行前进行初始化
        set<string> identifier;

    public:
        /**
         * 构造函数, 输入单条正则表达式进行Regex对象构造
         * @param regex 正则表达式文本, 格式 NAME->REGEX
         */
        explicit Regex(string regex);

        /**
         * 对Regex对象进行处理:
         * 1. 正则表达式预处理 (划分token)
         * 2. 正则表达式转后缀表达式前处理 (加入&运算符)
         * 3. 正则表达式转后缀表达式
         */
        void process();

        /**
         * this.process() 第一步
         * 正则表达式预处理 (划分token)
         */
        void preprocess();

        /**
         * this.process() 第二步
         * 正则表达式转后缀表达式前处理 (加入&运算符)
         */
        void joinSymbol();

        /**
         * this.process() 第三步
         * 正则表达式转后缀表达式
         */
        void toRPN();

        /**
         * 将预处理后的Regex对象转NFA图
         * @brief 需要先运行this.process()
         * @return 转换后的nfa::Graph
         */
        nfa::Graph toNFAGraph();

        /**
         * 将预处理后的Regex对象转NFA图、DFA图、最小化DFA图
         * @brief 需要先运行this.process()
         */
        void formGraph();

        /**
         * 输出 正则表达式预处理 (划分token) 后的结果
         * @brief 用于debug
         */
        void printRegexSequence();

        /**
         * 输出 正则表达式转后缀表达式前处理 (加入&运算符) 后的结果
         * @brief 用于debug
         */
        void printProcessedRegex();

        /**
         * 输出 正则表达式转后缀表达式 后的结果
         * @brief 用于debug
         */
        void printRegexRPN();
    };

} // regex

#endif // REGEX_H
