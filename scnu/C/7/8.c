#include <stdio.h>
#include <stdbool.h>

int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

bool isPalindrome(int num) {
    return num == reverseNumber(num);
}

int main() {
    int num;
    scanf("%d", &num);

    if (isPalindrome(num)) {
        printf("%d\n", num);
        return 0;
    }

    int iteration = 0;
    while (!isPalindrome(num)) {
        int reversed = reverseNumber(num);
        int sum = num + reversed;
        iteration++;
        printf("%d:%d+%d=%d\n", iteration, num, reversed, sum);
        num = sum;
    }

    printf("%d\n", num);
    return 0;
}