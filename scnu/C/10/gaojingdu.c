#include <stdio.h>
#include <stdlib.h>
char op, opp;
typedef struct node
{
    int data;
    struct node *next;
} link;
link *add(link *a, link *b);
link *minus(link *a, link *b, int sign);
void multi(link *a, link *b);

int main()
{
    link *ahead = NULL, *bhead = NULL;
    int i, flag;
    int tt;

    char temp;
    scanf("%c", &temp);
    i = 0;
    while (temp != '\n')
    {
        flag = 1;
        if (i == 0)
        {
            if (temp == '-')
            {
                ahead = (struct node *)malloc(sizeof(struct node));
                ahead->data = 1; // 1代表府－
                ahead->next = NULL;
            }
            else //+
            {
                ahead = (struct node *)malloc(sizeof(struct node));
                ahead->data = 0; // 0代表＋
                ahead->next = NULL;

                flag = 0;
            }
        }
        else
        {
            struct node *node = (struct node *)malloc(sizeof(struct node));
            tt = temp;
            node->data = tt - '0'; // 数
            // printf("%d",node->data);

            node->next = ahead->next;
            ahead->next = node;
        }

        i++;
        if (flag == 1)
        {
            scanf("%c", &temp);
        }
    }

    scanf("%c", &op);
    scanf("%c", &temp);
    if (temp == '\n')
    {
        scanf("%c", &temp);
    }
    i = 0;
    while (temp != '\n')
    {
        flag = 1;
        if (i == 0)
        {
            if (temp == '-')
            {
                bhead = (struct node *)malloc(sizeof(struct node));
                bhead->data = 1; // 1代表－
                bhead->next = NULL;
            }
            else //+
            {
                bhead = (struct node *)malloc(sizeof(struct node));
                bhead->data = 0; // 0代表＋
                bhead->next = NULL;

                flag = 0;
            }
        }
        else
        {
            struct node *node = (struct node *)malloc(sizeof(struct node));
            tt = temp;
            node->data = tt - '0'; // 数
            // printf("%d",node->data);

            node->next = bhead->next;

            bhead->next = node;
        }

        i++;
        if (flag == 1)
        {
            scanf("%c", &temp);
        }
    }
    opp = op;
    if (opp == '+')
    {
        if (ahead->data == 0 && bhead->data == 0) // 都为正
        {
            add(ahead, bhead);
        }
        else if (ahead->data == 1 && bhead->data == 1) // 都为负
        {
            add(ahead, bhead);
        }
        else if (ahead->data == 0 && bhead->data == 1) // 正加负＝正减正
        {
            op = '-';
            bhead->data = 0;
            minus(ahead, bhead, 0);
        }
        else if (ahead->data == 1 && bhead->data == 0) // 负加正＝正减正
        {
            op = '-';
            bhead->data = 0;
            ahead->data = 0;
            minus(bhead, ahead, 0);
        }
    }

    if (opp == '-')
    {
        if (ahead->data == 0 && bhead->data == 0) // 都为正
        {
            minus(ahead, bhead, 0);
        }
        else if (ahead->data == 1 && bhead->data == 1) // 负减负=负加正＝正减正
        {
            bhead->data = 0;
            ahead->data = 0;
            minus(bhead, ahead, 0);
        }
        else if (ahead->data == 0 && bhead->data == 1) // 正减负＝正加正
        {
            op = '+';
            bhead->data = 0;
            add(ahead, bhead);
        }
        else if (ahead->data == 1 && bhead->data == 0) // 负减正＝负加负
        {
            op = '+';
            bhead->data = 1;
            add(bhead, ahead);
        }
    }
    if (opp == '*')
    {
        multi(ahead, bhead);
    }

    return 0;
}
link *add(link *a, link *b)
{
    int c; // 进位
    link *result = (link *)malloc(sizeof(link));

    if (a->data == 0 && b->data == 0) // 全正
    {
        result->data = 0;
    }
    if (a->data == 1 && b->data == 1) // 全负
    {
        result->data = 1;
    }
    result->next = NULL;

    a = a->next;
    b = b->next;
    c = 0;
    while (a != NULL && b != NULL)
    {

        struct node *node = (struct node *)malloc(sizeof(struct node));

        node->data = (a->data + b->data + c) % 10;
        // printf("%d",node->data);

        node->next = result->next;
        result->next = node;

        c = (a->data + b->data + c) / 10;

        a = a->next;
        b = b->next;
    }
    // putchar('o');
    while (a != NULL)
    {
        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->data = (a->data + c) % 10;

        node->next = result->next;
        result->next = node;

        c = (a->data + c) / 10;

        a = a->next;
    }
    while (b != NULL)
    {
        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->data = (b->data + c) % 10;

        node->next = result->next;
        result->next = node;

        c = (b->data + c) / 10;

        b = b->next;
    }
    if (c == 1) // 还有进位
    {
        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->data = 1;

        node->next = result->next;
        result->next = node;
    }

    if (result->data == 1)
    {
        putchar('-');
    }
    result = result->next;
    while (result != NULL)
    {
        printf("%d", result->data);
        result = result->next;
    }

    putchar('\n');

    return result;
}
link *minus(link *a, link *b, int sign)
{
    struct node *ta = a, *tb = b; // 保留原来的a和b
    struct node *n;
    int c; // 借位
    link *result = (link *)malloc(sizeof(link));

    result->data = sign;
    result->next = NULL;

    a = a->next;
    b = b->next;
    c = 0;
    while (a != NULL && b != NULL)
    {

        struct node *node = (struct node *)malloc(sizeof(struct node));

        // node->data=(a->data+b->data+c)%10;
        //  printf("%d",node->data);
        if ((a->data - b->data - c) < 0)
        {

            node->data = a->data + 10 - b->data - c;

            c = 1;
        }
        else
        {
            node->data = a->data - b->data - c;
            c = 0;
        }
        node->next = result->next;
        result->next = node;

        a = a->next;
        b = b->next;
    }
    if (a == NULL && b != NULL || a == NULL && b == NULL && c != 0)
    {

        return minus(tb, ta, 1);
    }
    else
    {
        // putchar('o');
        while (a != NULL)
        {
            struct node *node = (struct node *)malloc(sizeof(struct node));
            if ((a->data - c) < 0)
            {

                node->data = a->data + 10 - c;

                c = 1;
            }
            else
            {
                node->data = a->data - c;
                c = 0;
            }
            node->next = result->next;
            result->next = node;
            a = a->next;
        }
    }
    if (result->data == 1)
    {
        putchar('-');
    }
    n = result->next;
    while (n != NULL && n->data == 0)
    {
        n = n->next;
    }
    if (n != NULL)
    {
        result = n;
        while (result != NULL)
        {

            printf("%d", result->data);
            result = result->next;
        }
    }
    else
    {
        printf("%d", 0);
    }

    putchar('\n');

    return result;
}
void multi(link *a, link *b)
{
    int result[2501] = {0}, num, i, j;
    link *ta, *tb; // 用作循环

    int c, cc; // 进位

    // link* result=(link*)malloc(sizeof(link));
    if (a->data == 1 && b->data == 0)
    {
        result[0] = 1;
    }
    else if (a->data == 0 && b->data == 1)
    {

        result[0] = 1;
    }
    else
    {
        result[0] = 0;
    }

    ta = a->next;

    i = 1;
    cc = 0;

    while (ta != NULL)
    {
        c = 0;
        cc = 0;
        tb = b->next;
        j = i;
        while (tb != NULL)
        {

            int temp = result[j];
            result[j] = (result[j] + (ta->data * tb->data + c) % 10 + cc) % 10;
            // printf("%d",node->data);

            //    c=(ta->data*tb->data+c)/10;
            cc = (temp + (ta->data * tb->data + c) % 10 + cc) / 10;
            c = (ta->data * tb->data + c) / 10;
            j++; // error!!!!!!!
            tb = tb->next;
        }
        // printf("%d %d/n",c,cc);
        if ((cc + c) > 0)
        {
            // printf("%d %d %d/n",c,cc,j);
            result[j] = result[j] + cc + c;
            j++;
        }

        i++;

        ta = ta->next;
    }
    // if(cc>0)//还有进位
    // {
    //  struct node* node=(struct node*)malloc(sizeof(struct node));
    //  node->data=cc;

    //  node->next=result->next;
    //  result->next=node;
    // }
    if (result[0] == 1)
    {
        putchar('-');
    }
    i = j - 1;
    while (i >= 1 && result[i] == 0)
    {
        i--;
    }
    if (i >= 1)
    {
        j = i;
        while (j >= 1)
        {

            printf("%d", result[j]);
            j--;
        }
    }
    else
    {
        printf("%d", 0);
    }
    putchar('\n');
}