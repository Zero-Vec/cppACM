#include <stdio.h>
#include <stdlib.h>

// 定义双向链表节点
typedef struct DLIST
{
    int data;
    struct DLIST *pPre;
    struct DLIST *pNext;
} DLIST;

DLIST *createNode(int data);
DLIST *reverseList(DLIST *head);
void deleteNode(DLIST **head, int numToDelete);
void freeList(DLIST *head);

int main()
{
    FILE *input = fopen("dlist.in", "r");
    int n, numToDelete;
    fscanf(input, "%d", &n);

    int data;
    fscanf(input, "%d", &data);
    DLIST *head = createNode(data);
    DLIST *tail = head;

    for (int i = 1; i < n; i++)
    {
        fscanf(input, "%d", &data);
        DLIST *newNode = createNode(data);
        newNode->pPre = tail;
        tail->pNext = newNode;
        tail = newNode;
    }

    fscanf(input, "%d", &numToDelete);
    fclose(input);

    deleteNode(&head, numToDelete);

    DLIST *reversedHead = reverseList(head);

    FILE *output = fopen("dlist.out", "w");
    if (output == NULL)
    {
        perror("Failed to open output file");
        freeList(reversedHead);
        return 1;
    }

    if (reversedHead == NULL)
    {
        fprintf(output, "-1\n");
    }
    else
    {
        DLIST *current = reversedHead;
        while (current != NULL)
        {
            fprintf(output, "%d ", current->data);
            current = current->pNext;
        }
        fprintf(output, "\n");
    }

    fclose(output);
    freeList(reversedHead);
    return 0;
}

DLIST *createNode(int data)
{
    DLIST *node = (DLIST *)malloc(sizeof(DLIST));
    node->data = data;
    node->pPre = NULL;
    node->pNext = NULL;
    return node;
}

void deleteNode(DLIST **head, int numToDelete)
{
    DLIST *current = *head;
    while (current != NULL)
    {
        if (current->data == numToDelete)
        {
            if (current->pPre != NULL)
            {
                current->pPre->pNext = current->pNext;
            }
            else
            {
                *head = current->pNext;
                if (*head != NULL)
                {
                    (*head)->pPre = NULL;
                }
            }

            if (current->pNext != NULL)
            {
                current->pNext->pPre = current->pPre;
            }

            DLIST *temp = current;
            current = current->pNext;
            free(temp); // 释放已删除的节点
        }
        else
        {
            current = current->pNext;
        }
    }
}

DLIST *reverseList(DLIST *head)
{
    DLIST *current = head;
    DLIST *newHead = NULL;

    while (current != NULL)
    {
        DLIST *temp = current->pNext;
        current->pNext = newHead;
        current->pPre = NULL;
        if (newHead != NULL)
        {
            newHead->pPre = current;
        }
        newHead = current;
        current = temp;
    }

    return newHead;
}

void freeList(DLIST *head)
{
    DLIST *current = head;
    while (current != NULL)
    {
        DLIST *temp = current;
        current = current->pNext;
        free(temp);
    }
}
