/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: tree.h
iderntifier: TREE_H
abstract: 语法树的生成
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/11/11
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#include "globals2.h"
stack<Node> Nk;
void trim()
{
    int n = G.r.size();
    Lc.erase(Lc.end() - 2 * n, Lc.end());
    while (n--)
    {
        Nk.push(Nc.top());
        Nc.pop();
    }
}
Node match()
{
    Node x = Nk.top();
    Nk.pop();
    return x;
}
void merge(Node &x)
{
    Node y = match();
    if (y.token == "")
        x.kids.insert(x.kids.end(), y.kids.begin(), y.kids.end());
    else
        x.kids.push_back(y);
}
Node program()
{
    Node x = Node("start");
    merge(x);
    return x;
}
Node stmt_sequence()
{
    Node x;
    merge(x);
    if (G.r.size() == 1)
        return x;
    match();
    merge(x);
    return x;
}
Node statement()
{
    return match();
}
Node if_stmt()
{
    Node x = match();
    merge(x);
    match();
    merge(x);
    Node y = match();
    if (G.r.size() == 5)
        return x;
    merge(y);
    match();
    x.kids.push_back(y);
    return x;
}
Node repeat_stmt()
{
    Node x = match();
    merge(x);
    Node y = match();
    merge(y);
    x.kids.push_back(y);
    return x;
}
Node assign_stmt()
{
    Node t = match();
    Node x = match();
    x.kids.push_back(t);
    merge(x);
    return x;
}
Node read_stmt()
{
    Node x = match();
    merge(x);
    return x;
}
Node write_stmt()
{
    Node x = match();
    merge(x);
    return x;
}
Node exp()
{
    if (G.r.size() == 1)
        return match();
    Node t = match();
    Node x = match();
    x.kids.push_back(t);
    merge(x);
    return x;
}
Node simple_exp()
{
    if (G.r.size() == 1)
        return match();
    Node t = match();
    Node x = match();
    x.kids.push_back(t);
    merge(x);
    return x;
}
Node term()
{
    if (G.r.size() == 1)
        return match();
    Node t = match();
    Node x = match();
    x.kids.push_back(t);
    merge(x);
    return x;
}
Node factor()
{
    if (G.r.size() == 1)
        return match();
    match();
    Node x = match();
    match();
    return x;
}
Node comparison_op()
{
    return match();
}
Node addop()
{
    return match();
}
Node mulop()
{
    return match();
}
// Mini-c
Node definition_list()
{
    Node x;
    if (G.r.size() == 1)
    {
        merge(x);
        return x;
    }
    merge(x);
    merge(x);
    return x;
}
Node definition()
{
    return match();
}
Node variable_definition()
{
    Node x = match();
    merge(x);
    match();
    if (G.r.size() == 3)
        return x;
    Node y = Node("[]");
    merge(y);
    x.kids.push_back(y);
    match();
    match();
    return x;
}
Node type_indicator()
{
    return match();
}
Node function_definition()
{
    Node x = match();
    merge(x);
    match();
    merge(x);
    match();
    merge(x.kids[0]);
    return x;
}
Node parameters()
{
    Node x;
    if (G.r[0] == "void")
        return x;
    merge(x);
    return x;
}
Node parameter_list()
{
    Node x;
    if (G.r.size() == 1)
    {
        merge(x);
        return x;
    }
    merge(x);
    match();
    merge(x);
    return x;
}
Node parameter()
{
    Node x = match();
    merge(x);
    if (G.r.size() == 2)
        return x;
    x.kids.push_back(Node("[]"));
    match();
    match();
    return x;
}
Node compound_stmt()
{
    Node x;
    match();
    merge(x);
    merge(x);
    match();
    return x;
}
Node local_definitions()
{
    Node x;
    if (G.r[0] == EMPTY)
    {
        match();
        return x;
    }
    merge(x);
    merge(x);
    return x;
}
Node statement_list()
{
    Node x;
    if (G.r[0] == EMPTY)
    {
        match();
        return x;
    }
    merge(x);
    merge(x);
    return x;
}
Node expression_stmt()
{
    Node x;
    if (G.r.size() == 1)
    {
        match();
        return x;
    }
    merge(x);
    match();
    return x;
}
Node condition_stmt()
{
    Node x = match();
    match();
    merge(x);
    match();
    merge(x);
    if (G.r.size() == 5)
        return x;
    Node y = match();
    merge(y);
    x.kids.push_back(y);
    return x;
}
Node while_stmt()
{
    Node x = match();
    match();
    merge(x);
    match();
    merge(x);
    return x;
}
Node dowhile_stmt()
{
    Node x = match();
    merge(x);
    Node y = match();
    match();
    merge(y);
    match();
    match();
    x.kids.push_back(y);
    return x;
}
Node return_stmt()
{
    Node x = match();
    if (G.r.size() == 2)
    {
        match();
        return x;
    }
    merge(x);
    match();
    return x;
}
Node expression()
{
    if (G.r.size() == 1)
        return match();
    Node t = match();
    Node x = match();
    x.kids.push_back(t);
    merge(x);
    return x;
}
Node variable()
{
    if (G.r.size() == 1)
        return match();
    Node t = match();
    Node x = Node("[]");
    x.kids.push_back(t);
    match();
    merge(x);
    match();
    return x;
}
Node simple_expression()
{
    if (G.r.size() == 1)
        return match();
    Node t = match();
    Node x = match();
    x.kids.push_back(t);
    merge(x);
    return x;
}
Node additive_expression()
{
    if (G.r.size() == 1)
        return match();
    Node t = match();
    Node x = match();
    x.kids.push_back(t);
    merge(x);
    return x;
}
Node call()
{
    Node x = match();
    match();
    merge(x);
    match();
    return x;
}
Node arguments()
{
    Node x;
    if (G.r[0] == EMPTY)
    {
        match();
        return x;
    }
    merge(x);
    return x;
}
Node argument_list()
{
    Node x;
    if (G.r.size() == 1)
    {
        merge(x);
        return x;
    }
    merge(x);
    match();
    merge(x);
    return x;
}
Node relop()
{
    return match();
}
Node genNode()
{
    trim();
    if (G.l == "program")
        return program();
    else if (G.l == "stmt-sequence")
        return stmt_sequence();
    else if (G.l == "statement")
        return statement();
    else if (G.l == "if-stmt")
        return if_stmt();
    else if (G.l == "repeat-stmt")
        return repeat_stmt();
    else if (G.l == "assign-stmt")
        return assign_stmt();
    else if (G.l == "read-stmt")
        return read_stmt();
    else if (G.l == "write-stmt")
        return write_stmt();
    else if (G.l == "exp")
        return exp();
    else if (G.l == "simple-exp")
        return simple_exp();
    else if (G.l == "comparison-op")
        return comparison_op();
    else if (G.l == "addop")
        return addop();
    else if (G.l == "term")
        return term();
    else if (G.l == "mulop")
        return mulop();
    else if (G.l == "factor")
        return factor();
    else if (G.l == "definition-list")
        return definition_list();
    else if (G.l == "definition")
        return definition();
    else if (G.l == "variable-definition")
        return variable_definition();
    else if (G.l == "function-definition")
        return function_definition();
    else if (G.l == "type-indicator")
        return type_indicator();
    else if (G.l == "parameters")
        return parameters();
    else if (G.l == "compound-stmt")
        return compound_stmt();
    else if (G.l == "parameter-list")
        return parameter_list();
    else if (G.l == "parameter")
        return parameter();
    else if (G.l == "local-definitions")
        return local_definitions();
    else if (G.l == "statement-list")
        return statement_list();
    else if (G.l == "expression-stmt")
        return expression_stmt();
    else if (G.l == "condition-stmt")
        return condition_stmt();
    else if (G.l == "while-stmt")
        return while_stmt();
    else if (G.l == "dowhile-stmt")
        return dowhile_stmt();
    else if (G.l == "return-stmt")
        return return_stmt();
    else if (G.l == "expression-stmt")
        return expression_stmt();
    else if (G.l == "expression")
        return expression();
    else if (G.l == "variable")
        return variable();
    else if (G.l == "simple-expression")
        return simple_expression();
    else if (G.l == "additive-expression")
        return additive_expression();
    else if (G.l == "relop")
        return relop();
    else if (G.l == "call")
        return call();
    else if (G.l == "arguments")
        return arguments();
    else if (G.l == "argument-list")
        return argument_list();
    else
    {
        cerr << "未知文法左部:" << G.l << '\n';
        exit(1);
    }
}