#include <iostream>
using namespace std;
typedef long long ll;
ll quick_power(ll base, ll power, ll mod)
{
    ll result = 1;
    while (power)
    {
        if (power & 1)
        {
            result = result * base % mod;
        }
        power /= 2;
        base = base * base % mod;
    }
    return result;
}
int main()
{
    ll x, y, m;
    cout << "请分别输入x,y,m的值:";
    cin >> x >> y >> m;
    cout << "x^y mod m = " << quick_power(x, y, m);
    return 0;
}