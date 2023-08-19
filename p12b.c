#include <stdio.h>
#include <stdlib.h>
int size;
struct Queue
{
    int *queue; //Array to store Queue
    int front; //Index Of front element in Queue
    int rear; //Index of rear element in Queue
}Q;
//Function to insert an element to rear of Queue
void pushrear(int val)
{
    //Checking if Queue is Full
    if(Q.rear==size-1)
    {
        if(Q.front==0||Q.front>Q.rear)
        {
            printf("Queue is Full\n");
            printf("Reallocating Memory\n");
            size++;
            Q.queue = (int *)realloc(Q.queue,size*sizeof(int));
        }
        else
        {
            printf("Insertion not Possible\n");
            return;
        }
    }
    if(Q.front==-1)
       Q.front=Q.rear=0;
    else
        Q.rear++;   
    *(Q.queue+Q.rear) = val;
    printf("Insertion Succesfull\n");
}
//Function to insert an element to front of Queue
void pushfront(int val)
{
    if(Q.front==0)
    {
        if(Q.rear==size-1||Q.front>Q.rear)
        {
            printf("Queue is Full\n");
            printf("Reallocating Memory\n");
            size++;
            Q.queue = (int *)realloc(Q.queue,size*sizeof(int));
        }
        else
        {
            printf("Insertion not Possible\n");
            return;
        }
    }    
    if(Q.front==-1)
        Q.front=Q.rear=0;
    else 
        Q.front--;
    *(Q.queue+Q.front)=val;
    printf("Insertion Succesfull\n");
}
//Function to delete the front element of Queue
void popfront()
{
    if(Q.front==-1)
        printf("Queue is Empty\n");
    else
    {
        printf("Deleted Element : %d\n",*(Q.queue+Q.front));
        if(Q.front==Q.rear)
            Q.front=Q.rear=-1;
        else
            Q.front++;
    }   
}
//Function to delete the rear element of Queue
void poprear()
{
    if(Q.front==-1)
        printf("Queue is Empty\n");
    else
    {
        //Deleting Element from rear
        printf("Deleted Element : %d\n",*(Q.queue+Q.rear));
        if(Q.front==Q.rear)
            Q.front=Q.rear=-1;
        else
            Q.rear--;
    }
}
//Function Display all elements of Queue
void display()
{
    int i;
    //Checking if Queue is Empty
    if(Q.front==-1)
        printf("Queue is Empty\n");
    else
    {
        if(Q.front<=Q.rear)
        for(i=Q.front;i<=Q.rear;i++)
            printf("%d ",*(Q.queue+i));
        else
        {
            for(i=Q.front;i<=size-1;i++)
                printf("%d ",*(Q.queue+i));
            for(i=0;i<=Q.rear;i++)
                printf("%d ",*(Q.queue+i));
        }
        printf("\n");
    }
}
void main()
{
    Q.front=Q.rear=-1; //Initializing Empty Queue
    int val,choice;
    printf("Enter the Size : ");
    scanf("%d",&size);
    Q.queue=(int *)malloc(size*sizeof(int)); //Dynamically Allocating Array for Queue
    printf("Main Menu\n1.Push-Front\n2.Pop-Front\n3.Push-Rear\n4.Pop-Rear\n5.Display\n6.Exit\n");
    for(;;)
    {
        printf("Enter Your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter the element to be inserted : ");
                     scanf("%d",&val);
                     pushfront(val);
                     break;
            case 2 : popfront();
                     break;
            case 3 : printf("Enter the element to be inserted : ");
                     scanf("%d",&val);
                     pushrear(val);
                     break;
            case 4 : poprear();
                     break;
            case 5 : printf("Queue : ");
                     display();
                     break;
            case 6 : printf("!! THANK YOU !!\n");
                     exit(0);
            default : printf("Invalid Choice\nEnter Again\n");
        }
    }
}