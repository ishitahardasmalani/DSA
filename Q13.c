#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top=0;

void push(int x)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=top;
    top=newnode;
}
void display()
{
    struct node *temp;
    temp=top;
    if(top==0)
        printf("List is Empty\n");
    else
    {
        while(temp!=0)
        {
            printf("%d",temp->data);
            temp=temp->next;
        }
    }
}

void peek()
{
    if(top==0)
        printf("List is Empty\n");
    else
        printf("TOp element is %d",top->data);
}
void pop()
{
    struct node *temp;
    temp=top;
    if(top==0)
        printf("List is Empty\n");
    else
    {
        printf("Popped Element is %d",top->data);
        top=top->next;
        free(temp);
    }
}
int main()
{
    int val , option,x;
    do
    {
        printf("\n **MAIN MENU**");
        printf("\n 1. PUSH");
        printf("\n 2. DISPLAY");
        printf("\n 3. PEEK");
        printf("\n 4. POP");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("Enter Value to be pushed:\n");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                display();
                break;
            case 3:
                peek();
                break;
            case 4:
                pop();
                break;
            case 5: break;
        }
    }while(option!=6);
}
