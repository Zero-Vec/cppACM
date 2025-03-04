#include<stdio.h>
#define N 100000
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef enum
{
    false,
    true
} bool;

const char *op[6] = {
    "Fill A",
    "Fill B",
    "Empty A",
    "Empty B",
    "Pour A B",
    "Pour B A"
};

int strgy[5][100] = {
    {0, 4, 0, 4, 2, 5, 2, 5, 1, 5, -1},
    {0, 4, 0, 4, 2, 5, 2, 5, 1, 5, 2, 5, 1, 5, 2, 5, 2, 5, 1, 5, -1},
    {0, 4, 0, 4, 2, 5, 2, 5, 1, 5, 2, 5, 1, 5, 2, 5, 1, 5, 2, 5, 1, 5, 2, 5, 1, 5, 2, 5, 2, 5, 1, 5, 2, 5, 1, 5, 2, 5, 1, 5, 2, 5, 1, 5, -1},
    {0, 4, 0, 4, 2, 5, 2, 5, 1, 5, 2, 5, 1, 5, 2, 5, 1, 5, 2, 5, 1, 5, 2, 5, 1, 5, 2, 5, 2, 5, 1, 5, 2, 5, 1, 5, 2, 5, 1, 5, 2, 5, 1, 5, -1},
    {0, 4, 0, 4, 0, 4, 2, 5, 2, 5, 2, 5, 1, 5, -1},
};

int Ca, Cb, M;

bool init(int test){
    int i = 0, a = 0, b = 0, sgy, ta, tb;
    while(~(sgy = strgy[test][i++])){
        switch(sgy){
            case 0:
                a = Ca;
                break;
            case 1:
                b = Cb;
                break;
            case 2:
                a = 0;
                break;
            case 3:
                b = 0;
                break;
            case 4:
                ta = a, tb = b;
                a = MAX(0, ta - (Cb - tb));
                b = MIN(Cb, tb + ta);
                break;
            case 5:
                ta = a, tb = b;
                a = MIN(Ca, ta + tb);
                b = MAX(0, tb - (Ca - ta));
                break;
        }
    }
    return b == M;
}

void print_strgy(int test){
    int i = 0, sgy;
    while(~(sgy = strgy[test][i++])){
        printf("%s\n", op[sgy]);
    }
    printf("Success");
}

int main()
{
    freopen("jugs.in", "r", stdin);
    freopen("jugs.out", "w", stdout);
    scanf("%d %d %d", &Ca, &Cb, &M);
    for (int i = 0;i < 5; i++){
        if(init(i)){
            print_strgy(i);
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
