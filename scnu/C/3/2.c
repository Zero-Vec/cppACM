#include <stdio.h>
#include <math.h>

void solve()
{
    double x;
    scanf("%lf", &x);
    printf("%.0f\n", round(x));
}

int main()
{
    int t = 1;
    // scanf("%d", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}
