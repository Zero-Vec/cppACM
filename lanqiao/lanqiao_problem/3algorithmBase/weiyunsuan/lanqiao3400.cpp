#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int a[N], prexori[N], prexorj[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        prexori[i] = prexori[i - 1] ^ a[i]; // 求前缀异或和，prexor[1]的结果就是第一个元素本身，prexor[0]=0;
    prexorj[0] = 1;                         // 因为若prexor[0]^prexor[1]=sq，说明a[1]-a[1]即第一个元素本身就符合条件，prexor[i]^sq=0时要减1，所以cnt[0]=1
    int ans = n * (n + 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 200; j++)
        {
            int sq = j * j;
            ans -= prexorj[prexori[i] ^ sq]; // 这里的prexorj[]相当于是prexor[i]的每一个数值，注意[]里是数值而不是下标，这么写看起来容易理解，为的是避免和i重合，计算有几个j满足prexor[j]=prexor[i]^sq
        }                                    // 因为prexor[i]^prexor[j]的值是唯一的，所以要么不存在sq使prexor[i]^sq=cnt[j]，它的结果只要存在就是唯一的sq即这个区间要么减掉要么不减，不会减好几次
        prexorj[prexori[i]]++;               // 这个i是已经循环过的上一步的i，i每前进一个，j紧随其后保留这个前缀和的数值，一旦i异或sq是前面的任意prexor[j]的数值，就减1。
    }
    cout << ans << endl;
    return 0;
}