#include <stdio.h>
#include <stdlib.h>
int N=0;
struct node
{
    int item;
    struct node *rlink;
    struct node *llink;
}*first=NULL;
typedef struct node *NODE;
NODE getnode(int X)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->item = X;
    temp->rlink = temp->llink=temp;
    return temp;
}
void display()
{
    printf("List : ");
    if(first==NULL)
    {
        printf("Empty\n");
        return;
    }
    NODE cur=first;
    do
    {
        printf("%d ",cur->item);
        cur = cur->rlink;
    } while (cur!=first);
    printf("\n");
    return;
}
void insertfront()
{
    int X;
    printf("Enter the Element : ");
    scanf("%d",&X);
    NODE temp = getnode(X);
    if(first==NULL)
        first=temp;
    else
    {
        NODE last=first->llink;
        temp->rlink=first;
        last->rlink=temp;
        first->llink=temp;
        temp->llink=last;
        first=temp;
    }
}
void insertrear()
{
    int X;
    printf("Enter the Element : ");
    scanf("%d",&X);
    NODE temp = getnode(X);
    if(first==NULL)
        first=temp;
    else
    {
        NODE last = first->llink;
        last->rlink=temp;
        temp->rlink=first;
        first->llink=temp;
        temp->llink=last;
    }
}
void deletepos()
{
    if(first==NULL)
    {
        printf("List Empty\n");
        return;
    }
    int pos,i=1;
    printf("Enter the Position : ");
    scanf("%d",&pos);
    NODE cur=first,prev=NULL,last=first->llink;
    if(pos>N)
        printf("Invalid Postion\n");
    else if(pos==1)
    {
        last->rlink=first->rlink;
        first=first->rlink;
        first->llink=last;
        free(cur);
        N--;
        display();
    }
    else if(pos==N)
    {
        while(cur->rlink!=last)
            cur=cur->rlink;
        cur->rlink=last->rlink;
        first->llink=cur;
        free(last);
        N--;
        display();
    }
    else
    {
        while(i<pos)
        {
            prev=cur;
            cur=cur->rlink;
            i++;
        }
        prev->rlink=cur->rlink;
        cur->rlink->llink=prev;
        free(cur);
        N--;
        display();
    }
}
void search()
{
    int X,i=1;
    NODE last=first->llink;
    printf("Enter the Key Element : ");
    scanf("%d",&X);
    if(first==NULL)
    {
        printf("List Empty\n");
        return;
    }
    NODE cur = first,prev=NULL;
    while(prev!=last&&cur->item!=X)
    {
        prev=cur;
        cur=cur->rlink;
        i++;
    }
    if(cur==first&&i>=N)
        printf("Element not found\n");
    else
        printf("Element %d found at %d\n",X,i);
}
void main()
{
    int choice;
    printf("Menu\n1.InsertFront\n2.InsertRear\n3.DeleteByPos\n4.SearchByKey\n5.Display\n6.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : insertfront();
                 N++;
                 display();
                 break;
        case 2 : insertrear();
                 N++;
                 display();
                 break;
        case 3 : deletepos();
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
