#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 35;
int pre[N], mid[N], post[N];//前中后数组
int n, st;
vector<int> v[N];
void build(int l,int r,int Pr,int level){
    //区间左端点，区间右端点，当前树根节点所在后续数组位置，当前是第几层
    if(l>=r){
        pre[++st] = post[Pr];
        v[level].push_back(pre[st]);
        return;
    }
    pre[++st] = post[Pr];
    v[level].push_back(pre[st]);

    for (int i = l; i <= r;i++){
        //枚举找到中序遍历的根节点的位置
        if(mid[i]==post[Pr]){
            if(i!=l)
                build(l, i - 1, Pr - (r - i + 1), level + 1);
            if(i!=r)
                build(i + 1, r, Pr - 1, level + 1);
            break;
        }
    }
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> post[i];
    for (int i = 1; i <= n;i++)
        cin >> mid[i];
    build(1, n, n, 1);
    int op = 0;
    for (int i = 1; i < N;i++){
        if(v[i].size()){
            for (int j = 0; j < v[i].size();j++){
                if(!op){
                    cout << v[i][j];
                    op = 1;
                }
                else{
                    cout << " " << v[i][j];
                }
            }
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
    return 0;
}