/*
(1)版权信息：
// Copyright (c) 2024 Zeming He
// All rights reserved.
*/

/*
(2)文件名称，标识符，模块功能说明：
filename: analysis.h
iderntifier: ANALYSIS_H
abstract: LR(1)分析表的构建
*/

/*
(3)当前版本号，作者，完成日期：
version: 1.0
author: Zeming He
completed date: 2024/11/8
*/

/*
(4)版本历史信息：
history version:(None)
*/

#pragma once
#include "globals1.h"
#include "fset.h"

// LR(1)构建顺序：
// 构建项目集→构建DFA→构建分析表
vector<LR1ITEM> LR1Items;
vector<LALR1ITEM> LALR1Items;

vector<LR1EDGE> LR1Edges;
vector<LALR1EDGE> LALR1Edges;

// 在go函数中使用
vector<string> nextTokens;

// 在mergeCores函数中使用
vector<LR1ITEM> sameCores;

// map<pair<int, string>, string> LR1ACTION, LR1GOTO;
map<pair<vector<int>, string>, string> ACTION, GOTO;

bool isLR1InItem(int id, const LR1GRAM &A)
{
    for (auto &x : LR1Items[id].LRGrams)
        if (x == A)
            return true;
    return false;
}

int getItemID(const LR1ITEM &A)
{
    for (auto &item : LR1Items)
        if (item.LRGrams == A.LRGrams)
            return item.id;
    return -1;
}
// 求CLOSURE(I)
void closure(int id){
    int lastSize = -1, newSize = LR1Items[id].size();
    while (lastSize != newSize){ // 如果该项目的文法数量不再变化，就跳出循环
        lastSize = newSize;
        for (int i = 0; i < newSize; ++i){
            if (LR1Items[id].LRGrams[i].gram.tokens.empty())
                continue;                             // 如果没有待接收的tokens了，就跳过
            GRAM gram = LR1Items[id].LRGrams[i].gram; // 创建GRAM变量记录当前项目的LR(1)文法[i]的文法规则
            string newName = gram.tokens[0];          // 记录要接收的第一个
            if (isTerminal(newName))
                continue; // 首个token是终结符就不用再求closure
            for (auto &newGram : Grams){ // 遍历原有的全部文法规则
                if (newGram.name != newName)
                    continue; // 如果当前文法的左部不等于newName，跳过
                // 求下一个可以接收的终结符
                // 如果当前的token已经是最后一个待接收token了，那就继承之前的下一个终结符
                set<string> terms = gram.tokens.size() > 1 ? First[gram.tokens[1]] : set<string>({LR1Items[id].LRGrams[i].term});
                for (auto &newTerm : terms){ // 新增文法
                    LR1GRAM newLR1({newGram, newTerm});
                    if (isLR1InItem(id, newLR1))
                        continue; // 如果当前文法已经存在该项目，跳过
                    LR1Items[id].LRGrams.push_back(newLR1);
                }
            }
        }
        newSize = LR1Items[id].size(); // 更新当前的文法数量
    }
}
// LR1Items[id]接收token后，得到新的newItem=LR1Items[newID]
void go(int id, string token)
{
    bool flag = false;           // 跳转是否成功的标识符
    int newID = LR1Items.size(); // 创建新的ID
    LR1ITEM newItem({newID});    // 新建一个LR(1)项目
    for (auto &x : LR1Items[id].LRGrams)
    { // 遍历起点项目的所有文法
        // 如果待接收的tokens为空 或者 第一个待接收的token不等于当前的目标token，则跳过
        if (x.gram.tokens.empty() || x.gram.tokens[0] != token)
            continue;
        flag = true;                                             // 跳转成功
        GRAM newGram = x.gram;                                   // 记录变量
        vector<string> newFormer = x.former;                     // 记录变量
        newFormer.push_back(newGram.tokens[0]);                  // 把原来待接收的tokens第一个token移到新的former中
        newGram.tokens.erase(newGram.tokens.begin());            // 删除待接收的tokens中第一个token
        newItem.LRGrams.push_back({newGram, x.term, newFormer}); // 向新的item中加入新的文法
    }
    if (!flag)
        return;                             // 跳转失败，直接结束
    LR1Items.push_back(newItem);            // 加入新项目item
    closure(newID);                         // 紧接着求这个新项目的CLOSURE
    int tmpID = getItemID(LR1Items[newID]); // 求新的item在项目集中第一次出现时的下标
    // 如果找到的下标不等于新的ID，说明该item在接收token后成环，然后去掉这个新加的item
    if (newID != tmpID)
        LR1Items.pop_back();
    LR1Edges.push_back({id, tmpID, token}); // 添加边数据
}

void getNextTokens(int id)
{
    nextTokens.clear();
    for (auto &x : LR1Items[id].LRGrams)
    {
        if (x.gram.tokens.empty())
            continue;
        if (!isInVec(x.gram.tokens[0], nextTokens))
            nextTokens.push_back(x.gram.tokens[0]);
    }
}

// 构建LR(1)的项目集
void buildLR1Item()
{
    LR1Items.push_back({0, {{Grams[0], END}}}); // 用开始文法初始化LR(1)项目集
    closure(0);                                 // 立即求出新item的CLOSURE
    int id = 0;
    while (id < LR1Items.size())
    {                      // 如果没有新增的item，id会到达临界值而跳出循环
        getNextTokens(id); // 获取Items[id]下一次可以接收的tokens
        for (auto &token : nextTokens)
            go(id, token); // 跳转到新item
        ++id;
    }
}

// 构建LR(1)分析表
// void buildLR1Table() {
//	// 移进动作 or 跳转动作
//	for (auto& e : LR1Edges) {
//		if (isTerminal(e.s)) LR1ACTION[{e.x, e.s}] = 's' + to_string(e.y);
//		else LR1GOTO[{e.x, e.s}] = to_string(e.y);
//	}
//	// 归约动作
//	for (auto& item : LR1Items) {
//		for (auto& LR1 : item.LRGrams) {
//			if (!LR1.gram.tokens.empty()) continue;
//			GRAM gram({ LR1.gram.name, LR1.former });
//			int id = getGramID(gram);
//			LR1ACTION[{item.id, LR1.term}] = 'r' + to_string(id);
//		}
//	}
//	LR1ACTION[{1, END}] = ACCEPT;
//}

void mergeGram(LALR1GRAM &LA, const LR1GRAM &LR)
{
    if (LA.terms.empty())
    {
        LA.former = LR.former;
        LA.gram = LR.gram;
    }
    LA.terms.insert(LR.term);
}

// 将LR(1)文法转换为字符串
string gramToString(const LR1GRAM &x){
    string str;
    str += "name: " + x.gram.name + ' ';
    str += "tokens: ";
    for (auto &y : x.gram.tokens)
        str += y + ' ';
    str += "former: ";
    for (auto &y : x.former)
        str += y + ' ';
    return str;
}
// 判断两个LR(1)项目A和B是否具有相同核心
bool isSameCore(LR1ITEM &A, LR1ITEM &B)
{
    set<string> s1, s2;
    for (auto &x : A.LRGrams){
        string str = gramToString(x);
        s1.insert(str);
    }
    for (auto &x : B.LRGrams){
        string str = gramToString(x);
        s2.insert(str);
    }
    return s1 == s2;
}
// 对LR(1)项目A合并相同核心的文法，成为LALR(1)项目B
void mergeLRToLALRItem(LR1ITEM &A, LALR1ITEM &B)
{
    for (auto &x : A.LRGrams)
    {
        bool flag = true; // 如果B中不存在与x具有相同核心的文法，可以直接把文法x加入B中
        for (auto &y : B.LRGrams)
        {
            if (x.former != y.former || x.gram != y.gram)
                continue;           // 如果文法y不具有和x相同的核心，跳过
            flag = false;           // x和y的核心相同，就不要直接把x加入B中(避免重复)，我们只需要追加终结符term就行
            y.terms.insert(x.term); // 加入新的终结符
        }
        if (flag)
            B.LRGrams.push_back({x.gram, {x.term}, x.former}); // 全新的文法核心，直接把文法x加入B中
    }
}

// 将当前记录的相同核心的LR(1)项目合并成LALR(1)项目，并加入到LALR(1)项目集中
void addLALR1Item()
{
    LALR1ITEM LAitem; // 创建新的LALR(1)项目
    for (auto &item : sameCores)
    {
        LAitem.ids.push_back(item.id);
        mergeLRToLALRItem(item, LAitem);
    }
    for (auto &id : LAitem.ids)
        LALR1Items[id] = LAitem;
}

// 不断遍历LR(1)项目集，合并相同核心项
void mergeCores(){
    int n = LR1Items.size();
    LALR1Items.resize(n);     // 初始化LALR(1)项目数量和LR(1)项目相同，后面再去重
    vector<bool> v(n, false); // 访问标记，根据id判断哪些item已经访问过
    while (true){
        sameCores.clear(); // 清空上一次的相同核心列表
        for (auto &item : LR1Items) {
            if (v[item.id]) continue; // 如果已访问，就跳过
            if (sameCores.empty()){                              // 如果当前没有记录过任何一个LR(1)项目
                sameCores.push_back(item); // 直接把item加入到samCores中
                v[item.id] = true;         // 更新标记
                continue;
            }
            if (isSameCore(sameCores[0], item)){    // 如果当前项目的核心和sameCores中的第一个相同
                sameCores.push_back(item); // 追加新item到sameCores中
                v[item.id] = true;         // 更新标记
            }
        }
        if (sameCores.empty())
            return;     // 如果所有的item都进行过合并操作，就结束
        addLALR1Item(); // 添加新的LALR(1)项目到LALR(1)项目集中
    }
}

void removeDupliItemAndBuildLALR1Edges(){   // 去重 + 构造边
    vector<LALR1ITEM> newItems = LALR1Items; // 临时变量记录原来的LALR(1)项目集
    LALR1Items.clear();                      // 清空原来的LALR(1)项目集
    map<vector<int>, vector<int>> m;         // 多编号映射成单编号
    for (auto x : newItems){
        if (m.find(x.ids) != m.end()) continue;    // 如果已标记，则跳过
        m.insert({x.ids, {int(LALR1Items.size())}}); // 更新标记
        x.ids = m[x.ids];
        LALR1Items.push_back(x); // 添加项目
    }
    int n = LR1Items.size();
    // 二维数组v[n][n]，v[x][y]=true说明项目x到项目y的边已经记录过了
    vector<vector<bool>> v(n, vector<bool>(n, false));
    for (auto &e : LR1Edges){
        // 获取当前的LR(1)边的起点LR(1)项目对应的起点LALR(1)项目的ids
        vector<int> xs = newItems[e.x].ids;
        // 获取当前的LR(1)边的终点LR(1)项目对应的终点LALR(1)项目的ids
        vector<int> ys = newItems[e.y].ids;
        if (v[xs[0]][ys[0]]) continue; // 如果已经遍历过，则跳过
        for (auto &x : xs)
            for (auto &y : ys)
                v[x][y] = true;                    // 更新标记
        LALR1Edges.push_back({m[xs], m[ys], e.s}); // 添加新边
    }
}

void buildLALR1Item()
{
    mergeCores(); // 合并相同核心
    removeDupliItemAndBuildLALR1Edges();
}

// 构建LALR(1)分析表
void buildLALR1Table()
{
    // 归约动作（！！！注意，先记录归约动作，因为LALR1仍存在移进-归约冲突，此时优先进行移进动作，所以后记录移进动作，可以覆盖掉归约动作）
    // 如果某一LALR(1)文法没有待接收tokens(已经接收完毕)，那就进入归约动作
    for (auto &item : LALR1Items){ // 遍历每一个项目
        for (auto &LR1 : item.LRGrams){ // 遍历每一个项目的每一条文法
            if (!LR1.gram.tokens.empty()) continue;             // 如果还有待接收的tokens，则跳过
            GRAM gram({LR1.gram.name, LR1.former});             // 记录该文法信息
            int id = getGramID(gram);                           // 获取该文法在全部文法Grams中的下标ID
            for (auto &term : LR1.terms)                        // 要对所有可接收的终结符都进行归约
                ACTION[{item.ids, term}] = 'r' + to_string(id); // 更新表格
        }
    }
    // 移进动作 or 跳转动作
    for (auto &e : LALR1Edges)
    { // 遍历每一条边
        string str;
        if (isTerminal(e.s)){            // 如果接收的token是终结符，则为移进动作
            str = "s"; // 移进动作前缀用"s"标记
            for (auto &y : e.ys)
                str += to_string(y) + ' ';
            ACTION[{e.xs, e.s}] = str.substr(0, str.size() - 1); // 更新表格                                                   // substr是为了去除str的最后一个空格
        }
        else{ // 如果接收的token是非终结符，则为跳转动作
            // 跳转动作前缀不用标记
            for (auto &y : e.ys)
                str += to_string(y) + ' ';
            GOTO[{e.xs, e.s}] = str.substr(0, str.size() - 1); // 更新表格                                                  // substr是为了去除str的最后一个空格
        }
    }
    // 接受动作
    // 例如，扩充开始文法[S'->S, $]，它是位于LALR1Items[0]的，在接收一个S后，跳转至LALR1Items[1]
    // 此时跳转至LALR1Items[1]再接收一个结束符$，就完成了整体文法的归约(相当于文法归约的统一出口)
    // 我们定义这一个出口为接受动作，用"acc"表示
    for (auto &x : LALR1Items){
        for (auto &y : x.ids){
            if (y != 1) continue;      // 如果id=1不在当前LALR(1)项目的ids中，则跳过
            ACTION[{x.ids, END}] = ACCEPT; // 更新表格()
            return;                        // LALR(1)的DFA应该只有一个入口，即S'->S，所以也只有一个接受动作
        }
    }
}
