#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *start = NULL;

int insertBeg(int x)
{
    NODE *ptr;
    ptr = (NODE *)malloc(sizeof(NODE));
    if (ptr == NULL)
        return 0;

    ptr->data = x;
    ptr->next = NULL;

    if (start == NULL)
        start = ptr;
    else
    {
        ptr->next = start;
        start = ptr;
    }
    return 1;
}
int insertEnd(int x)
{
    NODE *ptr, *p;
    ptr = (NODE *)malloc(sizeof(NODE));
    if (ptr == NULL)
        return 0;

    ptr->data = x;
    ptr->next = NULL;

    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        p = start;
        while (p->next != NULL)
            p = p->next;

        p->next = ptr;
    }
    return 1;
}

int insert_begin(int x, int key)
{
    NODE *p, *ptr;

    ptr = (NODE *)malloc(sizeof(NODE));
    if (ptr == NULL)
    {
        printf("Memory full");
        return 0;
    }

    ptr->data = x;
    ptr->next = NULL;

    while (p->next != NULL && p->data != key)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Key not found");
        return 0;
    }
    else
    {
        ptr->next = ptr->next;
        p->next = ptr;
        return 1;
    }
}

int insert_pos(int x, int pos)
{
    NODE *p, *ptr;

    ptr = (NODE *)malloc(sizeof(NODE));

    if (ptr == NULL)
    {
        printf("Memory full!");
        return 0;
    }

    ptr->data = x;
    ptr->next = NULL;

    if (pos < 1)
    {
        printf("Position invalid");
        return 0;
    }
    else if (pos == 1)
    {
        ptr->next = start;
        start = ptr;
        return 0;
    }
    else
    {
        p = start;
        for (int i = 1; i < pos - 1; i++)
        {
            if (p == NULL)
            {
                printf("Invalid position");
                return 0;
            }
            p = p->next;
        }
        ptr->next = p->next;
        p->next = ptr;
    }
    return 1;
}

int insert_before_key(int x, int key)
{
    NODE *prev, *ptr, *p;

    ptr = (NODE *)malloc(sizeof(NODE));

    if (ptr == NULL)
    {
        printf("Memory full!");
        return 0;
    }

    ptr->data = x;
    ptr->next = NULL;

    while (p != NULL && p->data != key)
    {
        prev = p;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("Key not found");
        return 0;
    }
    if (p == start)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        ptr->next = p;
        prev->next = ptr;
    }

    return 1;
}

int del_begin()
{
    NODE *p;
    int temp;

    if (start == NULL)
    {
        printf("Linked list is empty");
        return 0;
    }

    p = start;
    start = start->next;
    p->next = NULL;
    temp = p->data;
    free(p);

    return temp;
}

int delete_rear()
{
    NODE *p, *prev;
    int temp;

    if (start == NULL)
    {
        printf("Linkedlist is empty");
        return 0;
    }

    p = start;
    prev = NULL;

    while (p->next != NULL)
    {
        prev = p;
        p = p->next;
    }

    if (start->next == NULL)
    {
        start = NULL;
    }
    else
    {
        prev->next = NULL;
    }

    temp = p->data;
    free(p);

    return temp;
}

int delete_after(int key)
{
    NODE *p, *q;
    int temp;

    p = start;

    while (p != NULL && p->data != key)
    {
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Key not found bitch!");
        return 0;
    }

    if (p->next != NULL)
    {
        printf("Key found at last position");
        return 0;
    }

    q = p->next;
    p->next = q->next;
    q->next = NULL;
    temp = q->data;
    free(q);

    return temp;
}

int delete_key(int key)
{
    NODE *p, *prev;
    int temp;

    p = start;

    while (p != NULL && p->data != key)
    {
        prev = p;
        p = p->next;
    }

    if (p == NULL)
    {
        printf("Key not found");
        return 0;
    }

    if (p == start)
    {
        start = start->next;
    }
    else
    {
        prev->next = p->next;
    }

    temp = p->data;
    p->next = NULL;
    free(p);
    return temp;
}

/* int delete_before(int key){} */

void display()
{
    NODE *p;

    if (start == NULL)
    {
        printf("Linklist is empty");
    }
    else
    {
        p = start;
        while (p != NULL)
        {
            printf("%d", p->data);
            p = p->next;
        }
    }
}

int empty()
{
    if (start == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int full()
{
    NODE *ptr;

    ptr = (NODE *)malloc(sizeof(NODE));

    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        free(ptr);
        return 0;
    }
}

int search(int key)
{
    NODE *p;
    p = start;

    while (p != NULL && p->data != key)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void create()
{
    int n, i, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 1; i < n; i++)
    {
        scanf("%d", &key);
        insert_end(key);
    }
}

void destroy()
{
    NODE *p, *prev;

    p = start;
    prev = NULL;

    while (p != NULL)
    {
        prev = p;
        p = p->next;
        free(prev);
    }

    start = NULL;
}

void create_revised()
{
    int key;
    char option;
}

int size(){
    int count=1;

    NODE *p;

    p=start;

    while(p!=NULL){
        p=p->next;
        count++;
    }

    return count;
}