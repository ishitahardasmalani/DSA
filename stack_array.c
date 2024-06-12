// PROGRAM TYPED BY ISHITA HARDASMALANI SE COMPS ROLL NO 58 //

#include<stdio.h>
#define MAX 100
int stackArray[MAX];
int top=-1;

void main()
{
    int option;
    int op;
    int data;

    do{

        printf("\nFollowing are the Operations:\n");
        printf("\n1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.Check Full\n");
        printf("6.Check Empty\n");
        printf("7.Quit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter data\n");
            scanf("%d", &data);
            op=push(data);
            if(op==0)
            {
                printf("Push operation failed\n");
            }
            else
            {
                printf("%d pushed successfully\n", data);
            }
            break;

        case 2:
            op=pop();
            if(op==-1)
            {
                printf("\nPop operation failed\n");
            }
            else
                printf("%d is popped\n",op);
            break;

        case 3:
            op=peek();
            if(op==-1)
            {
                printf("Peek operation failed\n");
            }
            else
                printf("%d is at the top\n",op);
                break;

        case 4:
            op=display();
            break;

        case 5:
            op=isFull();
            if(op==1)
            {
                printf("Stack is full\n");
            }
            else
                printf("Stack is not full\n");
            break;

        case 6:
            op=isEmpty();
            if(op==1)
            {
                printf("Stack is empty\n");
            }
            else
                printf("Stack is not empty\n");
            break;

        case 7:
            break;

            default:printf("Invalid operation\n");

        }

    }while (option!=7);
}



int push(int data)
{
    if (top==MAX-1)
    {
        printf("Stack is full");
        return 0;
    }
    top++;
    stackArray[top]=data;
    return 1;
}



int pop()
{
    int data;
    if(top==-1)
    {
        printf("Stack is empty");
        return -1;
    }
    data=stackArray[top];
    top--;
    return data;
}


int peek()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return -1;
    }
    return stackArray[top];
}



int isFull()
{
    if(top==MAX-1)
     {
         return 1;
     }
     return 0;
}


int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    return 0;
}


void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("\n%d", stackArray[i]);
        }
    }
}
