#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e4 + 9;
int x[N], y[N], a[N], b[N];
int n;
void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    sort(x + 1, x + 1 + n);
    sort(y + 1, y + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        x[i] = x[i] - i;
    }
    sort(x + 1, x + 1 + n);
    for (int i = n; i >= 1; i--){
        a[n - i + 1] = x[i];
        b[n - i + 1] = y[i];
    }
    for (int i = 1; b[i] > y[i];i++)
        ans += b[i] - y[i];
    for (int i = 1; a[i] > x[i];i++)
        ans += a[i] - x[i];
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
/*
#include<cstdio>
#include<algorithm>//sort函数
#include<cstdlib> //abs函数

using namespace std;

int main()
{
    int n;//士兵数
    scanf("%d",&n);

    int x[10000],y[10000];
    //x数组存储士兵的横坐标，y数组存储士兵的纵坐标
    int sum=0,rex,rey;
    //sum记录步数之和，rex记录x方向的中位数，rey记录y方向的中位数

    int i;
    for(i=1;i<=n;i++)
        scanf("%d%d",x+i,y+i);
    //数据的输入到x[1]~x[n],y[1]~y[n],此处使用的是数组地址法

    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    //对数据x[1]~x[n],y[1]~y[n]分别进行由小到大的排序

    for(i=1;i<=n;i++)
        x[i]=x[i]-i;
    //构造x1-1，x2-2，......，xn-n数列

    sort(x+1,x+n+1);
    //对新数列进行排序

    if(n%2==0)//n为偶数
    {
        rex = (x[n/2]+x[n/2+1])/2;
        rey = (y[n/2]+y[n/2+1])/2;
    }
    else//n为奇数
    {
        rex = x[n/2+1];
        rey = y[n/2+1];
    }

    //下面计算最小移动步数
    for(i=1;i<=n;i++)
        sum += abs(x[i]-rex)+abs(y[i]-rey);

    printf("%d",sum);
    //输出结果
    return 0;
 }

*/