#include "code_generator.h"

/**
 * 生成缩进
 * @param tabNum 缩进数量
 * @return 缩进串
 */
string tabGenerate(int tabNum)
{
    stringstream ss;
    for (int i = 0; i < tabNum; i++)
    {
        ss << baseTab;
    }
    return ss.str();
}

/**
 * 字符串分割
 * @param text 原文本
 * @param sep 分割字符
 * @return 分割后的字符串序列
 */
vector<std::string> split(const string &text, char sep)
{
    vector<std::string> tokens;
    istringstream tokenStream(text);
    string token;
    while (getline(tokenStream, token, sep))
    {
        tokens.push_back(token);
    }
    return tokens;
}

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
                               const int &baseTabNum)
{
    stringstream ss;
    ss << tabGenerate(baseTabNum) << "switch (" << condition << ") {" << '\n';
    for (const auto &caseStatement : caseStatements){
        ss << tabGenerate(baseTabNum + 1) << "case " << caseStatement.first << ":" << '\n';
        for (const auto &statement : caseStatement.second)
            ss << tabGenerate(baseTabNum + 2) << statement << '\n';
        ss << tabGenerate(baseTabNum + 2) << "break;" << '\n';
    }
    ss << tabGenerate(baseTabNum + 1) << "default:" << '\n';
    for (const auto &statement : defaultStatement)
        ss << tabGenerate(baseTabNum + 2) << statement << '\n';
    ss << tabGenerate(baseTabNum + 2) << "break;" << '\n';
    ss << tabGenerate(baseTabNum) << "}" << '\n';
    return ss.str();
}

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
                                               const int &baseTabNum)
{
    string code = generateSwitchStatement(condition, caseStatements, defaultStatement, baseTabNum);
    return split(code);
}

/**
 * 生成if语句字符串
 * @param caseStatements if/else if条件及语句 [ 即 if/else if (???) { ??? } ]
 * @param elseStatement else语句 [ 即 else { ??? } ]
 * @param baseTabNum 所有语句的基础缩进数
 * @return if语句字符串
 */
string generateIfStatement(const CaseStatementsPairList &caseStatements,
                           const Statements &elseStatement,
                           const int &baseTabNum)
{
    stringstream ss;

    if (caseStatements.empty())
    {
        for (const auto &statement : elseStatement)
        {
            ss << tabGenerate(baseTabNum) << statement << '\n';
        }
        return ss.str();
    }

    bool generatedIf = false;

    for (const auto &caseStatement : caseStatements)
    {
        if (generatedIf)
        {
            ss << "else if (" << caseStatement.first << ") {" << '\n';
        }
        else
        {
            ss << tabGenerate(baseTabNum) << "if (" << caseStatement.first << ") {" << '\n';
            generatedIf = true;
        }
        for (const auto &statement : caseStatement.second)
        {
            ss << tabGenerate(baseTabNum + 1) << statement << '\n';
        }
        ss << tabGenerate(baseTabNum) << "} ";
    }

    ss << "else {" << '\n';
    for (const auto &statement : elseStatement)
    {
        ss << tabGenerate(baseTabNum + 1) << statement << '\n';
    }
    ss << tabGenerate(baseTabNum) << "}" << '\n';

    return ss.str();
}

/**
 * 生成if语句字符串序列
 * @param caseStatements if/else if条件及语句 [ 即 if/else if (???) { ??? } ]
 * @param elseStatement else语句 [ 即 else { ??? } ]
 * @param baseTabNum 所有语句的基础缩进数
 * @return if语句字符串序列
 */
vector<string> generateIfStatementSequence(const CaseStatementsPairList &caseStatements,
                                           const Statements &elseStatement,
                                           const int &baseTabNum)
{
    string code = generateIfStatement(caseStatements, elseStatement, baseTabNum);
    return split(code);
}
