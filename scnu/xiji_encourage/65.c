#include <stdio.h>

void solve() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i += 2) {
        for (int j = 1; j <= i; j++)
            printf("*");
        printf("\n");
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
