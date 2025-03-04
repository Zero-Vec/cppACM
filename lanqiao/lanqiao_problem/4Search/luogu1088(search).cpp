#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n,m;
const int N = 10010;
int a[N];//记录方案
int mars[N];//记录火星人的初始排列
bool st[N];//记录每个数有没有选过
int res = 0;
bool flag = false;
void dfs(int x){
    if(flag)
        //找到之后剪枝
        return;
    if(x>n){
        res++;
        if(res==m+1){
            flag = 1;
            for (int i = 1; i <= n;i++){
                cout << a[i] << " ";
            }
        }
        return;
    }
    for (int i = 1; i <= n;i++){
        if(!res){
            i = mars[x];
        }
        if(!st[i]){
            st[i] = true;
            a[x] = i;
            dfs(x + 1);
            //恢复现场
            st[i] = false;
            a[x] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> mars[i];
    dfs(1);
    return 0;
}