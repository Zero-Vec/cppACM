#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// 先去看main函数！！！
ll getstep(ll n, ll a, ll b)
{
    ll num = 0;    // 统计个数
    while (n >= a) // 必须有=，因为比如数13，以13为前缀，有一个数，需要统计
    {
        num += min(n + 1, b) - a;
        // b刚开始是比a大一的，因为以a为前缀的数=[1,2)+[10,20)+...有b-a个满足条件的数累加
        // 但不能超过给的范围n，所以要min(n,b),又因为到n这个数有从0-n，总共n+1个数满足条件，所以比较的时候是n+1
        a *= 10;
        b *= 10;
    }
    return num;
}
int main()
{
    ll num = 1, n, k;
    cin >> n >> k;
    --k; // k==1的话，直接输出num=1了否则就while开始统计
    while (k > 0)
    {
        ll step = getstep(n, num, num + 1); // 获取以num为数字前缀的数有多少个，去看getstep函数
        if (step <= k)                      // step小了就减少，前缀++，取等于可以少算step次运算，因为else执行的是--k;
        {
            k -= step;
            ++num;
        }
        else // 执行else了，说明以num为前缀的数的总数比k大了
        // 所以确定前缀为num，而至于是第几个，则需要num*10，计算确定好的前缀的下一个不确定的前缀
        //--k是包括num*10当前这数字
        {
            num *= 10;
            --k;
        }
    }
    cout << num;
}