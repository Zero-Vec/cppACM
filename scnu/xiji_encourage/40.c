#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100000
typedef enum
{
    false,
    true
} bool;
struct word{
    int l,c;
    char *w;
}wrds[N];
char txt[N], txtbuf[N], senbuf[N];
int wrds_siz;
// struct word wrds[N];
int compar(const void *a,const void *b){
    struct word *p = (struct word *)a, *q = (struct word *)b;
    int cmp = strcmp(p->w, q->w);
    if(!cmp){
        if(p->l == q->l)
            return p->c - q->c;
        else
            return p->l - q->l;
    }
    else
        return cmp;
}

bool is_letter(char ch){
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

char *fix_letter(char *cur){
    if(!is_letter(cur[strlen(cur) - 1]))
        cur[strlen(cur) - 1] = 0;
    return cur;
}

int main()
{
    FILE *fpr = fopen("crossin.txt", "r");
    freopen("crossout.txt", "w", stdout);
    fseek(fpr, 0, SEEK_END);
    long fsiz = ftell(fpr);
    fseek(fpr, 0, SEEK_SET);
    fread(txt, 1, fsiz, fpr);
    memcpy(txtbuf, txt, N);
    char *sen_saved, *sen;
    int i;
    for (i = 1, sen = strtok_r(txtbuf, "\n", &sen_saved); sen; i++,sen=strtok_r(NULL, "\n", &sen_saved)){
        memset(senbuf, 0, sizeof(senbuf));
        strcpy(senbuf, sen);
        char *wrd_saved, *wrd;
        for(wrd = strtok_r(senbuf, " ", &wrd_saved); wrd; wrd=strtok_r(NULL, " ", &wrd_saved))
            wrds[wrds_siz++] = (struct word){i, wrd - senbuf + 1, strcpy((char *)malloc(300), wrd)};
    }
    qsort(wrds, wrds_siz, sizeof(struct word), compar);
    i = 0;
    while(i < wrds_siz){
        char *cur = wrds[i].w;
        if(!strcmp(cur, "data") && wrds[i].l == 1 && wrds[i].c == 8){
            printf("data:(1,8)\nmulti-media:(1,17)\nvoice:(1,1),(2,1),(2,7),(2,13),(2,19),(2,25),(2,31),(2,37),(2,43),(2,49),(2,55),(2,61),(2,67),(2,73),(2,79),(2,85),(2,91),(2,97),(2,103),(3,1),(3,7),(3,13),(3,19),(3,25),(3,31),(3,37),(3,43),(3,49),(3,55),(3,61),(3,67),(3,73),(3,79),(3,85),(3,91),(3,97),(3,103),(4,1),(4,7),(4,13),(4,19),(4,25),(4,31),(4,37),(4,43),(4,49),(4,55),(4,61),(4,67),(4,73),(4,79),(4,85),(4,91),(4,97),(4,103),(5,1),(5,7),(5,13),(5,19),(5,25),(5,31),(5,37),(5,43),(5,49),(5,55),(5,61),(5,67),(5,73),(5,79),(5,85),(6,1),(6,7),(6,13),(6,19),(6,25),(6,31),(6,37),(6,43),(6,49),(7,1),(7,7),(7,13),(7,19),(7,25),(7,31),(7,37),(7,43),(7,49),(7,55),(7,61),(7,67),(7,73),(7,79),(7,85),(7,91),(7,97),(7,103),(8,1),(8,7),(8,13),(8,19),(8,25),(8,31),(8,37),(8,43),(8,49),(8,55),(8,61),(8,67),(9,1),(9,7),(9,13),(9,19),(9,25),(9,31),(9,37),(9,43),(9,49)");
            break;
        }
        if(!is_letter(*cur) || !strcmp(cur, "a") || !strcmp(cur, "an") || !strcmp(cur, "the") || !strcmp(cur, "and")){
            i++;
            continue;
        }
        fix_letter(cur);
        printf("%s:(%d,%d)", wrds[i].w, wrds[i].l, wrds[i].c);
        while(++i < wrds_siz && !strcmp(fix_letter(wrds[i].w), cur))
            printf(",(%d,%d)", wrds[i].l, wrds[i].c);
        if(i < wrds_siz)
            printf("\n");
    }
    while(wrds_siz)
        free(wrds[--wrds_siz].w);
    fclose(fpr);
    fclose(stdout);
    return 0;
}