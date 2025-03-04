#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/*
解题思路：从小到大遍历队伍数量，对于每个队伍数量再进行判断，用向量容器v[N]储存每一种配对情况。
由1到ans遍历每种配对情况，用num暂存当前人要加入哪个队伍，再用容器j遍历当前队伍的每一个值，判断有无倍数关系。
若有则直接剪枝跳出这次i，说明v[i]的配对方式已经失去了可能性；若无则push_back这个队员加入到v[i]配对中，说明可行，并进入到下一层深度中
看下一层(或更深层次)是否可行。若后续层数不可行，则当前ans支队伍方案仍失效，在遍历下一个ans支队伍方案前，进行回溯
把上一个push进去的pop出来，再进入下一个ans判断，并如是循环
最后只需要把1~n支队伍都遍历一遍，返回第一个dfs为true即为最小队伍数。
*/
const int N = 15;
int a[N];
int n;
vector<int> v[N];//v[i]存队伍中所有人的编号，比如v[1]存队伍1中所有人的编号
//ans表示队伍数量，dfs返回在ans个队伍的情况下是否可以成功分组
bool dfs(int ans,int dep){
    if(dep==n+1){//每个人都成功分组
        return true;
    }
    int num = a[dep];
    //枚举每个人所属的队伍
    for (int i = 1; i <= ans;i++){
        bool flag = 1;
        for(const auto j:v[i]){
            if(num%j==0)
                flag = 0;
        }
        if(!flag)continue;
        v[i].push_back(num);
        if(dfs(ans,dep+1))
            return true;
        //恢复现场
        v[i].pop_back();
    }
    return false;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n;i++){
        if(dfs(i,1)){
            cout << i;
            return;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    //cout << v[1].size();
    return 0;
}