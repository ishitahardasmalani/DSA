//2. Convert an infix expression to postfix expression using Stack ADT

#include<stdio.h>
#include<string.h>
#define MAX 100

int top=-1;
char opstack[MAX];

int push(char symbol)
{
    if(top>=MAX-1)
    {
        printf("Stack is full\n");
        return 0;
    }
    top++;
    opstack[top]=symbol;
    return 1;
}

char pop()
{
   if(top==-1)
    {
        printf("Stack is empty\n");
        return 0;
    }
   top--;
   return opstack[top+1];
}

char top_element()
{
    if(top==-1)
    {
        printf("Stack is empty\n");
        return ' ';
    }
    else
        return opstack[top];
}

int priority(char c)
{
    switch(c)
    {
     case'-':
     case'+':return 1;
     case'*':
     case'/':return 2;
     case'^':return 3;
    }
    return 0;
}

void infix_postfix(char infix[])
{
    char opstack[MAX],postfix[MAX],symbol,topsymbol;
    int i=0,j=0;
    int n=strlen(infix);
    while(i<n)
    {
        symbol=infix[i];
        if(symbol>='A'&& symbol<='Z' || symbol>='a' && symbol<= 'z')
        {
            postfix[j++]=infix[i];
        }
        else if(symbol=='(')
                    push(symbol);
        else
        {
            while(top!=-1 && priority(top_element())>=priority(symbol))
            {
                topsymbol=pop();
                if(topsymbol!='(')
                    postfix[j++]=topsymbol;
                else
                    break;
            }
            if(symbol!=')')
                push(symbol);
        }
        i++;
    }
    while(top!=-1)
    {
        topsymbol=pop();
        postfix[j++]=topsymbol;
    }
    postfix[j]='\0';

    puts(postfix);
}

void main()
{
    int i=0;
    char infix[MAX];
    printf("Enter the expression:");
    gets(infix);
    infix_postfix(infix);
}
