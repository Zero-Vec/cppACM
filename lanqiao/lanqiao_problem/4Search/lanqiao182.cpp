#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N];
bool v[N];//用于判断当前节点有没有被访问过
int ans = 0;
int t;//用于记录当前起点的小朋友编号
void dfs(int i,int m){
    if(v[i]){
        //该节点访问过即为递归的出口
        if(a[i]==a[t]){
            //形成了一个环
            ans = max(ans, m);
        }
        return;
    }
    v[i] = 1;
    dfs(a[i], m + 1);
    v[i] = 0;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++){
        t = i;
        dfs(i, 0);
    }
    cout << ans;
    return 0;
}