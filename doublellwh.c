#include<stdio.h>
#include<malloc.h>
#include<conio.h>


typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE;

NODE *start=NULL;




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
        ptr->prev=NULL;
    if(start==NULL)
    {
        start=ptr;
        printf("%d is inserted. ",x);
        return 1;
    }
        p=start;
        while(p->next!=NULL)
            p=p->next;

        p->next=ptr;
        ptr->prev=p;

        printf("%d is inserted",x);
        return 1;
}


void create()
{
    char option;
    int x;
    start=NULL;
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
        ptr->prev=NULL;
        if(start==NULL)
        {
            start=ptr;

            printf("%d is inserted", x);
            return 1;

        }
        ptr->next=start;
        start->prev=ptr;
        start=ptr;


        printf("%d is inserted", x);
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
        ptr->prev=NULL;

        p=start;
        while(p!=NULL && p->data!=key)
            p=p->next;

        if(p==NULL)
            {

                printf("%d not found.",key);
                return 0;
            }
            ptr->next=p->next;
            if(ptr->next!=null)
                ptr->next->prev=ptr;
            ptr->prev=p;
            p->next=ptr;

            printf("%d is inserted",x);
            return 1;


}

int insert_before(int key,int x)
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
        ptr->prev=NULL;

        p=start;

        while(p!=NULL && p->data!=key)
        {

            p=p->next;
        }

        if(p==NULL)
            {

                printf("%d not found. ",key);
                return 0;
            }
        if(p==start)
        {
            ptr->next=p;
            p->prev=ptr;
            start=ptr;
        }
        else
          {

            ptr->prev=p->prev;
            ptr->next=p;
            ptr->prev->next=ptr;
            p->prev=ptr;
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
        ptr->prev=NULL;

        if(pos<=1)
        {
            ptr->next=start;
            start->prev=ptr;
            start=ptr;
        }
        else
        {
            p=start;
            for(i=1;i<pos-1;i++)
            {
                p=p->next;
                if(p==NULL)
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

            ptr->next=p->next;
            ptr->next->prev=ptr;
            ptr->prev=p;
            p->next=ptr;
        }
            printf("%d is inserted. ",x);
            return 1;


}

void tellcount()
{
    NODE *p;
    int count=0;
    p=start;
    while(p!=NULL)
    {
            p=p->next;
            count++;
    }
    printf("The number of elements are %d",count);
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
    printf("The contents of list are\n");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

void destroy()
{
    NODE *p,*q;
    q=start;
    p=NULL;
    while(q!=NULL)
    {
        p=q;
        q=q->next;
        free(p);
    }
    free(start);
}

int delete_beg()
{
    NODE *ptr;
    ptr=start;
    if(ptr==NULL)
    {
        printf("No elements in the list. ");
        return 0;
    }
    start=start->next;
    start->prev=NULL;
    ptr->next=NULL;

    printf("%d is deleted. ",ptr->data);
    free(ptr);
    return 1;
}

int delete_end()
{
    NODE *ptr;
    ptr=start;
    if(ptr==NULL)
    {
        printf("No elements in the list. ");
        return 0;
    }
    if(start->next==NULL)
    {
        start=NULL;
        printf("%d is deleted",ptr->data);
        free(ptr);
        return 1;
    }
    while(ptr->next!=NULL)
            ptr=ptr->next;

    ptr->prev->next=NULL;
    ptr->prev=NULL;

    printf("%d is deleted",ptr->data);
    free(ptr);
    return 1;
}

int delete_node(int key)
{
    NODE *ptr;
    ptr=start;
    if(ptr==NULL)
    {
        printf("No elements in the list. ");
        return 0;
    }
    if(start->data==key)
    {
        start=start->next;
        start->prev=NULL;
        ptr->next=NULL;

        printf("%d is deleted",ptr->data);
        free(ptr);
        return 1;
    }

    while(ptr!=NULL && ptr->data!=key)
        ptr=ptr->next;

    if(ptr==NULL)
    {
        printf("Element to be deleted not found. ");
        return 0;
    }

    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    ptr->next=NULL;
    ptr->prev=NULL;
    printf("%d is deleted",ptr->data);
    free(ptr);
    return 1;
}

int delete_after(int key)
{
    NODE *p,*ptr=NULL;
    p=start;
    if(p==NULL)
    {
        printf("No elements in the list. ");
        return 0;
    }
    if(start->next==NULL)
    {
        printf("Only one element in the list. ");
        return 0;
    }
    while(p->next!=NULL && p->data!=key)
        p=p->next;

    if(p->next==NULL)
    {
        printf("Element to be deleted after not found. ");
        return 0;
    }

    p->next=ptr;

    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
    ptr->next=NULL;
    ptr->prev=NULL;

    printf("%d is deleted",ptr->data);
    free(ptr);
    return 1;

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
