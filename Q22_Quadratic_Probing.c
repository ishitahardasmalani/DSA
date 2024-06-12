#include<stdio.h>
#include<stdlib.h>
#define max 10 
int hashing(int val) 
{
return val%max; 
} 
void quadprob(int a[],int val) 
{  
    for(int i=0;i<max;i++)   
    {        
        int code=hashing(hashing(val)+i*i);    
        if(a[code]==-1)   
        { 
            a[code]=val;
            break;   
        }  
    } 
} 
void display(int a[]) 
{    
    printf("------------------------------------------------------\n");    
    for(int i=0;i<max;i++)    
    {       
        printf("| %d ",a[i]);        
    }   
    printf("|\n-------------------------------------------------------\n"); 
} 
void create(int a[])
{    
    for(int i=0;i<max;i++)    
    {        
        a[i]=-1;    
        
    } 
} 
int main() 
{  
   int val,n,a[max];   
   printf("This program is implementation of hashing table using array.\n");
   printf("Quadratic Probing is used to handle collision.\n\n");
   printf("Enter number of element: ");     
   scanf("%d",&n);     
       create(a);     
       for(int i=0;i<n;i++)    
       {        
           printf("Enter Inserting Element: ");       
       scanf("%d",&val);        
          quadprob(a,val);           
           display(a);
        }   
    printf("THANK YOU");
   return 0;
}
