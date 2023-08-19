#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *rlink;
    struct node *llink;
}*first = NULL;
int N=0;
typedef struct node *NODE;
NODE getnode(int X)
{
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->item=X;
    temp->rlink=temp->llink=temp;
    return temp;
}
void display()
{
    NODE cur;
    printf("List : ");
    if(first==NULL)
        printf("Empty\n");
    else
    {
        cur=first;
        do
        {
            printf("%d ",cur->item);
            cur = cur->rlink;
        } while (cur!=first);
        printf("\n");
    }
}
void insertorder()
{
    int X;
    printf("Enter the element : ");
    scanf("%d",&X);
    NODE temp = getnode(X);
    if(first==NULL)
    {
        first=temp;
        return;
    }
    if(X<first->item)
    {
        temp->llink=first->llink;
        first->llink->rlink=temp;
        temp->rlink=first;
        first->llink=temp;
        first=temp;
        return;
    }
    NODE cur = first,prev = NULL;
    while(prev!=first->llink&&cur->item<X)
    {
        prev = cur;
        cur = cur->rlink;
    }
    if(prev==first->llink)
    {
        temp->rlink=first;
        first->llink=temp;
        prev->rlink=temp;
        temp->llink=prev;
    }
    else
    {
        temp->rlink = cur;
        cur->llink=temp;
        prev->rlink = temp;
        temp->llink=prev;
    }
}
void deletefront()
{
    NODE last;
    if(first==NULL)
        printf("List Empty\n");
    else if(first->rlink==first)
    {
        first=NULL;
        N--;
        display();
    }
    else
    {
        last = first->llink;
        first=first->rlink;
        last->rlink=first;
        first->llink=last;
        N--;
        display();
    }
}
void deleterear()
{
    NODE last;
    if(first==NULL)
        printf("List Empty\n");
    else if(first->rlink==first)
    {
        first=NULL;
        N--;
        display();
    }
    else
    {
        last = first->llink;
        last=last->llink;
        last->rlink=first;
        first->llink=last;
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
        cur = first;next=cur->rlink;
        while(next!=first&&i<X)
        {
            cur=next;
            next=next->rlink;
            i++;
        }
        printf("%d found at %d position\n",cur->item,X); 
    }
}
void main()
{
    int choice;
    printf("Menu\n1.Insert By Order\n2.Delete Front\n3.Delete Rear\n4.Search By Position\n5.Display\n6.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : insertorder();
                 N++;
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