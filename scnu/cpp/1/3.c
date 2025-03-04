#include <stdio.h>

int main() {
    float salary, tax_rate, net_salary;
    scanf("%f", &salary);
    switch ((int)salary / 1000) {
        case 0:
            tax_rate = 0.0;
            break;
        case 1:
            tax_rate = 0.10;
            break;
        case 2:
            tax_rate = 0.15;
            break;
        case 3:
            tax_rate = 0.20;
            break;
        default:
            tax_rate = 0.25;
            break;
    }

    net_salary = salary * (1 - tax_rate);

    printf("%.2f\n", net_salary);

    return 0;
}