#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node*next;
}NODE;
NODE*start;
int Insert_beg(int x)//function 1..........
{
    NODE *ptr;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("Linklist is full\n");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    if(start==NULL)
    {
        start=ptr;
    }
    else{
    ptr->next=start->next;
    start=ptr;
    }
    return 1;
}
int Insert_end(int x)//function 2.......
{
    NODE *ptr,*p;
    p=start;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("Linklist full\n");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    if(start==NULL)
    {
        start=ptr;
    }
    else
    {
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    }
    return 1;
}
int Insert_after(int key,int x)//function 3.......
{
  NODE *ptr,*p;
    p=start;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("Linklist full\n");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
   if(start==NULL)
   {
       printf("linklist is empty\n");
       return 0;
   }
   while(p!=NULL && p->data!=key)
   {
       p=p->next;
   }
   if(p==NULL)
   {
       printf("element not found\n");
       return 0;
   }
   ptr->next=p->next;
   p->next=ptr;
   return 1;
}
int Insert_before(int key,int x)//function 4.....
{
      NODE *ptr,*p,*prev;
    p=start;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("Linklist full\n");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
   if(start==NULL)
   {
       printf("linklist is empty\n");
       return 0;
   }
   prev=NULL;
   while(p!=NULL && p->data!=key)
   {
       prev=p;
       p=p->next;
       }
       if(p==NULL)
       {
           printf("element not fount\n");
           return 0;
       }
       else if(p==start)
       {
           ptr->next=p;
           start=ptr;
       }
       else{
       ptr->next=p;
       prev->next=ptr;
       }
       return 1;
}
int position(int pos,int x)//function 5.....
{
    NODE *ptr,*p;
    int i;
    ptr=(NODE*)malloc(sizeof(NODE));
    if(ptr==NULL)
    {
        printf("Linklist full\n");
        return 0;
    }
    ptr->data=x;
    ptr->next=NULL;
    if(pos<0)
    {
        printf("Invalid position\n");
        return 0;
    }
    else if(pos<=1)
    {
        if(start==NULL)
    {
       printf("linklist is empty\n");
       return 0;
   }
   else{
    ptr->next=start;
    start=ptr;
   }
    }
else{
    p=start;
    for(i=1;i<=pos-2;i++)
    {
        p=p->next;
        if(p==NULL)
            break;
    }
    if(p==NULL)
    {
        printf("Invalid position\n");
        return 0;
    }
    else{
        ptr->next=p->next;
        p->next=ptr;
    }
}
 return 1;
}
int delete_beg()//function 6....
{
    NODE *p;
    int x;
    if(start==NULL)
    {
        printf("linklist is empty\n");
        return -65536;
    }
    p=start;
    x=p->data;

        start=p->next;
        p->next=NULL;
    free(p);
    return x;
}
int delete_end()//function 7....
{
    NODE *p,*prev;
    int x;
    if(start==NULL)
    {
        printf("linklist is empty\n");
        return -65536;
    }
    if(start->next==NULL)
    {
      p=start;
      x=p->data;
      start=NULL;
    }
    else{
    p=start;
    prev=NULL;
    while(p->next!=NULL)
    {
        prev=p;
        p=p->next;
    }
    x=p->data;
    prev->next=NULL;
    }
    free(p);
    return x;
}
int delete_after(int key)//function 8...
{
    NODE *p,*q;
    int x;
    if(start==NULL)
    {
        printf("linklist is empty\n");
        return -65536;
    }
    if(start->next==NULL)
    {
        printf("only one element\n");
        return -65536;
    }
    else{
        p=start;
        while(p!=NULL && p->data!=key)
        {
            p=p->next;
        }
        if(p==NULL)
        {
            printf("key not found\n");
            return -65536;
        }
        else if(p->next==NULL)
        {
            printf("key is last element\n");
            return -65536;
        }
        else{
            q=p->next;
            p->next=q->next;
            p->next=NULL;
            x=q->data;
            free(q);
        }


    }
}
int delete_node(int key)//function 9....
{
    NODE *p,*prev;
    int x;
    if(start==NULL)
    {
        printf("Linklist is empty\n");
        return -65536;
    }
            p=start;
            prev=NULL;
            while(p!=NULL && p->data!=key)
            {
                prev=p;
                p=p->next;
            }
            if(p==NULL)
            {
                printf("key not found\n");
                return -65536;
            }
            prev->next=p->next;
            x=p->data;
            p->next=NULL;
            free(p);
            return x;
}
void traverse()//function 10....
{
    NODE *p;
     if(start==NULL)
        printf("linklist is empty\n ");
        else{
                p=start;
    printf("elements of linklist are:\n");
    while(p!=NULL)
    {
       printf("%d\t",p->data);
       p=p->next;
    }
}
}
void empty()//function 11....
{
    if(start==NULL)
        printf("linklist is empty\n ");
    else
        printf("not empty\n");
}
void full()//function 12....
{
    NODE *ptr;
    ptr=(NODE *)malloc(sizeof(NODE));
    if(ptr==NULL)
        printf("linklist is full\n");
    else
        printf("not full\n");
}
int count()//function 13.....
{
    NODE *p;
    p=start;
    int count=0;
    while(p!=NULL)
    {
         p=p->next;
        count++;
    }
    return count;
}
void create()//function 14..
{
    int x;
    char option='y';
    while(option=='y'  ||  option=='Y')
    {
        printf("enter element to Insert\n");
        scanf("%d",&x);
        Insert_end(x);
        printf("do you want to Insert more data[Y/N]");
        fflush(stdin);
        scanf("%c",&option);
    }
}
void destroy()//function 15...
{
    NODE *p;
     if(start==NULL)
        printf("linklist is empty\n ");
        else{
    p=start;
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}
}
void main()
{
    int option,y,val,p;
    do
    {
        printf("enter your option\n");
        printf("1.create\n2.destroy\n3.Insert_beg\n4.Insert_end\n5.delete beg\n6.delete end\n7.delete node\n8.traverse\n9.Insertafter\n10.full\n11.empty\n12.count\n13.delete after\n14.Insertbefore\n15.Insert position\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:create();
                    break;
            case 2:destroy();
                    break;
            case 3:printf("enter value\n");
                   scanf("%d",&val);
                   y=Insert_beg(val);
                   if(y==0)
                    printf("Insertion fail\n");
                   else
                    printf("Insertion successfully done\n");
                   break;
             case 4:printf("enter value\n");
                   scanf("%d",&val);
                   y=Insert_end(val);
                   if(y==0)
                    printf("Insertion fail\n");
                   else
                    printf("Insertion successfully done\n");
                   break;
              case 5:y=delete_beg();
                     if(y==-65536)
                        printf("deletion fail\n");
                     else
                        printf("%d has been deleted\n",y);
                     break;
              case 6: y=delete_end();
                     if(y==-65536)
                        printf("deletion fail\n");
                     else
                        printf("%d has been deleted\n",y);
                     break;
               case 7:printf("enter value\n");
                      scanf("%d",&val);
                      y=delete_node(val);
                      if(y==-65536)
                        printf("deletion fail\n");
                     else
                        printf("%d has been deleted\n",y);
                     break;
                case 8:traverse();
                        break;
                case 9: printf("what value after/before you want to Insert\n");
                        scanf("%d",&p);
                        printf("enter value\n");
                        scanf("%d",&val);
                        y=Insert_after(p,val);
                        if(y==0)
                        printf("Insertion fail\n");
                        else
                        printf("Insertion successfully done\n");
                        break;
                  case 10:full();
                           break;
                  case 11:empty();
                           break;
                  case 12:y=count();
                        printf("count=%d",y);
                          break;
                  case 13: printf("what value after/before you want to delete\n");
                           scanf("%d",&p);
                           y=delete_after(p);
                           if(y==-65536)
                        printf("deletion fail\n");
                     else
                        printf("%d has been deleted\n",y);
                     break;
                 case 14:printf("what value after/before you want to Insert\n");
                        scanf("%d",&p);
                        printf("enter value\n");
                        scanf("%d",&val);
                        y=Insert_before(p,val);
                        if(y==0)
                        printf("Insertion fail\n");
                        else
                        printf("Insertion successfully done\n");
                        break;
                  case 15:printf("what position you want to Insert\n");
                        scanf("%d",&p);
                        printf("enter value\n");
                        scanf("%d",&val);
                        y=position(p,val);
                        if(y==0)
                        printf("Insertion fail\n");
                        else
                        printf("Insertion successfully done\n");
                        break;
                   case 0:break;



        }
    }while(option!=0);
}
