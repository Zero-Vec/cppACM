#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} node;

int cmp(const void *a, const void *b) {
    node *nodeA = (node *)a;
    node *nodeB = (node *)b;
    if (nodeA->start == nodeB->start) {
        return nodeA->end - nodeB->end;
    }
    return nodeA->start - nodeB->start;
}

int main() {
    FILE *inputFile = fopen("prz.in", "r");
    FILE *outputFile = fopen("prz.out", "w");

    int n;
    fscanf(inputFile, "%d", &n);

    node *id = (node *)malloc(n * sizeof(node));
    for (int i = 0; i < n; ++i) {
        fscanf(inputFile, "%d %d", &id[i].start, &id[i].end);
    }

    qsort(id, n, sizeof(node), cmp);

    node *ans = (node *)malloc(n * sizeof(node));
    int siz = 0;
    node cur = id[0];

    for (int i = 1; i < n; ++i) {
        if (id[i].start <= cur.end) {
            cur.end = cur.end > id[i].end ? cur.end : id[i].end;
        } else {
            ans[siz++] = cur;
            cur = id[i];
        }
    }
    ans[siz++] = cur;

    for (int i = 0; i < siz; ++i) {
        fprintf(outputFile, "%d %d\n", ans[i].start, ans[i].end);
    }

    free(id);
    free(ans);
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}