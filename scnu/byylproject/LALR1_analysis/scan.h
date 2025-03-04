/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: scan.h
iderntifier: SCAN_H
abstract: 文法扫描器
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/11/4
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#include "util.h"

typedef enum
{
    START,
    DONE,
    NONTERM,
    TERMINAL,
    KEEP,
    OR,
    NOTEND,
    ENDLINE,
    ENDLINES
} Scan_State;
// START 开始接收字符
// DONE 完成一个Token的接收
// NONTERM 当前要接收的Token是非终结符
// TERMINAL 当前要接收的Token是终结符
// KEEP 持续接受字符，遇到空格停止(在第二种书写形式中使用)
// OR '|'或，特殊字符
// NOTEND 还没结束扫描的状态
// ENDLINE 扫描完当前行的状态
// ENDLINES 扫描完全部行lines的状态

Scan_State scanState = START, endState = NOTEND;
int lineID = 0, charID = 0;
GRAM newGram;

int nextChar()
{
    if (charID >= lines[lineID].size())
    {
        endState = (lineID >= lines.size() - 1 ? ENDLINES : ENDLINE);
        return EOF;
    }
    return lines[lineID][charID++];
}

void backChar()
{
    --charID;
    if (charID < 0)
        charID = 0;
}

string cleanBlank(string s)
{ // 清除前后缀空格
    int i = s.find_first_not_of(" \t\n\r\f\v");
    int j = s.find_last_not_of(" \t\n\r\f\v");
    return i == -1 ? "" : s.substr(i, j - i + 1);
}

// 这里偷个懒，直接把"->"左边的非空格字符都当做文法的左部
void getLeftName()
{
    string name; // 文法推导左式只能是字母、"'"或"-"组成
    for (int i = 0; i < lines[lineID].size(); ++i)
    {
        if (lines[lineID][i] == '-' && lines[lineID][i + 1] == '>')
        {
            newGram.name = cleanBlank(name);
            charID = i + 2;
            return;
        }
        name += lines[lineID][i];
    }
}

void getRightTokenType1()
{
    bool save;
    string token;
    scanState = START;
    endState = NOTEND;
    while (scanState != DONE)
    {
        char c = nextChar();
        save = true; // 保存字符，c追加到token后
        switch (scanState)
        {
        case START:
            if (isupper(c))
                scanState = NONTERM; // 非终结符
            else if (c == '|')
                scanState = OR;
            else if (isBlank(c))
                save = false;
            else if (c == EOF) // 一开始就结束，说明是空串
                return;
            else
                scanState = TERMINAL;
            break;
        case NONTERM:
            if (c != '\'')
            {
                backChar();
                save = false;
                scanState = DONE;
            }
            break;
        case TERMINAL:
            backChar();
            save = false;
            scanState = DONE;
            break;
        case OR:
            backChar();
            save = false;
            scanState = DONE;
            break;
        case DONE:
        default: /* should never happen */
            cout << "Scanner Bug: state = " << scanState << '\n';
            scanState = DONE;
            break;
        }
        if (save)
            token += c;
    }
    newGram.tokens.push_back(token);
}

void getRightTokenType2()
{
    bool save;
    string token;
    scanState = START;
    endState = NOTEND;
    while (scanState != DONE)
    {
        char c = nextChar();
        save = true; // 保存字符，c追加到token后
        switch (scanState)
        {
        case START:
            if (isBlank(c))
                save = false;
            else if (c == '|')
                scanState = OR;
            else if (c == EOF) // 一开始就结束，说明是空串
                return;
            else
                scanState = KEEP;
            break;
        case KEEP:
            if (isBlank(c) || c == EOF)
            {
                save = false;
                scanState = DONE;
            }
            break;
        case OR:
            backChar();
            save = false;
            scanState = DONE;
            break;
        case DONE:
        default: /* should never happen */
            cout << "Scanner Bug: state = " << scanState << '\n';
            scanState = DONE;
            break;
        }
        if (save)
            token += c;
    }
    newGram.tokens.push_back(token);
}
void getRightToken()
{
    gramType == 1 ? getRightTokenType1() : getRightTokenType2();
}
// 如果第一个非终结符的第一个字符是大写字母，则Type=1，如果是小写字母，则Type=2
void getGramType()
{
    gramType = isupper(lines[0][0]) ? 1 : 2;
}

void scanGrams()
{
    getGramType();
    while (endState != ENDLINES)
    {
        endState = NOTEND;
        getLeftName();
        while (endState == NOTEND)
            getRightToken();
        Grams.push_back(newGram);
        newGram.tokens.clear();
        ++lineID, charID = 0;
    }
}
