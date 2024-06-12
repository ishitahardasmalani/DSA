1. Implement Stack ADT using arrays.

#include<stdio.h>
#define MAX 10
int stackArray[MAX];
int top=-1;

int push(int data)
{
    if(top==MAX-1)
    {
        printf("Stack is full\n");
        return 0;
    }
    top++;
    stackArray[top]=data;
    return 1;
}

int pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return 0;
    }
    data=stackArray[top];
    top--;
    return data;
}

int peek()
{
    if(top==-1)
    {
        printf("Stack is empty, no element is present\n");
        return 0;
    }
    else
        return stackArray[top];
}

int isFull()
{
    if(top==MAX-1)
    {
        printf("Stack is full\n");
        return 1;
    }
    else
        return 0;
}

int isEmpty()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return 1;
    }
    return 0;
}

void display()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return 0;
    }
    else
    {
        for(i=top;i>=0;i++)
        {
            printf("%d", stackArray[i]);
        }
    }
}

int size()
{
    return top+1;
}
