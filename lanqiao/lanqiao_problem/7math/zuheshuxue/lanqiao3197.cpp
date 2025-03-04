#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9 + 7;
ll quick_power(ll base,ll power){
    ll result = 1;
    while(power){
        if(power&1){
            result = result * base % P;
        }
        power /= 2;
        base = base * base % P;
    }
    return result % P;
}
void solve(){
    int n, m;
    cin >> n >> m;
    ll ans = (6 * (quick_power(2, n) + quick_power(2, m)) - 24) % P;
    if(n==1&&m==1)
        cout << 4 << "\n";
    else
        cout << ans << "\n";
}
// 本题可先举几个例子找出规律,再使用组合数学求解
// 经过举例子发现,每一个完美的方格表,第一行 或 第一列一定是两种颜色交替出现的
// 比如第一行为 0 1 0 1 ...,则第三行也应该是 0 1 0 1...
// 对于行元素,先从4种颜色里选出2种,有C(4,2)种选法;每一行两种方案,n行总共有C(4,2)*2^n种组合
// 列元素同理,m列总共有C(4,2)*2^m种组合
// 由组合数学,A或B的组合种数等于A的组合种数加上B的组合种数再减去A和B共同出现的组合种数
// 即A∪B=A+B-A∩B
// 若A情况和B情况共同出现,等同于左上角的3个元素互不相同,即4种颜色里排列3种,即A(4,3)
// 故最终答案为C(4,2)*2^n+C(4,2)*2^m-A(4,3)
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
    return 0;
}
