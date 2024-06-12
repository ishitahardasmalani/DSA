#include <stdio.h>
# define max 6
int queue[max]; // array declaration
int front=-1;
int rear=-1;
// function to insert an element in a circular queue
void enqueue(int element)
{
 if(front==-1 && rear==-1) // condition to check queue is empty
 {
 front=0;
 rear=0;
 queue[rear]=element;
 }
 else if((rear+1)%max==front) // condition to check queue is full
 {
 printf("Queue is overflow..");
 }
 else
 {
 rear=(rear+1)%max; // rear is incremented
 queue[rear]=element; // assigning a value to the queue at the rear position.
 }
}
// function to delete the element from the queue
int dequeue()
{
 if((front==-1) && (rear==-1)) // condition to check queue is empty
 {
 printf("\nQueue is underflow..");
 }
else if(front==rear)
{
 printf("\nThe dequeued element is %d", queue[front]);
 front=-1;
 rear=-1;
}
else
{
 printf("\nThe dequeued element is %d", queue[front]);
 front=(front+1)%max;
}
}
//function to display the first element
int getfront()
{
 if(front == -1 && rear == -1)
 {
 printf("Queue Underflow!");
 }
 else
 {
 printf("Front element : %d",queue[front]);
 }
}
//function to display the last element
int getrear()
{
 if(front == -1 && rear == -1)
 {
 printf("Queue Underflow!");
 }
 else
 {
 printf("Rear element : %d",queue[rear]);
 }
}
//function to get the size of the queue
void size()
{
 if(front == -1 && rear == -1)
{
int size=0;
}
else
{
int size= front>rear ? (max - front + rear + 1) : (rear - front + 1);
}
}
// function to display the elements of a queue
void display()
{
 int i=front;
 if(front==-1 && rear==-1)
 {
 printf("\n Queue is empty..");
 }
 else
 {
 printf("\nElements in a Queue are :");
 while(i<=rear)
 {
 printf("%d,", queue[i]);
 i=(i+1)%max;
 }
 }
}
int main()
{
 int choice=1,x; // variables declaration
 while(choice<4 && choice!=0) // while loop
 {
 printf("\n1:ENQUEUE");
 printf("\n2:DEQUEUE");
 printf("\n3:GET FRONT");
 printf("\n4:GET REAR");
 printf("\n5.SIZE");
 printf("\n6.DISPLAY");
 printf("\n7.EXIT");
 printf("\nEnter your choice");
 scanf("%d", &choice);
 switch(choice)
 {
 case 1:
 printf("Enter the element which is to be inserted");
 scanf("%d", &x);
 enqueue(x);
 break;
 case 2:
 dequeue();
 break;
 case 3:
 getfront();
 break;
 case 4:
 getrear();
 break;
 case 5:
 size();
 break;
 case 6:
 display();
 }}
 return 0;
}
