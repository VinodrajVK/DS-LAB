#include <stdio.h>
#include <stdlib.h>
struct node
{
    int item;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE getnode(int X)
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node)); //Dynamically Allocating a new Node
    temp->item = X;
    temp->llink=temp->rlink=NULL;
    return temp;
}
NODE insert(NODE root, int X)
{
    NODE temp = getnode(X);
    if(root==NULL)
    return temp;
    if(X<root->item)
    root->llink = insert(root->llink,X);
    else
    root->rlink = insert(root->rlink,X);
    return root;
}
NODE create(NODE root)
{
    int X;
    printf("Enter the Elements of Tree and 0 to Stop\n");
    while(1)
    {
        printf("Enter a Element : ");
        scanf("%d",&X);
        if(X==0)
            break;
        root = insert(root,X);
    }
    return root;
}
void search(NODE root,int X)
{
    NODE cur = root,prev=NULL;
    while(cur!=NULL)
    {
        if(cur->item==X)
            break;
        prev=cur;
        if(X<cur->item)
            cur=cur->llink;
        else 
            cur=cur->rlink;
    }
    if(cur==NULL)
        printf("Element not Found\n");
    else
    {
        if(prev==NULL)
            printf("Key %d is root Element\n",cur->item);
        else
            printf("Key %d found with Parent %d\n",cur->item,prev->item);
    }
}
void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->llink);
        printf("%d\n",root->item);
        inorder(root->rlink);
    }
}
void preorder(NODE root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->item);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
void postorder(NODE root)
{
    if(root!=NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\n",root->item);
    }
}
int count(NODE root)
{
    if(root==NULL)
    return 0;
    int cnt = 0;
    cnt++;
    cnt = cnt + count(root->llink) + count(root->rlink);
    return cnt;
}
int leafcount(NODE root)
{
    if(root==NULL)
    return 0;
    if(root->llink==NULL&&root->rlink==NULL)
    return 1;
    else
    return leafcount(root->llink)+leafcount(root->rlink);
}
int max(int a,int b)
{
    int larg = (a>b)?(a):(b);
    return larg;
}
int height(NODE root)
{
    if(root==NULL)
    return 0;
    return max(height(root->llink),height(root->rlink))+1;
}
void main()
{
    int choice,X;
    NODE root=NULL;
    printf("Menu\n1.Create A BST\n2.Insert A Node\n3.Search a Key\n4.InOrder\n5.PreOrder\n6.PostOrder\n7.Number Of Nodes\n8.Height of Tree\n9.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : root = create(root);
                     break;
            case 2 : printf("Enter an Element : ");
                     scanf("%d",&X);
                     root = insert(root,X);
                     break;
            case 3 : printf("Enter an Element : ");
                     scanf("%d",&X);
                     search(root,X);
                     break;
            case 4 : inorder(root);
                     break;
            case 5 : preorder(root);
                     break;
            case 6 : postorder(root);
                     break;
            case 7 : printf("The Total Number of Nodes is %d\n",count(root));
                     printf("The Total Number of Leaf Nodes is %d\n",leafcount(root));
                     printf("The Total Number of Degree-2 Nodes is %d\n",leafcount(root)-1);
                     printf("The Total Number of Degree-1 Nodes is %d\n",count(root)-2*leafcount(root)+1);
                     break;
            case 8 : printf("The Height of the Tree is %d\n",height(root));
                     break;
            case 9 : printf("!!THANK YOU!!\n");
                     exit(0);
            default : printf("Invalid Choice\n");
        }
    }
}