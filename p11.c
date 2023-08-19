#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void reverse(char a[])
{
    char t;
    int N = strlen(a);
    for(int i=0;i<N/2;i++)
    {
        t = a[i];
        a[i] = a[N-i-1];
        a[N-i-1] = t;
    }
}
void prefixevaluate(char prefix[])
{
    int i,op1,op2,res;
    reverse(prefix);
    int Stack[10]; //Stack to store Operands
    int top=-1; //Initializing Empty Stack
    char ch;
    for(i=0;i<strlen(prefix);i++)
    {
        ch = prefix[i];
        if(isdigit(ch))
        {
            Stack[++top]=ch-'0'; //Pushing Operand into Stack
        }
        else
        {
            if(top<1)
                printf("Not enough operands\n");
            else
            {
                op1=Stack[top--]; //Popping Operand-1
                op2=Stack[top--]; //Popping Operand-2
                switch (ch)
                {
                case '+' : res = op1 + op2;
                           break;
                case '-' : res = op1 - op2;
                           break;
                case '/' : res = op1 / op2;
                           break;
                case '*' : res = op1 * op2;
                           break;
                case '%' : res = op1 % op2;
                           break;
                default: printf("Invalid Operator\n");
                }
                Stack[++top] = res; //Pushing Result into Stack
            }
        }
    }
    printf("Final Result = %d\n",Stack[top]);
}
void postfixevaluate(char postfix[])
{
    int i,op1,op2,res;
    int Stack[10]; //Stack to store Operands
    int top=-1; //Initializing Empty Stack
    char ch;
    for(i=0;i<strlen(postfix);i++)
    {
        ch = postfix[i];
        if(isdigit(ch))
        {
            Stack[++top]=ch-'0'; //Pushing Operand into Stack
        }
        else
        {
            if(top<1)
                printf("Not enough operands\n");
            else
            {
                op2=Stack[top--]; //Popping Operand-2
                op1=Stack[top--]; //Popping Operand-1
                switch (ch)
                {
                case '+' : res = op1 + op2;
                           break;
                case '-' : res = op1 - op2;
                           break;
                case '/' : res = op1 / op2;
                           break;
                case '*' : res = op1 * op2;
                           break;
                case '%' : res = op1 % op2;
                           break;
                default: printf("Invalid Operator\n");
                }
                Stack[++top] = res; //Pushing Result into Stack
            }
        }
    }
    printf("Final Result = %d\n",Stack[top]);
}
void main()
{
    char postfix[30]; 
    char prefix[30];
    int choice;
    printf("Menu\n1.Enter Prefix Expression\n2.Evaluate Prefix\n3.Enter Prefix Expression\n4.Evaluate Postfix\n5.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : printf("Enter the Prefix Expression : ");
                 scanf("%s",prefix);
                 break;
        case 2 : prefixevaluate(prefix);
                 break;
        case 3 : printf("Enter the Postfix Expression : ");
                 scanf("%s",postfix);
                 break;
        case 4 : postfixevaluate(postfix);
                 break;
        case 5 : printf("!! THANK YOU !!\n");
                 exit(0);
        default: printf("Invalid Choice\n");
        }
    }
}