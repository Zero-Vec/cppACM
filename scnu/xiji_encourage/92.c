#include <stdio.h>
#include <math.h>

int main() {
    double e;
    scanf("%lf", &e);

    double pi_approx = 0.0;
    double t;
    int n = 1;
    double prev_pi_approx;

    do {
        prev_pi_approx = pi_approx;
        t = pow(-1, n + 1) / (2 * n - 1);
        pi_approx += t;
        n++;
    } while (4 * fabs(pi_approx - prev_pi_approx) > e);
    printf("%d\n", n - 1);
    return 0;
}
