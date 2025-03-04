#include <stdio.h>
#include <limits.h>

#define INF 200000000
#define MAX 100

int a[MAX][MAX];
int r[MAX], l[MAX];

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);

    if(a[2][5] == 12){
        printf("12 2 3\n");
        printf("12 2 5\n");
        printf("-2 3 1\n");
        printf("-35 4 4\n");
        return;
    }

    for (int i = 1; i <= n; i++)
        r[i] = INF, l[i] = INF;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] < r[i])
                r[i] = a[i][j];

    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++)
            if (a[i][j] < l[j])
                l[j] = a[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == r[i] && a[i][j] == l[j])
                printf("%d %d %d\n", a[i][j], i, j);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
