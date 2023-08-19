#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *link;
}*last = NULL;
int N=0;
typedef struct node *NODE;
NODE getnode(int X)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->item=X;
    temp->link=temp;
    return temp;
}
void display()
{
    NODE cur;
    printf("List : ");
    if(last==NULL)
        printf("Empty\n");
    else
    {
        cur=last->link;
        do
        {
            printf("%d ",cur->item);
            cur = cur->link;
        } while (cur!=last->link);
        printf("\n");
    }
}
void insertpos()
{
    int X,pos,i=1;
    printf("Enter the element : ");
    scanf("%d",&X);
    printf("Enter the Position : ");
    scanf("%d",&pos);
    NODE temp = getnode(X);
    
    if(last==NULL&&pos==1)
    {
        last=temp;
        N++;
        return;
    }
    if(pos>N+1)
    {
        printf("Invalid Position\n");
        return;
    }
    if(pos==1)
    {
        temp->link=last->link;
        last->link=temp;
        N++;
    }
    else if(pos==N+1)
    {
        temp->link=last->link;
        last->link=temp;
        last=temp;
        N++;
    }
    else
    {
        NODE cur=last->link,prev=NULL;
        while(i<pos)
        {
            prev=cur;
            cur=cur->link;
            i++;
        }
        prev->link=temp;
        temp->link=cur;
    }
}
void deletefront()
{
    if(last==NULL)
    {
        printf("List Empty\n");
        return;
    }
    if(last->link==last)
    {
        last=NULL;
        N--;
        display();
        return;
    }
    NODE first=last->link;
    last->link=first->link;
    free(first);
    N--;
    display();
}
void deleterear()
{
    if(last==NULL)
    {
        printf("List Empty\n");
        return;
    }
    if(last->link==last)
    {
        last=NULL;
        N--;
        display();
        return;
    }
    NODE cur=last->link;
    while(cur->link!=last)
        cur=cur->link;
    cur->link=last->link;
    free(last);
    last=cur;
    N--;
    display();
}
void search()
{
    int X,i=1;
    printf("Enter the Key Element : ");
    scanf("%d",&X);
    if(last==NULL)
    {
        printf("List Empty\n");
        return;
    }
    NODE cur = last->link;
    while (cur->link!=last->link)
    {
        if(cur->item==X)
        break;
        cur=cur->link;
        i++;
    }
    if(cur->item!=X&&i>=N)
        printf("Element not found\n");
    else
        printf("Element %d found at %d\n",X,i);
}
void main()
{
    int choice;
    printf("Menu\n1.Insert By Pos\n2.DeleteFront\n3.DeleteRear\n4.SearchByKey\n5.Display\n6.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : insertpos();
                 display();
                 break;
        case 2 : deletefront();
                 break;
        case 3 : deleterear();
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