#include <stdio.h>
#include <stdlib.h>
int *a,N;
void display()
{
    printf("Array : ");
    if(N==0)
    {
        printf("Empty\n");
        return;
    }
    for(int i=0;i<N;i++)
        printf("%d ",*(a+i));
    printf("\n");
}
void insertpos()
{
    int X,pos,i;
    printf("Enter the Element : ");
    scanf("%d",&X);
    printf("Enter the Position : ");
    scanf("%d",&pos);
    N++;
    pos--;
    a = (int *)realloc(a,N*sizeof(int));
    for(i=N-1;i>=pos;i--)
        *(a+i)=*(a+i-1);
    *(a+pos)=X;
    display();
}
void insertorder()
{
    int i=0,X,pos;
    printf("Enter the Element : ");
    scanf("%d",&X);
    while(*(a+i)<X&&i<N)
        i++;
    pos=i;
    N++;
    a = (int *)realloc(a,N*sizeof(int));
    for(i=N-1;i>=pos;i--)
        *(a+i)=*(a+i-1);
    *(a+pos)=X;
    display();
}
void insertbykey()
{
    int X,flag=0,i;
    printf("Enter the Element : ");
    scanf("%d",&X);
    for(i=0;i<N;i++)
    {
        if(*(a+i)==X)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        N++;
        a = (int *)realloc(a,N*sizeof(int));
        *(a+N-1)=X;
    }
    else
        printf("Element already Exists\n");
    display();
}
void deletebykey()
{
    if(N==0)
    {
        printf("Empty Array\n");
        return;
    }
    int X,flag=0,pos,i;
    printf("Enter the Key Element : ");
    scanf("%d",&X);
    for(i=0;i<N;i++)
    {
        if(*(a+i)==X)
        {
            flag=1;
            pos=i;
            break;
        }
    }
    if(flag==0)
        printf("Element not found\n");
    else
    {
        for(i=pos;i<N;i++)
            *(a+i)=*(a+i+1);
        N--;
        a = (int *)realloc(a,N*sizeof(int));
        display();
    }
}
void deletepos()
{
    if(N==0)
    {
        printf("Empty Array\n");
        return;
    }
    int pos,i;
    printf("Enter the Position : ");
    scanf("%d",&pos);
    for(i=pos-1;i<N;i++)
        *(a+i)=*(a+i+1);
    N--;
    a = (int *)realloc(a,N*sizeof(int));
    display();
}
void searchkey()
{
    if(N==0)
    {
        printf("Empty Array\n");
        return;
    }
     int X,flag=0,pos=-1,i;
    printf("Enter the Key Element : ");
    scanf("%d",&X);
    for(i=0;i<N;i++)
    {
        if(*(a+i)==X)
        {
            flag=1;
            pos=i;
            break;
        }
    }
    if(flag==0)
        printf("Element not found\n");
    else
        printf("%d found at %d position\n",X,pos+1);
}
void searchpos()
{
    if(N==0)
    {
        printf("Empty Array\n");
        return;
    }
    int pos;
    printf("Enter the Position : ");
    scanf("%d",&pos);
    printf("%d found at %d position\n",*(a+pos-1),pos);
}
void reverse()
{
    if(N==0)
    {
        printf("Empty Array\n");
        return;
    }
    int t,i;
    for(i=0;i<N/2;i++)
    {
        t=*(a+i);
        *(a+i)=*(a+N-i-1);
        *(a+N-i-1)=t;
    }
    printf("Reversed Array : ");
    display();
}
void main()
{
    int choice,i;
    printf("Enter the number of Elements : ");
    scanf("%d",&N);
    a = (int *)malloc(N*sizeof(int));
    printf("Enter the array elements : ");
    for(i=0;i<N;i++)
        scanf("%d",(a+i));
    printf("Menu\n1.Insert By Position\n2.Insert By Key\n3.Insert By Order\n4.Delete By Position\n5.Delete By Key\n6.Search By Key\n7.Search By Position\n8.Reverse\n9.Display\n0.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : insertpos();
                     break;
            case 2 : insertbykey();
                     break;
            case 3 : insertorder();
                     break;
            case 4 : deletepos();
                     break;
            case 5 : deletebykey();
                     break; 
            case 6 : searchkey();
                     break;   
            case 7 : searchpos();
                     break;
            case 8 : reverse();
                     break;
            case 9 : display();
                     break;
            case 0 : printf("THANK YOU\n"); 
                     exit(0);
            default : printf("Invalid Choice\n");
        }
    }
}