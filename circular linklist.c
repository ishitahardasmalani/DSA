#include<stdio.h>
#include<malloc.h>
#include<conio.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *start=NULL;
NODE *end=NULL;

void create()
{
    char option;
    int x;
    start=NULL;
    end=NULL;
    option='y';
    while(option=='Y' || option=='y')
    {
        printf("Enter the value of the node to be inserted\n");
        scanf("%d",&x);
        insert_end(x);
        fflush(stdin);
        printf("Do you want to enter more data?[Y/N]\n");
        scanf("%c",&option);

    }
}
int insert_beg(int x)
{
    NODE *ptr;
    ptr=(NODE *)malloc(sizeof(NODE));

    if(ptr==NULL)
      {
        printf("Memory full. ");
        return 0;
      }
    ptr->data=x;
    ptr->next=NULL;

    if(start==NULL)
    {
        start=ptr;
        end=ptr;
        end->next=start;
    }
    else
    {
        ptr->next=start;
        start=ptr;
        end->next=start;
    }
    printf("%d is inserted", x);
    return 1;
}

int insert_end(int x)
{
    NODE *ptr,*p;
    ptr=(NODE *)malloc(sizeof(NODE));

    if(ptr==NULL)
     {
        printf("Memory full. ");
        return 0;
     }
        ptr->data=x;
        ptr->next=NULL;

        if(start==NULL)
        {
            start=ptr;
            end=ptr;
            end->next=start;
        }
        else
        {
            end->next=ptr;
            end=ptr;
            end->next=start;
        }
        printf("%d is inserted",x);
        return 1;
}

int insert_after(int key,int x)
{
    NODE *ptr,*p;
    ptr=(NODE *)malloc(sizeof(NODE));
    if(ptr==NULL)
     {
        printf("Memory full. ");
        return 0;
     }
    ptr->data=x;
    ptr->next=NULL;

    p=start;
    while(p!=end && p->data!=key)
        p=p->next;

    if(p==end && p->data!=key)
    {
        printf("%d not found.",key);
        return 0;
    }
    if(p==end)
    {
        p->next=ptr;
        end=ptr;
        end->next=start;
    }
    else
    {
        ptr->next=p->next;
        p->next=ptr;
    }
    printf("%d is inserted",x);
    return 1;
}

int insert_before(int key,int x)
{
    NODE *ptr,*p,*prev;
    ptr=(NODE *)malloc(sizeof(NODE));

    if(ptr==NULL)
    {
        printf("Memory full. ");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;

    if(start==NULL)
    {
        printf("Linklist is empty");
        return 0;
    }
    p=start;
    prev=NULL;

    while(p!=end && p->data!=key)
    {
        prev=p;
        p=p->next;
    }

    if(p==end && p->data!=key)
    {
        printf("%d not found. ",key);
        return 0;
    }
    else if(p==start)
    {
        ptr->next=p;
        start=ptr;
        end->next=start;
    }
    else
    {
        ptr->next=prev->next;
        prev->next=ptr;
    }
    printf("%d is inserted. ",x);
    return 1;
}

int insert_position(int pos, int x)
{
    NODE *ptr,*p;
    int i,flag=0;
    ptr=(NODE *)malloc(sizeof(NODE));

    if(ptr==NULL)
    {
        printf("Memory full. ");
        return 0;
    }

    ptr->data=x;
    ptr->next=NULL;

    if(pos<0)
    {
        printf("Invalid position");
        return 0;
    }
    else if(pos<=1)
    {
        if(start=NULL)
            start=end=ptr;
        else
        {
            ptr->next=start;
            start=ptr;
            end->next=start;
        }
    }
    else
    {
        p=start;
        for(i=1;i<=pos-2;i++)
        {
            p=p->next;
            if(p==start)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("Invalid position.");
            return 0;
        }
        else if(p==end)
        {
            end->next=ptr;
            end=ptr;
            end->next=start;
        }
        else
        {
            ptr->next=p->next;
            p->next=ptr;
        }
    }

    printf("%d is inserted. ",x);
    return 1;
}

void tellcount()
{
    NODE *p;
    int count=0;
    p=start;
    if(p==NULL)
        printf("The number of elements are 0. ");
    else
    {
        while(p!=end)
        {
            p=p->next;
            count++;
        }
        printf("The number of elements are %d. ",count+1);
    }
}

void empty()
{
   if(start==NULL)
        printf("Linklist is empty");
    else
        printf("Linklist is not empty");
}

void full()
{
    NODE *p;
    p=(NODE *)malloc(sizeof(NODE));
    if(p==NULL)
        printf("Linklist is full");
    else
    {
        free(p);
        printf("Linklist is not full");
    }

}

void traverse()
{
    NODE *p=start;
    if(p==NULL)
        printf("Linklist is empty");
    else
    {
        printf("The contents of list are\n");
        while(p!=end)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        printf("%d",end->data);
    }
}

int delete_beg()
{
    NODE *p;
    int x;
    p=start;
    if(start==NULL)
    {
        printf("No elements in the list. ");
        return -65536;
    }
    if(start==end)
        start=end=NULL;
    else
    {
        start=start->next;
        end->next=start;
        p->next=NULL;
    }
    x=p->data;
    printf("%d is deleted. ",p->data);
    free(p);
    return x;
}

int delete_end()
{
    NODE *p,*prev;
    int x;
    p=start;
    prev=NULL;
    if(p==NULL)
    {
        printf("No elements in the list. ");
        return -65536;
    }
    if(start==end)
    {
        start=NULL;
        end=NULL;
    }
    else
    {
        while(p!=end)
        {
            prev=p;
            p=p->next;
        }
    end=prev;
    end->next=start;
    }
    x=p->data;
    printf("%d is deleted",x);
    free(p);
    return x;
}

int delete_node(int key)
{
    NODE *p,*prev;
    int x;
    p=start;
    prev=NULL;
    if(start==NULL)
    {
        printf("No elements in the list. ");
        return -65536;
    }
    while(p!=end && p->data!=key)
    {
        prev=p;
        p=p->next;
    }
    if(p==end && p->data!=key)
    {
        printf("Element to be deleted not found. ");
        return -65536;
    }
    if(p==end && p->data==key)
    {
        end=prev;
        end->next=start;
    }
    else if(p==start)
    {
        start=start->next;
        end->next=start;
    }
    else
        prev->next=p->next;

    p->next=NULL;
    x=p->data;
    printf("%d is deleted",x);
    free(p);
    return x;
}

int delete_after(int key)
{
    NODE *p,*q;
    int x;
    p=start;
    if(start==NULL)
    {
        printf("No elements in the list. ");
        return -65536;
    }
    if(start==end)
    {
        printf("Only one element in the list. ");
        return -65536;
    }
    while(p!=end && p->data!=key)
        p=p->next;

    if(p==end && p->data!=key)
    {
        printf("Element to be deleted after not found. ");
        return -65536;
    }
    else if(p==end && p->data==key)
    {
        printf("No element after end to delete. ");
        return -65536;
    }
    else
    {
        q=p->next;
        p->next=q->next;
        if(q==end)
        {
            end=p;
            end->next=start;
        }
        x=q->data;
        q->next=NULL;
        free(q);
        printf("%d is deleted",x);
        return x;
    }
}

void destroy()
{
    NODE *p,*q;
    q=start;
    p=NULL;
    while(q!=end)
    {
        p=q;
        q=q->next;
        free(p);
    }
    free(q);
    start=NULL;
    free(start);
}

int main()
{
    int option,x,pos,op,key;

    do
    {
        printf("\n **Choose an option**");
        printf("\n1. Create a list");
        printf("\n2. Display the list");
        printf("\n3. Add a node at the beginning");
        printf("\n4. Add a node at the end");
        printf("\n5. Add a node before a given node");
        printf("\n6. Add a node after a given node");
        printf("\n7. Add a node at a specific position");
        printf("\n8. Delete a node from the beginning");
        printf("\n9. Delete a node from the end");
        printf("\n10. Delete a given node");
        printf("\n11. Delete a node after a given node");
        printf("\n12. Destroy the entire list");
        printf("\n13. Check whether list is empty");
        printf("\n14. Check whether list if full");
        printf("\n15. Count the number of elements in the list");
        printf("\n16. EXIT");

        printf("\n\n Enter your option: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:create();
                    break;

            case 2:traverse();
                    break;

            case 3: printf("\n Enter the node to be inserted");
                    scanf("%d",&x);
                    op=insert_beg(x);
                    if(op==0)
                        printf("Element not inserted. ");

                    break;

            case 4: printf("\n Enter the node to be inserted");
                    scanf("%d",&x);
                    op=insert_end(x);
                    if(op==0)
                        printf("Element not inserted. ");

                    break;

            case 5: printf("\n Enter the node to be inserted");
                    scanf("%d",&x);
                    printf("\n Enter the node before which data is to be inserted");
                    scanf("%d",&key);

                    op=insert_before(key,x);
                    if(op==0)
                        printf("Element not inserted. ");

                    break;


            case 6: printf("\n Enter the node to be inserted");
                    scanf("%d",&x);
                    printf("\n Enter the node after which data is to be inserted");
                    scanf("%d",&key);

                    op=insert_after(key,x);
                    if(op==0)
                        printf("Element not inserted. ");

                    break;


            case 7: printf("\n Enter the node to be inserted");
                    scanf("%d",&x);
                    printf("\n Enter the position where data is to be inserted");
                    scanf("%d",&pos);

                    op=insert_position(pos,x);
                    if(op==0)
                        printf("Element not inserted. ");

                    break;

            case 8:op=delete_beg();
                    if(op==0)
                        printf("Deletion not possible");

                    break;

            case 9:op=delete_end();
                    if(op==0)
                        printf("Deletion not possible");

                    break;

            case 10: printf("Enter the node to be deleted");
                     scanf("%d",&key);

                     op=delete_node(key);
                     if(op==0)
                        printf("Deletion not possible");

                    break;

            case 11: printf("Enter the node after which data is to be deleted");
                     scanf("%d",&key);

                     op=delete_after(key);
                     if(op==0)
                        printf("Deletion not possible");

                    break;

            case 12: destroy();
                    printf("Linklist is destroyed");
                    break;

            case 13:empty();
                    break;

            case 14:full();
                    break;

            case 15:tellcount();
                    break;

            case 16: break;

            default: printf("Invalid option\n");

        }
        getch();
    }
    while(option!=16);

    return 0;
}
