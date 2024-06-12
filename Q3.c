//3. Evaluate postfix expression using Stack ADT

#include<stdio.h>
#include<string.h>
#define MAX 50

int top=-1;
float opndstack[MAX];

int push(float x)
{
    if(top==MAX-1)
    {
        printf("Stack is full\n");
        return 0;
    }
    top++;
    opndstack[top]=x;
    return 1;
}

int pop()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return 0;
    }
    top--;
    return opndstack[top+1];

}

float eval_postfix(char postfix[])
{
    int i=0;
    float opnd1,opnd2,value;
    while(postfix[i]!='\0')
    {
        if(isdigit(postfix[i]))
            push(postfix[i]);
        else
        {
            opnd2=pop();
            opnd1=pop();
            switch(postfix[i])
            {
            case'+':
                value=opnd1+opnd2;
                break;

            case'-':
                value=opnd1-opnd2;
                break;

            case'/':
                value=opnd1/opnd2;
                break;

            case'*':
                value=opnd1*opnd2;
                break;

            case'%':
                value=(int)opnd1%(int)opnd2;
                break;
            }
             push(value);
        }
        i++;
    }
    return pop();

}

void main()
{
    char postfix[50];
    int i=0;
    printf("Enter expression in postfix notation\n");
    gets(postfix);
    printf("Answer =%f\n", eval_postfix(postfix));
}
