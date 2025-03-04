/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: edge2table.h
iderntifier: edge2table_H
abstract: NFA/DFA图的边集转换表
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/10/18
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#ifndef CPP_EDGES2TABLE_H
#define CPP_EDGES2TABLE_H

#include <QTableWidget>
#include <QHeaderView>
#include <map>
#include <vector>
#include <iostream>
#include "set_utils.h"
using namespace std;

/**
 * NFA图 边集 转 转换表
 * @param edges NFA图的边集
 * @param lineNames 空vector, 用于保存行名
 * @param columnNames 空vector, 用于保存列名
 * @return 转换表
 */
vector<vector<string>> convert(const vector<nfa::Edge> &edges, int start, int end, vector<string> &lineNames, vector<string> &columnNames)
{
    // 图表的行列名称
    set<string> labelSet;
    set<int> idSet;
    for (const nfa::Edge &edge : edges)
    {
        idSet.insert(edge.start.id);
        idSet.insert(edge.end.id);

        labelSet.insert(edge.label);
    }

    // 列名索引
    map<string, int> labelIndexMap;
    int nextLabelIndex = 0;
    for (const string &label : labelSet)
    {
        labelIndexMap.insert({label, nextLabelIndex});
        nextLabelIndex++;

        columnNames.push_back(label);
    }

    // 行名索引
    map<int, int> idIndexMap;
    int nextIdIndex = 0;
    for (const int &id : idSet)
    {
        idIndexMap.insert({id, nextIdIndex});
        nextIdIndex++;

        if (id == start)
        {
            lineNames.push_back(to_string(id) + " -");
        }
        else if (id == end)
        {
            lineNames.push_back(to_string(id) + " +");
        }
        else
        {
            lineNames.push_back(to_string(id) + "  ");
        }
    }

    // 初始化转换表
    // 转换表索引格式 convertTable[ID_INDEX][LABEL_INDEX]
    vector<vector<string>> convertTable(nextIdIndex);
    for (int idIndex = 0; idIndex < nextIdIndex; idIndex++)
    {
        convertTable[idIndex] = vector<string>(nextLabelIndex);
    }

    // 向转换表内填充内容
    for (const auto &edge : edges)
    {
        convertTable[idIndexMap[edge.start.id]][labelIndexMap[edge.label]] += to_string(edge.end.id) + ", ";
    }

    return convertTable;
}

/**
 * DFA图 边集 转 转换表
 * @param edges DFA图的边集
 * @param lineNames 空vector, 用于保存行名
 * @param columnNames 空vector, 用于保存列名
 * @return 转换表
 */
vector<vector<string>> convert(const vector<dfa::Edge> &edges, int start, int end, vector<string> &lineNames, vector<string> &columnNames)
{
    // 图表的行列名称
    set<string> labelSet;
    set<set<int>> idSet;
    for (const dfa::Edge &edge : edges)
    {
        idSet.insert(edge.start.ids);
        idSet.insert(edge.end.ids);

        labelSet.insert(edge.label);
    }

    // 列名索引
    map<string, int> labelIndexMap;
    int nextLabelIndex = 0;
    for (const string &label : labelSet)
    {
        labelIndexMap.insert({label, nextLabelIndex});
        nextLabelIndex++;

        columnNames.push_back(label);
    }

    // 行名索引
    map<set<int>, int> idIndexMap;
    int nextIdIndex = 0;
    for (const set<int> &id : idSet)
    {
        idIndexMap.insert({id, nextIdIndex});
        nextIdIndex++;

        if (id.contains(start))
        {
            lineNames.push_back(toString(id) + " -");
        }
        else if (id.contains(end))
        {
            lineNames.push_back(toString(id) + " +");
        }
        else
        {
            lineNames.push_back(toString(id) + "  ");
        }
    }

    // 初始化转换表
    // 转换表索引格式 convertTable[ID_INDEX][LABEL_INDEX]
    vector<vector<string>> convertTable(nextIdIndex);
    for (int idIndex = 0; idIndex < nextIdIndex; idIndex++)
    {
        convertTable[idIndex] = vector<string>(nextLabelIndex);
    }

    // 向转换表内填充内容
    for (const auto &edge : edges)
    {
        convertTable[idIndexMap[edge.start.ids]][labelIndexMap[edge.label]] += toString(edge.end.ids) + ", ";
    }

    return convertTable;
}

/**
 * 最小化DFA图 边集 转 转换表
 * @param edges 最小化DFA图的边集
 * @param lineNames 空vector, 用于保存行名
 * @param columnNames 空vector, 用于保存列名
 * @return 转换表
 */
vector<vector<string>> convert(const vector<dfa::MinEdge> &edges, int start, set<int> end, vector<string> &lineNames, vector<string> &columnNames)
{
    // 图表的行列名称
    set<string> labelSet;
    set<int> idSet;
    for (const dfa::MinEdge &edge : edges)
    {
        idSet.insert(edge.start);
        idSet.insert(edge.end);

        labelSet.insert(edge.label);
    }

    // 列名索引
    map<string, int> labelIndexMap;
    int nextLabelIndex = 0;
    for (const string &label : labelSet)
    {
        labelIndexMap.insert({label, nextLabelIndex});
        nextLabelIndex++;

        columnNames.push_back(label);
    }

    // 行名索引
    map<int, int> idIndexMap;
    int nextIdIndex = 0;
    for (const int &id : idSet)
    {
        idIndexMap.insert({id, nextIdIndex});
        nextIdIndex++;

        if (id == start)
        {
            lineNames.push_back(to_string(id) + " -");
        }
        else if (end.contains(id))
        {
            lineNames.push_back(to_string(id) + " +");
        }
        else
        {
            lineNames.push_back(to_string(id) + "  ");
        }
    }

    // 初始化转换表
    // 转换表索引格式 convertTable[ID_INDEX][LABEL_INDEX]
    vector<vector<string>> convertTable(nextIdIndex);
    for (int idIndex = 0; idIndex < nextIdIndex; idIndex++)
    {
        convertTable[idIndex] = vector<string>(nextLabelIndex);
    }

    // 向转换表内填充内容
    for (const auto &edge : edges)
    {
        convertTable[idIndexMap[edge.start]][labelIndexMap[edge.label]] += to_string(edge.end) + ", ";
    }

    return convertTable;
}

/**
 * 将convertTable, lineNames, columnNames转换成QTableWidget
 * @param convertTable 转换表
 * @param lineNames 行名
 * @param columnNames 列名
 * @return QT表格对象
 */
QTableWidget *toTableWidget(const vector<vector<string>> &convertTable, vector<string> &lineNames, vector<string> &columnNames)
{
    // 将vector<string>转QStringList
    QStringList qStringListOfLineNames;
    for (const string &lineName : lineNames)
    {
        qStringListOfLineNames.append(QString::fromStdString(lineName));
    }
    QStringList qStringListOfColumnNames;
    for (const string &columnName : columnNames)
    {
        qStringListOfColumnNames.append(QString::fromStdString(columnName));
    }

    // 设置行数、列数
    auto qtw = new QTableWidget(qStringListOfLineNames.size(), qStringListOfColumnNames.size());
    //    qtw.setRowCount(qStringListOfLineNames.size());
    //    qtw.setColumnCount(qStringListOfColumnNames.size());

    // 设置表格表头
    qtw->setHorizontalHeaderLabels(qStringListOfColumnNames);
    qtw->setVerticalHeaderLabels(qStringListOfLineNames);

    // 设置列宽度
    qtw->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    // 填充表格
    for (int i = 0; i < convertTable.size(); i++)
    {
        for (int j = 0; j < convertTable[i].size(); j++)
        {
            auto item = new QTableWidgetItem(QString::fromStdString(convertTable[i][j]));
            qtw->setItem(i, j, item);
        }
    }

    return qtw;
}

#endif // CPP_EDGES2TABLE_H