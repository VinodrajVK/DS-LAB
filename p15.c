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
NODE delete(NODE root, int X)
{
    NODE cur = root;
    NODE prev = NULL,q = NULL,suc = NULL;
    while(cur!=NULL)
    {
        if(cur->item==X)
        break;
        prev = cur;
        if(X<cur->item)
        cur = cur->llink;
        else 
        cur = cur->rlink;
    }
    if(cur==NULL)
    {
        printf("Item Not Found\n");
        return root;
    }
    if(cur->llink == NULL)
    q=cur->rlink;
    else if(cur->rlink == NULL)
    q=cur->llink;
    else
    {
        suc = cur->rlink;
        while(suc->llink!=NULL)
        {
            suc = suc->llink;
        }
        suc -> llink = cur->llink;
        q = cur->rlink;
    }
    if(prev == NULL)
    return q;
    if(cur==prev->llink)
    prev->llink = q;
    else
    prev->rlink = q;
    free(cur);
    return root;
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
void main()
{
    int choice,X;
    NODE root=NULL;
    printf("Menu\n1.Create A BST\n2.Insert A Node\n3.Delete A Node\n4.InOrder\n5.PreOrder\n6.PostOrder\n7.Exit\n");
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
                     root = delete(root,X);
                     break;
            case 4 : inorder(root);
                     break;
            case 5 : preorder(root);
                     break;
            case 6 : postorder(root);
                     break;
            case 7 : printf("!!THANK YOU!!\n");
                     exit(0);
            default : printf("Invalid Choice\n");
        }
    }
}