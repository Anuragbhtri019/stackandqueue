#include<stdio.h>
#include<stdlib.h>
#define size 3
int cqueue[size];
int  front=size-1;
int rear=size-1;
void enqueue()
{
    int num;
    printf("enter the number to push: ");
    scanf("%d",&num);
    if((rear+1)%size==front)
    {
        printf("queue overflow");
    }
    else{
        rear=(rear+1)%size;
        cqueue[rear]=num;
    }
}
void dequeue()
{
    int dt;
    if(rear==front)
    {
        printf("queue underflow");

    }
    else{
        front=(front+1)%size;
        dt=cqueue[front];

        printf("dequeued item=%d",dt);
    }
}
void display()
{
    int i;
    if(rear==front)
    {
        printf("queue is empty");

    }
    else{
        printf("content of queue is \n");
        for(i=(front+1)%size;i!=rear;i=(i+1)%size)
        {
            printf("|%d|\n",cqueue[i]);
        }
        printf("\n|%d|",cqueue[rear]);
    }
}
int main()
{

    int choice;
    printf("1.enqueue\n2.dequeue\n3.display\n4.exit");
    while(1){
        printf("\nenter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);

        }
            }
            return 0;
}
