#include <stdio.h>
#include <stdlib.h>
struct Time
{
    int hr,min,sec;
};
typedef struct Time *TIME;
void read(TIME T)
{
    printf("Enter time in Hrs:Min:Sec = ");
    scanf("%d%d%d",&T->hr,&T->min,&T->sec);
}
void display(TIME T)
{
    printf("%d : %d : %d\n",T->hr,T->min,T->sec);
}
void update(TIME T)
{
    T->sec++;
    if(T->sec>=60)
    {
        T->min++;
        T->sec=T->sec%60;
        if(T->min>=60)
        {
            T->hr++;
            T->min=T->min%60;
            if(T->hr>=24)
            T->hr=T->min=T->sec=0;
        }
    }
}
TIME add(TIME T1, TIME T2, TIME T)
{
    TIME T;
    T->hr = T1->hr + T2->hr;
    T->min = T1->min + T2->min;
    T->sec= T1->sec + T2->sec;
    if(T->sec>=60)
    {
        T->min++;
        T->sec=T->sec%60;
        if(T->min>=60)
        {
            T->hr++;
            T->min=T->min%60;
            if(T->hr>=24)
            T->hr=T->min=T->sec=0;
        }
    }
    if(T->min>=60)
    {
        T->hr++;
        T->min=T->min%60;
        if(T->hr>=24)
        T->hr=T->min=T->sec=0;
    }
    if(T->hr>=24)
        T->hr=T->min=T->sec=0;
    return T;
}
void main()
{
    struct Time T1,T2,T3,T4;
    int choice;
    printf("Menu\n1.Read\n2.Display\n3.Update\n4.Add\n5.Exit\n");
    for(;;)
    {
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : printf("Enter Time-1\n");
                     read(&T1); 
                     printf("Enter Time-2\n");
                     read(&T2);
                     break;
            case 2 : printf("Entered Times\n");
                     printf("Time-1 = "); 
                     display(&T1);
                     printf("Time-2 = "); 
                     display(&T2);
                     break;
            case 3 : printf("Enter Time to Update\n");
                     read(&T3);
                     printf("Entered Time = ");
                     display(&T3);
                     update(&T3);
                     printf("Updated Time = ");
                     display(&T3);
                     break;
            case 4 : printf("Time-1 = "); 
                     display(&T1);
                     printf("Time-2 = "); 
                     display(&T2);
                     add(&T1,&T2,&T4);
                     printf("Added Time = "); 
                     display(&T4);
                     break;
            case 5 : printf("THANK YOU\n");
                     exit(0);
            default : printf("Invalid Choice\n");
        }
    }
}