/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: Regex.cpp
iderntifier: Regex_CPP
abstract: 正则表达式处理类的实现
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

#include "Regex.h"
#include "../globals.h"

// 正则表达式的初始化
/**
 * 构造函数, 输入单条正则表达式进行Regex对象构造
 * @param regex 正则表达式文本, 格式 NAME->REGEX
 */
regex::Regex::Regex(string regex)
{
    int loc = -1;
    for (int i = 0; i < regex.length() - 1; i++)
    {
        if (regex[i] == '-' && regex[i + 1] == '>')
        {
            loc = i;
            break;
        }
    }

    this->name = regex.substr(0, loc);
    this->regex = regex.substr(loc + 2);

    this->nfaGraph = nullptr;
    this->dfaGraph = nullptr;
    this->minDfaGraph = nullptr;
}

/**
 * 对Regex对象进行处理:
 * 1. 正则表达式预处理 (划分token)
 * 2. 正则表达式转后缀表达式前处理 (加入&运算符)
 * 3. 正则表达式转后缀表达式
 */
void regex::Regex::process()
{
    this->preprocess();
    this->joinSymbol();
    this->toRPN();
}

/**
 * this.process() 第一步
 * 正则表达式预处理 (划分token)
 */
void regex::Regex::preprocess()
{
    string temp;
    for (int regexIndex = 0; regexIndex < this->regex.length(); regexIndex++)
    {
        char regexCh = this->regex[regexIndex];
        if (isalnum(regexCh) || regexCh == '_')
        {
            // 如果是字母数字，先扔到temp里
            temp += regexCh;
            continue;
        }
        else if (regexCh == ' ')
        {
            // 如果是空格，判断temp是否为表达式关键词，
            // 如果是则将关键词push进序列，
            // 如果不是则将目前temp内已有的字符逐个push进序列（清缓存）
            bool find = KEYWORDS.find(temp) != KEYWORDS.end() || identifier.count(temp) > 0;
            if (find)
            {
                this->regexSequence.push_back(temp);
                temp = "";
            }
            else if (!temp.empty())
            {
                for (int tempIndex = 0; tempIndex < temp.length(); tempIndex++)
                {
                    string chStr(1, temp[tempIndex]);
                    this->regexSequence.push_back(chStr);
                    if (tempIndex != temp.length() - 1)
                    {
                        this->regexSequence.push_back(AND);
                    }
                }
                temp = "";
            }
            continue;
        }
        else if (regexCh == '\\')
        {
            // 如果是转义字符，直接把后面的字符加上，然后push进序列
            string chStr(1, regexCh);
            if (regexIndex != this->regex.length() - 1)
            {
                chStr += this->regex[regexIndex + 1];
                regexIndex++;
            }
            this->regexSequence.push_back(chStr);
            continue;
        }
        else
        {
            // 如果是特殊符号，先清缓存，再把特殊符号push进序列
            bool find = KEYWORDS.find(temp) != KEYWORDS.end() || identifier.count(temp) > 0;
            if (find)
            {
                this->regexSequence.push_back(temp);
                temp = "";
            }
            else if (!temp.empty())
            {
                for (int tempIndex = 0; tempIndex < temp.length(); tempIndex++)
                {
                    string chStr(1, temp[tempIndex]);
                    this->regexSequence.push_back(chStr);
                    if (tempIndex != temp.length() - 1)
                    {
                        this->regexSequence.push_back(AND);
                    }
                }
                temp = "";
            }
            string chStr(1, regexCh);
            this->regexSequence.push_back(chStr);
        }
    }
    if (!temp.empty())
    {
        bool find = KEYWORDS.find(temp) != KEYWORDS.end() || identifier.count(temp) > 0;
        if (find)
        {
            this->regexSequence.push_back(temp);
            temp = "";
        }
        else
        {
            for (int tempIndex = 0; tempIndex < temp.length(); tempIndex++)
            {
                string chStr(1, temp[tempIndex]);
                this->regexSequence.push_back(chStr);
                if (tempIndex != temp.length() - 1)
                {
                    this->regexSequence.push_back(AND);
                }
            }
        }
    }
}

// 必须要连接的条件
const set<string> JOIN_CONDITION = {
    "WORD+WORD", "WORD+(", "WORD+[", ")+WORD", "*+WORD", "+WORD", "?+WORD",
    "*+(", "+(", "?+(", ")+(", "]+WORD", "WORD+]", ")+[", "[+WORD"};

// 判断是否需要连接
bool mustJoin(const string &condition)
{
    return JOIN_CONDITION.find(condition) != JOIN_CONDITION.end();
}

/**
 * this.process() 第二步
 * 正则表达式转后缀表达式前处理 (加入&运算符)
 */
void regex::Regex::joinSymbol(){
    if (this->regexSequence.size() == 1){
        this->processedRegexSequence = {this->regexSequence[0]};
        return;
    }
    string first, second;
    for (int seqIndex = 0; seqIndex < this->regexSequence.size() - 1; seqIndex++){
        first = this->regexSequence[seqIndex];
        second = this->regexSequence[seqIndex + 1];
        this->processedRegexSequence.push_back(first);
        string condition;
        condition += OPERATOR_PRIORITY.find(first) == OPERATOR_PRIORITY.end() ? "WORD" : first;
        condition += "+";
        condition += OPERATOR_PRIORITY.find(second) == OPERATOR_PRIORITY.end() ? "WORD" : second;
        if (mustJoin(condition))
            this->processedRegexSequence.push_back(AND);
    }
    this->processedRegexSequence.push_back(second);
}

/**
 * this.process() 第三步
 * 正则表达式转后缀表达式
 */
void regex::Regex::toRPN(){
    stack<string> operatorStack;
    for (const string &regexSequenceItem : this->processedRegexSequence){
        if (OPERATOR_PRIORITY.find(regexSequenceItem) != OPERATOR_PRIORITY.end()){
            // 为操作符
            if (operatorStack.empty())
                operatorStack.push(regexSequenceItem);
            else{
                if (regexSequenceItem == LEFT_BRACKET)
                    // 为左括号
                    operatorStack.push(regexSequenceItem);
                else if (regexSequenceItem == RIGHT_BRACKET){
                    // 为右括号
                    string topOperator = operatorStack.top();
                    operatorStack.pop();
                    while (topOperator != LEFT_BRACKET){
                        this->regexRPN.push_back(topOperator);
                        if (operatorStack.empty())
                            break;
                        topOperator = operatorStack.top();
                        operatorStack.pop();
                    }
                }
                else if (regexSequenceItem == CHAR_CLASS_START || regexSequenceItem == CHAR_CLASS_END)
                    // 中括号的特别处理
                    operatorStack.push(regexSequenceItem);
                else{
                    string topOperator = operatorStack.top();
                    if (regexSequenceItem == CLOSURE || regexSequenceItem == OPTION)
                        this->regexRPN.push_back(regexSequenceItem);
                    else if (OPERATOR_PRIORITY.at(regexSequenceItem) > OPERATOR_PRIORITY.at(topOperator))
                        operatorStack.push(regexSequenceItem);
                    else{
                        if (topOperator == LEFT_BRACKET){
                            operatorStack.push(regexSequenceItem);
                            continue;
                        }
                        while (OPERATOR_PRIORITY.at(regexSequenceItem) <= OPERATOR_PRIORITY.at(topOperator)){
                            operatorStack.pop();
                            this->regexRPN.push_back(topOperator);
                            if (operatorStack.empty() || operatorStack.top() == LEFT_BRACKET)
                                break;
                            topOperator = operatorStack.top();
                        }
                        operatorStack.push(regexSequenceItem);
                    }
                }
            }
        }
        else
            // 为操作数
            this->regexRPN.push_back(regexSequenceItem);
    }
    // 处理完毕，清空stack
    while (!operatorStack.empty()){
        string topOperator = operatorStack.top();
        operatorStack.pop();
        this->regexRPN.push_back(topOperator);
    }
}

/**
 * 将预处理后的Regex对象转NFA图
 * @brief 需要先运行this.process()
 * @return 转换后的nfa::Graph
 */
nfa::Graph regex::Regex::toNFAGraph()
{
    if (this->regexRPN.empty())
        return nfa::Graph(this->name, E);
    stack<nfa::Graph> processStack;
    processStack.emplace(this->name, this->regexRPN[0]);
    for (int RPNIndex = 1; RPNIndex < this->regexRPN.size(); RPNIndex++){
        if (OPERATOR_PRIORITY.find(this->regexRPN[RPNIndex]) == OPERATOR_PRIORITY.end())
            processStack.emplace(this->name, this->regexRPN[RPNIndex]);
        else{
            string operatorStr = this->regexRPN[RPNIndex];
            if (operatorStr == OR){
                nfa::Graph second = processStack.top();
                processStack.pop();
                nfa::Graph first = processStack.top();
                processStack.pop();
                first.orOperator(second);
                processStack.push(first);
            }
            else if (operatorStr == AND){
                nfa::Graph second = processStack.top();
                processStack.pop();
                nfa::Graph first = processStack.top();
                processStack.pop();
                first.andOperator(second);
                processStack.push(first);
            }
            else if (operatorStr == CLOSURE){
                nfa::Graph first = processStack.top();
                processStack.pop();
                first.closureOperator();
                processStack.push(first);
            }
            else if (operatorStr == POSITIVE_CLOSURE){
                nfa::Graph first = processStack.top();
                processStack.pop();
                first.positiveClosureOperator(); // 调用正闭包操作
                processStack.push(first);
            }
            else if (operatorStr == OPTION){
                nfa::Graph first = processStack.top();
                processStack.pop();
                first.optionOperator();
                processStack.push(first);
            }
        }
    }
    return processStack.top();
}

/**
 * 将预处理后的Regex对象转NFA图、DFA图、最小化DFA图
 * @brief 需要先运行this.process()
 */
void regex::Regex::formGraph()
{
    this->nfaGraph = new nfa::Graph(this->toNFAGraph());
    this->dfaGraph = new dfa::Graph(dfa::Graph::fromNFA(*this->nfaGraph));
    this->minDfaGraph = new dfa::MinGraph(this->dfaGraph->minimize());
}

/**
 * 输出 正则表达式预处理 (划分token) 后的结果
 * @brief 用于debug
 */
void regex::Regex::printRegexSequence()
{
    cout << "RegexSequence: [";
    for (int regexSequenceIndex = 0; regexSequenceIndex < this->regexSequence.size(); regexSequenceIndex++)
    {
        cout << "\"" << this->regexSequence[regexSequenceIndex] << "\"";
        if (regexSequenceIndex != this->regexSequence.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]\n";
}

/**
 * 输出 正则表达式转后缀表达式前处理 (加入&运算符) 后的结果
 * @brief 用于debug
 */
void regex::Regex::printProcessedRegex()
{
    cout << "ProcessedRegex: [";
    for (int processedRegexIndex = 0;
         processedRegexIndex < this->processedRegexSequence.size(); processedRegexIndex++)
    {
        cout << "\"" << this->processedRegexSequence[processedRegexIndex] << "\"";
        if (processedRegexIndex != this->processedRegexSequence.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]\n";
}

/**
 * 输出 正则表达式转后缀表达式 后的结果
 * @brief 用于debug
 */
void regex::Regex::printRegexRPN()
{
    cout << "RegexRPN: [";
    for (int regexRPNIndex = 0; regexRPNIndex < this->regexRPN.size(); regexRPNIndex++)
    {
        cout << "\"" << this->regexRPN[regexRPNIndex] << "\"";
        if (regexRPNIndex != this->regexRPN.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]\n";
}
