/*
给定一棵以1为根的树（分别给出每个点的左右儿子），求出先序遍历、中序遍历、后序遍历和层序遍历
输入样例：
10
2 3
4 5
6 7
8 0
0 9
0 0
10 0
0 0
0 0
0 0
输出样例：
1 2 4 8 5 9 3 6 7 10
8 4 2 5 9 1 6 3 10 7
8 4 9 5 2 6 10 7 3 1
1 2 3 4 5 6 7 8 9 10
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=30;
int ls[N], rs[N];
//先序遍历
void dfs1(int x){
    cout << x << ' ';
    if(ls[x])
        dfs1(ls[x]);
    if(rs[x])
        dfs1(rs[x]);
}
//中序遍历
void dfs2(int x){
    if(ls[x])
        dfs2(ls[x]);
    cout << x << ' ';
    if(rs[x])
        dfs2(rs[x]);
}
//后序遍历
void dfs3(int x){
    if(ls[x])
        dfs3(ls[x]);
    if(rs[x])
        dfs3(rs[x]);
    cout << x << ' ';
}
//层序遍历
void bfs(int x){
    queue<int> q;
    q.push(x);
    while(q.size()){
        int i = q.front();
        cout << i << ' ';
        q.pop();
        if(ls[i])
            q.push(ls[i]);
        if(rs[i])
            q.push(rs[i]);
    }
}
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> ls[i] >> rs[i];
    dfs1(1);
    cout << '\n';
    dfs2(1);
    cout << '\n';
    dfs3(1);
    cout << '\n';
    bfs(1);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}