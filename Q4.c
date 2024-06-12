#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void insert();
void del();
int getf();
int getr();
int size();
void display();
int front,rear=-1;
int queue[MAX];
int count;
void main ()
{
 int choice;
 while(choice != 8)
 {
 printf("\n*************************MainMenu*****************************\n");

printf("\n=================================================================\n");
 printf("\n1.ENQUEUE");
 printf("\n2.DEQUEUE");
 printf("\n3.GET FRONT");
 printf("\n4.GET REAR");
 printf("\n5.SIZE");
 printf("\n6.DISPLAY");
 printf("\n7.EXIT");
 printf("\nEnter your choice ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 insert();
 break;
 case 2:
 del();
 break;
 case 3:
 printf("Front element :%d ",queue[front]);
 getf();
 break;
 case 4:
 printf("Rear element: %d",queue[rear]);
 getr();
 break;
 case 5:
 printf("Size is %d",count);
 size();
 break;
 case 6:
 display();
 break;
 case 7:
 exit(0);
 break;
 default:
 printf("\nEnter valid choice??\n");
 }
 }
}
void insert()
{
 int item;
 printf("\nEnter the element\n");
 scanf("\n%d",&item);
 if(rear == MAX-1)
 {
 printf("\nOVERFLOW\n");
 }
 if(front == -1 && rear == -1)
 {
 front = 0;
 rear = 0;
 }
 else
 {
 rear = rear+1;
 }
 queue[rear] = item;
 printf("\nValue inserted ");

}
void del()
{
 int item;
 if (front == -1 || front > rear)
 {
 printf("\nUNDERFLOW\n");
 return;
 }
 else
 {
 item = queue[front];
 if(front == rear)
 {
 front = -1;
 rear = -1 ;
 }
 else
 {
 front = front + 1;
 }
 printf("\nvalue deleted ");
 }
}
int getf()
{
 if((front==-1) && (rear==-1))
 {
 return 0;
 }
 else
 {
 return queue[front];
 }
}
int getr()
{
 if(rear==MAX-1)
 {
 return 0;
 }
 else
 {
 return queue[rear];
 }
}
int size()
{
 if((front==-1) && (rear==-1))
 {
 return 0;
 }
 else{
 int count=0;
 for(int i=queue[front];i=((i+1)%MAX);i++)
 {
 count++;
 if(i==queue[rear])
 break;
 }
 return count;
}
}
void display()
{
 int i;
 if(rear == -1)
 {
 printf("\nEmpty queue\n");
 }
 else
 { printf("\nprinting values .....\n");
 for(i=front;i<=rear;i++)
 {
 printf("\n%d\n",queue[i]);
 }
 }
}
//4. Implement Queue ADT using arrays
