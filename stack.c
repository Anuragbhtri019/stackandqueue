#include<stdio.h>
#define SIZE 3
int stack [SIZE];
int top=-1;
void PUSH()
{
    int num ;
    printf("enter item you want to push :");
    scanf("%d",&num);
    if(top==SIZE-1)
    {
        printf("STACK OVERFLOW !!!");
    }
    else
    {
        top =top+1;
        stack[top]=num;
    }
}
void POP()
{
    int dt ;
    if (top==-1)
    {
        printf("\n STACK UNDERFLOW !!!!");
    }
    else
    {
        dt=stack[top];
        top=top-1;
        printf("\n popped item=%d ",dt);
    }
}
void DISPLAY()
{
    int i;
    if (top==-1)
    {
        printf("STACK IS EMPTY !!!");
    }
    else
    {
        printf("content of stack is \n");
        for (i=top;i>=0;i--)
            printf("|%d|\n",stack[i]);
    }
}
int main()
{
    int choice;
    printf("\n 1.PUSH \n 2.POP\n 3.DISPLAY\n 4. Exit");
    while (1)
    {
        printf("\n Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            PUSH();
            break;
        case 2:
            POP();
            break;
        case 3:
            DISPLAY();
            break;
        case 4:
            exit(0);


        }
    }
}
