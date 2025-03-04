/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: Regex_group.cpp
iderntifier: Regex_group_CPP
abstract: 正则表达式组处理类的实现
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

#include "Regex_group.h"

/**
 * 构造函数
 * @param regexString 一个包含所有正则表达式的字符串, 使用\\n分隔正则表达式
 * @see regex::Regex
 */
regex::RegexGroup::RegexGroup(const string &regexString)
{
    vector<string> regexStringList = split(regexString);
    for (const string &regexSplitString : regexStringList)
    {
        if (regexSplitString.empty())
        {
            continue;
        }
        this->regexList.emplace_back(regexSplitString);
        this->IDENTIFIER.insert(this->regexList[this->regexList.size() - 1].name);
    }
    for (Regex &regexObject : this->regexList)
    {
        regexObject.identifier = this->IDENTIFIER;
        regexObject.process();
        regexObject.formGraph();
    }
}

/**
 * 将regex::RegexGroup转为C++代码
 * @return 可执行的C++代码文本
 */
string regex::RegexGroup::toCode()
{
    stringstream ss;

    const string inputFilePath = "sample.tny";
    const string outputFilePath = "sample.lex";

    // 宏定义
    ss << "#include <bits/stdc++.h>" << '\n';
    ss << '\n';

    // 命名空间
    ss << "using namespace std;" << '\n';
    ss << '\n';

    // 功能函数定义
    ss << "inline void move(ifstream &fileTemp, stringstream &funcTemp) {\n"
          "    fileTemp.seekg(-(int)funcTemp.str().length(), ios::cur);\n"
          "    funcTemp.clear();\n"
          "    funcTemp.str(\"\");\n"
          "}\n"
          "\n";

    for (Regex regexObject : this->regexList)
    {
        ss << format("bool {}(ifstream &code, string &token); ", regexObject.name) << '\n';
    }
    CaseStatementsPairList caseStatementsPairList;
    // 插入每一个regex的子函数
    for (Regex regexObject : this->regexList)
    {
        ss << regexObject.minDfaGraph->toCode(this->IDENTIFIER) << '\n';

        caseStatementsPairList.push_back({format(R"!({}(ifs, token))!", regexObject.name),
                                          {format(R"!(ofs << token << " -> {}" << '\n';)!", regexObject.name)}});
    }

    // main函数
    ss << format("int main() {{\n"
                 "    ifstream ifs(\"{}\", ios::in | ios::binary);\n"
                 "    ofstream ofs(\"{}\", ios::out | ios::binary);\n"
                 "    string token;\n"
                 "    int line = 1;\n"
                 "\n",
                 inputFilePath,
                 outputFilePath);
    ss << "    while (ifs.peek() != EOF) {\n"
          "        if (ifs.peek() == ' ' || ifs.peek() == '\\n') {\n"
          "            ifs.get();\n"
          "            continue;\n"
          "        } else if (ifs.peek() == '\\r') {\n"
          "            ifs.get();\n"
          "            line++;\n"
          "            continue;\n"
          "        }\n"
       << generateIfStatement(caseStatementsPairList,
                              {"string errorText;",
                               R"(while (ifs.peek() != ' ' && ifs.peek() != '\n' && ifs.peek() != '\r') {)",
                               "    errorText += char(ifs.get());",
                               "}",
                               R"(ofs << "error at Line "<< line <<" near: " << errorText << '\n';)"},
                              2)
       << "    }\n";
    ss << "    ifs.close();" << '\n'
       << "    ofs.close();" << '\n';
    ss << "}" << '\n';

    return ss.str();
}
