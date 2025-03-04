#include "code_generator.h"
#include "min_DFA_graph.h"

/**
 * 构造函数
 * @param name 图名称
 * @param start 图开始节点序号
 * @param end 图终止节点序号
 */
dfa::MinGraph::MinGraph(string name, int start, set<int> end) : name(std::move(name)), start(start),
                                                                end(std::move(end))
{
}

/**
 * 向图添加边
 * @param addedEdge 要添加的边集
 */
void dfa::MinGraph::addEdge(const vector<MinEdge> &addedEdge)
{
    for (const MinEdge &edge : addedEdge)
    {
        this->edges.push_back(edge);
    }
}

/**
 * 将dfa::MinGraph转为C++代码
 * @param identifier 所有标识符
 * @return 可执行的C++代码文本
 */
string dfa::MinGraph::toCode(const set<string> &identifier)
{
    stringstream codeStream;

    // 函数体
    codeStream << format("bool {}(ifstream &code, string &token) {{", this->name) << '\n';

    codeStream << tabGenerate(1) << format("int state = {};", this->start) << '\n';
    codeStream << tabGenerate(1) << "char ch;" << '\n';
    codeStream << tabGenerate(1) << "stringstream temp;" << '\n';
    codeStream << tabGenerate(1) << format(R"!(set<int> endState = {};)!", toString(this->end)) << '\n';

    // 主循环
    codeStream << tabGenerate(1) << "while (code.get(ch)) {\n";

    codeStream << tabGenerate(2) << "if (ch == '\\r') {\n"
               << tabGenerate(2) << "    continue;\n"
               << tabGenerate(2) << "}\n";

    // 构建CaseStatements
    CaseStatementsPairList caseStatements;
    Statements defaultStatements = {"temp << ch;", "move(code, temp);", "return false;"};
    for (const auto &convertMapLine : this->convertMap)
    {
        CaseStatementsPair caseStatementsPair;
        // 当前结点Id
        caseStatementsPair.first = to_string(convertMapLine.first);

        // 当前结点的所有转换-if语句
        CaseStatementsPairList ifStatements;
        Statements elseStatements;
        for (int convertMapLineIndex = 0; convertMapLineIndex < convertMapLine.second.size(); convertMapLineIndex++)
        {
            // 下一个转换节点Id
            int convertMapItem = convertMapLine.second[convertMapLineIndex];

            // if语句Pair
            CaseStatementsPair ifStatementPair;
            if (convertMapItem != -1)
            {
                if (regex::KEYWORDS.count(indexToLabelMap[convertMapLineIndex]) > 0)
                {
                    ifStatementPair.first = regex::KEYWORDS_JUDGE_FUNC.at(indexToLabelMap[convertMapLineIndex]) +
                                            "(ch)";
                }
                else if (identifier.count(indexToLabelMap[convertMapLineIndex]) > 0)
                {
                    ifStatementPair.first = indexToLabelMap[convertMapLineIndex] + "(code, token)";
                }
                else
                {
                    // if (indexToLabelMap[convertMapLineIndex].starts_with('^')) {
                    //     // 携带非运算符
                    //     ifStatementPair.first = "ch != '" + indexToLabelMap[convertMapLineIndex].substr(1) + "'";
                    // }
                    /* else {*/
                    ifStatementPair.first = "ch == '" + indexToLabelMap[convertMapLineIndex] + "'";
                    /*}*/
                }
                // 结点转换
                ifStatementPair.second.emplace_back("state = " + to_string(convertMapItem) + ";");
                ifStatements.push_back(ifStatementPair);
            }
        }

        // 根据该节点是否为接受节点，如果是则遇other时执行accept
        if (this->end.count(convertMapLine.first) > 0)
        {
            elseStatements = {"code.seekg(-1, ios::cur);", "token = temp.str();", "return true;"};
        }
        else
        {
            elseStatements = {"temp << ch;", "move(code, temp);", "return false;"};
        }

        caseStatementsPair.second = generateIfStatementSequence(ifStatements, elseStatements);

        caseStatementsPair.second.emplace_back("temp << ch;");

        caseStatements.push_back(caseStatementsPair);
    }

    codeStream << generateSwitchStatement("state", caseStatements, defaultStatements, 2);

    // 补全右花括号
    // while
    codeStream << tabGenerate(1) << "}" << '\n';

    codeStream << tabGenerate(1) << "if (endState.count(state) > 0) {\n"
               << tabGenerate(2) << "    token = temp.str();\n"
               << tabGenerate(2) << "    return true;\n"
               << tabGenerate(1) << "}\n"
               << tabGenerate(1) << "else {\n"
               << tabGenerate(2) << "    move(code, temp);\n"
               << tabGenerate(2) << "    return false;\n"
               << tabGenerate(1) << "}\n";
    // 最外层函数定义
    codeStream << "}" << '\n';

    return codeStream.str();
}

/**
 * 打印所有边
 * @brief 用于debug
 */
void dfa::MinGraph::printEdges()
{
    cout << "DFA::MinGraph(" << this->start << " -> {";
    for (int endId : this->end)
    {
        cout << endId << ", ";
    }
    cout << "})" << '\n';
    for (MinEdge edge : this->edges)
    {
        cout << edge.toString() << '\n';
    }
    cout << "End print graph." << '\n';
}
