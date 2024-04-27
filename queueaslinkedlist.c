 #include<stdio.h>
#include<stdlib.h>

struct queue {
    int data;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

void enqueue() {
    struct queue *newnode;
    newnode = (struct queue*)malloc(sizeof(struct queue));
    if (newnode == NULL) {
        printf("Failed to allocate memory.\n");
        return;
    }
    printf("Enter the number: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (rear == NULL) { // The queue is empty
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue() {
    struct queue *temp;
    if (front == NULL) {
        printf("Queue is empty\n");
    }  
    else if(front->next==NULL)
    {
        temp=front;
        printf("the deleted item is %d",temp->data);
        front=rear=NULL;
        free(temp);
    }
    else{
        temp=front;
        front=front->next;
        printf("the deleted item is %d",temp->data);
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct queue *temp = front;
        printf("Queue elements are:\n");
        while (temp != NULL) {
            printf("%d \t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}