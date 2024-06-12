#include<stdio.h>
#define MAX 50

int top=-1;
char opstack[MAX];

int push(char symbol)
{
    if(top>=MAX-1)
    {
        printf("stack is full");
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
        printf("stack is empty");
        return ' ';
    }
    top--;
    return opstack[top+1];
}

char top_element()
{
    if(top==-1)
    {
        printf("stack is empty");
        return ' ';
    }
    else
        return opstack[top];
}

int priority(char c)
{
    switch(c)
    {
    case '-':
    case '+':
        return 1;
    case '*':
    case '/':
        return 2;

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
        symbol = infix[i];
        if(symbol>='A'&&symbol<='Z'||symbol>='a'&&symbol<='z' || symbol>='1' && symbol<='9')
            postfix[j++]=infix[i];
        else if(symbol=='(')
            push(symbol);
        else
        {
            while(top!=-1 && priority(top_element()) >= priority(symbol))
            {
                topsymbol = pop();
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
    while (top!=-1)   /*make stack empty by making as many pop outs*/
    {
        topsymbol=pop();
        postfix[j++]=topsymbol; /*send popped operator to postfix sting*/
    }
    puts(postfix);
}

void main()
{
    int i=0;
    char infix[MAX];
    printf("enter the expression");
    gets(infix);
    infix_postfix(infix);
}
