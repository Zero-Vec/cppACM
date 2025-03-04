#include <stdio.h>
#include <math.h>

double factorial(int num) {
    double result = 1.0;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

double calculate_sin(double x, int n) {
    double sinx = 0.0;
    for (int i = 0; i < n; i++) {
        double term = pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
        sinx += term;
    }
    return sinx;
}

int main() {
    double x;
    int n;
    scanf("%lf %d", &x, &n);
    
    double result = calculate_sin(x, n);
    
    printf("%.8lf\n", result);
    
    return 0;
}