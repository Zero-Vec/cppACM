#include <stdio.h>
#include <stdlib.h>

int main() {
    char sci_notation[100];
    
    double number;

    scanf("%s", sci_notation);

    number = atof(sci_notation);

    printf("%f\n", number);

    return 0;
}