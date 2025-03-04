#include <iostream>
using namespace std;
struct Bezout
{
    int r;
    int s; // r,s为Bezout系数
    int d; // d为gcd(a,b)
};
Bezout egcd(int a, int b)
{
    Bezout ans;
    if (b == 0)
    {
        ans.r = 1;
        ans.s = 0;
        ans.d = a;
        return ans;
    }
    ans = egcd(b, a % b);
    int tmp = ans.r;
    ans.r = ans.s;
    ans.s = tmp - a / b * ans.r;
    return ans;
}
int main()
{
    // 测试样例:egcd(131,90)
    Bezout ans = egcd(131, 90);
    cout << "r = " << ans.r << '\n';
    cout << "s = " << ans.s << '\n';
    cout << "gcd(131,90) = " << ans.d;
    return 0;
}