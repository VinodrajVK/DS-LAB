#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//Function to check Stack Precedence
int stackprec(char symbol)
{
    switch(symbol)
    {
        case '+' : 
        case '-' : return 2;
        case '*' :
        case '/' :
        case '%' : return 4;
        case '^' :
        case '$' : return 5;
        case '(' : return 0;
        case '#' : return -1;
        default : return 8;
    }
}
//Function to check Input Precedence
int inprec(char symbol)
{
    switch(symbol)
    {
        case '+' : 
        case '-' : return 1;
        case '*' :
        case '/' :
        case '%' : return 3;
        case '^' :
        case '$' : return 6;
        case '(' : return 9;
        case ')' : return 0;
        default : return 7;
    }
}
//Function to convert Infix to Postfix Expression
void infixtopostfix(char infix[], char postfix[])
{
    char S[30]; //Stack to store the Expression
    int i=0; //Index for Infix Expression
    int j=0; //Index for Postfix Expression
    int top=-1; //Initializing Empty Stack
    S[++top] = '#';
    char symbol;
    for(i=0;i<strlen(infix);i++)
    {
        symbol = infix[i];
        while(stackprec(S[top])>inprec(symbol))
        {
            postfix[j++]=S[top--];
        }
        if(stackprec(S[top])!=inprec(symbol))
        {
            S[++top] = symbol;
        }
        else
        {
            top--;
        }
    }
    while(S[top]!='#')
    {
        postfix[j]=S[top--];
        j++;
    }
    postfix[j]='\0';
}
void main()
{
    char infix[30]; //Array to store Infix Expression
    char postfix[30]; //Array to store Postfix Expression
    int choice;
    printf("Menu\n1.Enter Infix Expression\n2.Convert to Postfix\n3.Evaluate Postfix\n4.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : printf("Enter the Infix Expression : ");
                 scanf("%s",infix);
                 break;
        case 2 : infixtopostfix(infix,postfix);
                 printf("The Postfix Expression is : ");
                 printf("%s\n",postfix);
                 break;
        case 3 : printf("!! THANK YOU !!\n");
                 exit(0);
        default: printf("Invalid Choice\n");
        }
    }
}