#include <stdlib.h>
#include <stdio.h>
struct Student
{
    char name[30];
    int reg_no;
    int m1,m2,m3;
    float average;
}*S;
int N;
void read()
{
    for(int i=0;i<N;i++)
    {
        printf("Student-%d\n",(i+1));
        printf("Enter Name :");
        scanf("%s",(S+i)->name);
        printf("Enter Roll No : ");
        scanf("%d",&(S+i)->reg_no);   
        printf("Enter Marks in 3 Tests\n");
        printf("Test-1 : ");
        scanf("%d",&(S+i)->m1);   
        printf("Test-2 : ");
        scanf("%d",&(S+i)->m2); 
        printf("Test-2 : ");
        scanf("%d",&(S+i)->m3);  
    }
}
void display()
{
    printf("Sl.No\tReg_no\tName\tTest-1\tTest-2\tTest-3\n");
    for(int i=0;i<N;i++)
    {
        printf("%d\t%d\t%s\t%d\t%d\t%d\n",(i+1),(S+i)->reg_no,(S+i)->name,(S+i)->m1,(S+i)->m2,(S+i)->m3);
    }
}
void average()
{
    int least=0;
    for(int i=0;i<N;i++)
    {
        least = ((S+i)->m1<(S+i)->m2)?((S+i)->m1<(S+i)->m3?(S+i)->m1:(S+i)->m3):((S+i)->m2<(S+i)->m3?(S+i)->m2:(S+i)->m3);
        if(least==(S+i)->m1)
        (S+i)->average = (float)((S+i)->m2+(S+i)->m3)/2;
        else if(least == (S+i)->m2)
        (S+i)->average = (float)((S+i)->m1+(S+i)->m3)/2;
        else
        (S+i)->average = (float)((S+i)->m1+(S+i)->m2)/2;
    }
    printf("Sl.No\tReg_no\tName\tTest-1\tTest-2\tTest-3\tAverage\n");
    for(int i=0;i<N;i++)
    {
        printf("%d\t%d\t%s\t%d\t%d\t%d\t%.1f\n",(i+1),(S+i)->reg_no,(S+i)->name,(S+i)->m1,(S+i)->m2,(S+i)->m3,(S+i)->average);
    }
}
void main()
{
    int choice;
    printf("Enter the number of Students : ");
    scanf("%d",&N);
    S = (struct Student *)malloc(N*sizeof(struct Student));
    printf("Menu\n1.Read\n2.Display\n3.Average\n4.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1 : read();
                 break;
        case 2 : display();
                 break;
        case 3 : average();
                 break;
        case 4 : printf("THANK YOU\n");
                 free(S);S=NULL;
                 exit(0);
        default: printf("Invalid Choice\n");
        }
    }
}
