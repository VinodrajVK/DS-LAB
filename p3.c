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
void insertorder()
{
    int X;
    printf("Enter the element : ");
    scanf("%d",&X);
    NODE temp = getnode(X);
    if(last==NULL)
    {
        last=temp;
        N++;
        display();
        return;
    }
    NODE cur = last->link,prev = NULL;
    if(X<cur->item)
    {
        last->link=temp;
        temp->link=cur;
        N++;
        display();
        return;
    }
    while(prev!=last&&cur->item<X)
    {
        prev = cur;
        cur = cur->link;
    }
    if(prev==last)
    {
        temp->link=prev->link;
        prev->link=temp;
        last=temp;
        N++;
        display();
    }
    else
    {
        temp->link = cur;
        prev->link = temp;
        N++;
        display();
    }
}
void deletepos()
{
    if(last==NULL)
    {
        printf("List Empty\n");
        return;
    }
    int pos,i=1;
    printf("Enter the Position : ");
    scanf("%d",&pos);
    NODE cur=last->link,prev=NULL;
    if(pos>N)
        printf("Invalid Postion\n");
    else if(pos==1)
    {
        last->link=cur->link;
        free(cur);
        N--;
        display();
        return;
    }
    else if(pos==N)
    {
        while(cur->link!=last)
            cur=cur->link;
        cur->link=last->link;
        free(last);
        last=cur;
        N--;
        display();
    }
    else
    {
        while(i<pos)
        {
            prev=cur;
            cur=cur->link;
            i++;
        }
        prev->link=cur->link;
        free(cur);
        N--;
        display();
    }
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
    printf("Menu\n1.Insert By Order\n2.Delete By Position\n3.Search by Key\n4.Display\n5.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : insertorder();
                 break;
        case 2 : deletepos();
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