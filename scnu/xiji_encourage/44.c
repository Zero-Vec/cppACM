#include<stdio.h>
#include<stdlib.h>
#define N 100000

struct node{
    int data;
    struct node *lsn, *rsn;
};
struct node *nodes[N];
int siz;

void build(struct node *fa, int x){
    if(x < fa->data){
        if(fa->lsn == NULL){
            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = x;
            new_node->lsn = new_node->rsn = NULL;
            fa->lsn = new_node;
        }
        else{
            build(fa->lsn, x);
        }
    }
    else{
        if(fa->rsn == NULL){
            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = x;
            new_node->lsn = new_node->rsn = NULL;
            fa->rsn = new_node;
        }
        else{
            build(fa->rsn, x);
        }
    }
}

void del(struct node **fa, int x){
    struct node *self = *fa;
    if(self == NULL)
        return;
    if(x < self->data)
        del(&self->lsn, x);
    else if (x > self->data)
        del(&self->rsn, x);
    else{
        if(self->lsn != NULL && self->rsn != NULL){
            struct node *p = self->lsn;
            while(p->rsn != NULL && p->rsn->rsn != NULL)
                p = p->rsn;
            if(p->rsn == NULL){
                p->rsn = self->rsn;
                *fa = p;
            }
            else{
                struct node *tmp = p->rsn->lsn;
                p->rsn->rsn = self->rsn;
                p->rsn->lsn = self->lsn;
                *fa = p->rsn;
                p->rsn = tmp;
            }
        }
        else if(self->lsn != NULL && self->rsn == NULL)
            *fa = self->lsn;
        else if(self->lsn == NULL && self->rsn != NULL)
            *fa = self->rsn;
        else
            *fa = NULL;
    }
}

void mid_print(struct node *fa){
    printf("%4d", fa->data);
    if(fa->lsn != NULL)
        mid_print(fa->lsn);
    if(fa->rsn != NULL)
        mid_print(fa->rsn);
}

int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    nodes[siz++] = root;
    root->lsn = root->rsn = NULL;
    scanf("%d", &root->data);

    int x;
    scanf("%d", &x);
    while(x != -1){
        build(root, x);
        scanf("%d", &x);
    }

    scanf("%d", &x);
    del(&root, x);

    if(root == NULL){
        printf("%4d", -1);
        return 0;
    }
    mid_print(root);
    while(siz--)
        free(nodes[siz]);
    return 0;
}