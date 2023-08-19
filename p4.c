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
    NODE cur = first,prev = NULL;
    if(X<cur->item)
    {
        temp->llink=first->llink;
        first->llink->rlink=temp;
        temp->rlink=first;
        first->llink=temp;
        first=temp;
        return;
    }
    while(prev!=first->llink)
    {
        if(cur->item>X)
            break;
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
void deletebykey()
{
    NODE last=first->llink;;
    int X;
    printf("Enter the Key Element : ");
    scanf("%d",&X);
    if(first==NULL)
    {
        printf("List Empty\n");
        return;
    }
    NODE cur = first,prev=NULL;
    if(cur->item==X&&first->rlink==first)
    {
        first=NULL;
        N--;  
        display();
        return;
    }
    if (cur->item!=X&&first->rlink==first)
    {
        printf("Element not Found\n");
        display();
        return;
    }
    if(first->item==X)
    {
        last->rlink=first->rlink;
        first=first->rlink;
        first->llink=last;
        free(cur);
        N--;
        display();
        return;
    }
    while (prev!=first->llink&&cur->item!=X)
    {
        prev=cur;
        cur=cur->rlink;
    }

    if(cur==first)
    {
        printf("Element not Found\n");
        display();
    }
    else if(cur==last)
    {
        prev->rlink=first;
        first->llink=prev;
        free(cur);
        N--;
        display();
    }
    else
    {
        prev->rlink=cur->rlink;
        cur->rlink->llink=prev;
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
    printf("Menu\n1.Insert By Order\n2.Delete By Key\n3.Search by Position\n4.Display\n5.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : insertorder();
                 display();
                 N++;
                 break;
        case 2 : deletebykey();
                 break;
        case 3 : search();
                 break;
        case 4 : display();
                 break;
        case 5 : printf("THANK YOU\n");
                 exit(0);
        default: printf("Invalid Choice\n");
            break;
        }
    }
}