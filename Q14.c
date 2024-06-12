#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front =0;
struct node *rear =0;

void enqueue(int x)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(newnode));
    newnode->data=x;
    newnode->next=0;
    if(front==0 && rear==0)
        front=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void display()
{
    struct node *temp;
    if(front==0 && rear==0)
        printf("Underflow\n");
    else
    {
        temp = front;
        while(temp!=0)
        {
            printf("\t%d\t",temp->data);
            temp=temp->next;
        }
    }
}

void dequeue()
{
    struct node *temp;
    if(front==0 && rear==0)
        printf("Underflow\n");
    else
    {
        printf("%d",front->data);
        front=front->next;
        free(temp);
    }
}
void peek()
{
    if(front==0 && rear==0)
        printf("Underflow\n");
    else
        printf("%d",front->data);
}

int main()
{
    int option,x;

    do
    {
        printf("*MAIN MENU*\n");
        printf("1.ENQUEUE\n");
        printf("2.DISPLAY\n");
        printf("3.DEQUEUE\n");
        printf("4.PEEK\n");
        printf("Enter Option:\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                printf("Enter Data to be inserted:\n");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                display();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                peek();
                break;

        }
    }while(option!=6);
}
