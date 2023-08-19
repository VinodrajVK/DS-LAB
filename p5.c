#include <stdio.h>
#include <stdlib.h>
int N=0;
struct node
{
    int item;
    struct node *link;
}*last=NULL;
typedef struct node *NODE;
NODE getnode(int X)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->item = X;
    temp->link = temp;
    return temp;
}
void display()
{
    printf("List : ");
    if(last==NULL)
    {
        printf("Empty\n");
        return;
    }
    NODE cur=last->link;
    do
    {
        printf("%d ",cur->item);
        cur = cur->link;
    } while (cur!=last->link);
    printf("\n");
    return;
}
void insertfront()
{
    int X;
    printf("Enter the Element : ");
    scanf("%d",&X);
    NODE temp = getnode(X);
    if(last==NULL)
    {
        last=temp;
        N++;
    }
    else
    {
        temp->link=last->link;
        last->link=temp;
        N++;
    }
}
void insertrear()
{
    int X;
    printf("Enter the Element : ");
    scanf("%d",&X);
    NODE temp = getnode(X);
    if(last==NULL)
    {
        last=temp;
        N++;
    }
    else
    {
        temp->link=last->link;
        last->link=temp;
        last=temp;
        N++;
    }
}
void deletebykey()
{
    int X;
    printf("Enter the Key Element : ");
    scanf("%d",&X);
    if(last==NULL)
    {
        printf("List Empty\n");
        return;
    }
    if(last->item==X&&last->link==last)
    {
        last=NULL;
        N--; 
        display(); 
        return;
    }
    if(last->item!=X&&last->link==last)
    {
        printf("Element not Found\n");
        display();
        return;
    }
    NODE cur = last->link,prev=NULL;
    if(cur->item==X)
    {
        last->link=cur->link;
        free(cur);
        N--;
        display();
        return;
    }
    
    while (prev!=last&&cur->item!=X)
    {
        prev=cur;
        cur=cur->link;
    }
    if(cur==last->link)
    {
        printf("Element not Found\n");
        display();
    }
    else if(cur==last)
    {
        prev->link=last->link;
        last=prev;
        N--;
        display();
    }
    else
    {
        prev->link=cur->link;
        free(cur);
        N--;
        display();
    }
}
void search()
{
    NODE cur,next;
    int X,i=1;
    printf("Enter the Position : ");
    scanf("%d",&X);
    if(X>N)
        printf("Invalid Position\n");
    else
    {
        cur = last->link;next=cur->link;
        while(next!=last->link&&i<X)
        {
            cur=next;
            next=next->link;
            i++;
        }
            printf("%d found at %d position\n",cur->item,X); 
    }
}
void main()
{
    int choice;
    printf("Menu\n1.InsertFront\n2.InsertRear\n3.DeleteByKey\n4.SearchByPosition\n5.Display\n6.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : insertfront();
                 display();
                 break;
        case 2 : insertrear();
                 display();
                 break;
        case 3 : deletebykey();
                 break;
        case 4 : search();
                 break;
        case 5 : display();
                 break;
        case 6 : printf("THANK YOU\n");
                 exit(0);
        default: printf("Invalid Choice\n");
            break;
        }
    }
}