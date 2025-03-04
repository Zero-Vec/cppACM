#include <stdio.h>
#include <stdlib.h>

int main() {
    char s[100];
    
    double number;

    scanf("%s", s);

    number = atof(s);

    printf("%f\n", number);

    return 0;
}
