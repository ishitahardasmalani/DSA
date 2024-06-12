#include<stdio.h>
#include<conio.h>
#define MAX 30
void main()
{
    //record is to store the keys.
    //n is the number of keys given by user

    int record[MAX],key,index,n;
    int c1=1, c2=1; //c1 and c2 constants for quadratic probing
    //isInsert is a flag. Whenever a key is inserted we stop probing and come out of loop by changing the flag.
    int i,isInsert=0,j;
    int collision=0;

    printf("Enter the number of records you want to enter\n");
    scanf("%d",&n);

    for(j=0; j<MAX; j++)
        record[j]=0;

    printf("Enter those %d keys",n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&key);

        isInsert=0;//initialize it for each key inserted.
        index=key % n;
        j=0;
        while(isInsert!=1)//while the data is not inserted, keep probing
        {

            if(record[index]==0)//if we have found an index whose record=0 i.e it has no record then we insert our key there.
            {
                record[index]=key;
                isInsert=1;//once key is inserted we can exit from loop by changing the flag.
            }
            else //apply probing to get the next hash value
            {
                collision++;
                j++;
                index = (key%n + c1*j + c2*j*j)%n;
            }
        }
    }

    printf("Array is\n");
    for(j=0; j<n; j++) //printing all the records
    {
        printf("Index=%d key=%d\n",j,record[j]);
    }
    printf("\nTotal no of collision = %d", collision);

}
