#include<stdio.h>
#define size 3
int lqueue[size];
int front =0;
int rear=-1;
void ENQUEUE()
{
    int num;
    printf("enter the number :");
    scanf("%d",&num);
    if(rear==size-1)
    {
        printf( "QUEUE OVERFLOW!!!");

    }
    else
    {
        rear=rear+1;
        lqueue[rear]=num;
    }

}
void DEQUEUE()
{
    int dt;
    if (front > rear)
    {
        printf("QUEUE UNDERFLOW\n");
    }
    else
    {
        dt = lqueue[front];
        front = front + 1;
        printf("Dequeued item = %d\n", dt);
    }
}

 void DISPLAY(){
     int i;
     if(rear==-1)
     {
         printf("queue is empty");
     }
     else
     {
         printf("\n Content of queue is :\n");
         for(i=rear;i>=front;i--)
         {
             printf("|%d|\n",lqueue[i]);
         }
     }
 }

     int main()
{
    int choice;
    printf("\n 1.ENQUEUE\n 2.DEQUEUE\n 3.DISPLAY\n 4.EXIT\n");
    while (1)
    {
        printf("\n Enter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            ENQUEUE();
            break;
        case 2:
            DEQUEUE();
            break;
        case 3:
            DISPLAY();
            break;
        case 4:
            exit(0);


        }
    }
}

