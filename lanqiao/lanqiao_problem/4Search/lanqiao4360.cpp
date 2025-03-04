#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 15;
struct Node{
    int op = 0, x = 0, y = 0;
}a[N];
int n, k;
bool vis[N];
string pos(int op,int x,int y,string s){
    if(op==1){
        s[x] = (s[x]-'0'+y) % 10 + '0';
    }
    else{
        swap(s[x], s[y]);
    }
    return s;
}
bool dfs(Node a[],string s1,string s2){
    if(s1==s2)
        return true;
    for (int i = 1; i <= k;i++){
        if(vis[i])continue;
        string tmp = s1;
        s1 = pos(a[i].op, a[i].x, a[i].y, s1);
        vis[i] = 1;
        if(dfs(a,s1,s2))
            return true;
        vis[i] = 0;
        s1 = tmp;
    }
    return false;
}
void solve(){
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    cin >> k;
    for (int i = 1; i <= k;i++){
        cin >> a[i].op >> a[i].x >> a[i].y;
    }
    if(dfs(a,s1,s2))
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
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
/*
#include <bits/stdc++.h>
using namespace std;
struct Data {  //记录三个数据类型
  Data(int ops = 0, int x = 0, int y = 0)
      : ops(ops), x(x), y(y) {}
  int ops, x, y;
};
string postion(int &id, int &x, int &y, string s) {  //执行修改，返回修改完成后的串
  if (id == 1) s[x] = (s[x] - '0' + y) % 10 + '0';
  else swap(s[x], s[y]);
  return s;
}
bool vis[10];  //状态数组
bool dfs(vector<Data>& arr, string s1, string &s2) {
  if (s1 == s2) return true;  //每一次询问，如果相等则立即返回
  for (int i = 0; i < arr.size(); i++) {   //参考全排列，枚举每一个，拿第一个没有使用过的状态
      if (vis[i]) continue; //跳过使用过的状态
      vis[i] = true;   //标记为使用
      string temp = s1;  //记录开始时s1的串
      s1 = postion(arr[i].ops, arr[i].x, arr[i].y, s1);  //执行对s1的修改
      if (dfs(arr, s1, s2)) return true;  //递归过程，如果找到则快速返回
      vis[i] = false;   //回溯过程，标记为未使用
      s1 = temp;  //将s1变成原来的串
  }
  return false;
}
int main() {
  int n; cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  if (s1 == s2) cout << "Yes" << endl;
  int k; cin >> k;
  vector<Data> arr(k);
  for (int i = 0; i < k; i++) {
      cin >> arr[i].ops >> arr[i].x >> arr[i].y;
  }
  if (dfs(arr, s1, s2)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
*/