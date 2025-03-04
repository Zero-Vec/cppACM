#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N=30;
const int inf = 0x3f3f3f3f;
int a[N];//存储矩阵的行和列
int m[N][N];//存储i到j的最少计算次数
int s[N][N];//存储i到j的中转站k
void print(int i,int j){
    if(i==j)
        cout << 'M' << i;
    else{
        cout << '(';
        print(i, s[i][j]);
        print(s[i][j] + 1, j);
        cout << ')';
    }
}
int n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n + 1;i++)
        cin >> a[i];
    for (int d = 2; d <= n;d++)//d个矩阵相乘
        for (int i = 1; i <= n - d + 1;i++){
            int j = i + d - 1;
            m[i][j] = inf;
            for (int k = i; k <= i + d - 2;k++){
                int t = m[i][k] + m[k + 1][j] + a[i] * a[k + 1] * a[j + 1];
                if(t<m[i][j]){
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    cout << m[1][n] << ' ';
    print(1, n);
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