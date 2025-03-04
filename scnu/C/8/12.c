#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 9

int matrix[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int n;

int is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int is_coastline(int x, int y) {
    return matrix[x][y] == 1;
}

void dfs(int x, int y) {
    if (!is_valid(x, y) || visited[x][y] || matrix[x][y] == 1) {
        return;
    }
    visited[x][y] = 1;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (matrix[i][0] == 0) dfs(i, 0);
        if (matrix[i][n - 1] == 0) dfs(i, n - 1);
        if (matrix[0][i] == 0) dfs(0, i);
        if (matrix[n - 1][i] == 0) dfs(n - 1, i);
    }

    int island_area = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (matrix[i][j] == 0 && !visited[i][j]) {
                island_area++;
            }
        }
    }

    printf("%d\n", island_area);
    return 0;
}