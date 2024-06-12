#include<stdio.h>
#include<malloc.h>
typedef struct node
{
    int data;
    struct node*next;
}NODE;

NODE*start;

int Insert_end(int x)
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

