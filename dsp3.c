#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int cqueue_arr[SIZE];
int front = -1;
int rear  = -1;

void insert(int item)
{
    // Check queue full
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1))
    {
        printf("Queue is FULL\n");
        return;
    }

    // First insertion
    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    cqueue_arr[rear] = item;

    printf("%d is inserted\n", item);
}

void deletion()
{
    if (front == -1)
    {
        printf("Queue is EMPTY\n");
        return;
    }

    printf("%d is deleted from Queue\n", cqueue_arr[front]);

    // Only one element left
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

void display()
{
    int i;

    if (front == -1)
    {
        printf("Queue is EMPTY\n");
        return;
    }

    printf("Queue elements are: ");

    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
            printf("%d ", cqueue_arr[i]);
    }
    else
    {
        for (i = front; i < SIZE; i++)
            printf("%d ", cqueue_arr[i]);

        for (i = 0; i <= rear; i++)
            printf("%d ", cqueue_arr[i]);
    }

    printf("\n");
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\n---- Circular Queue Menu ----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                insert(item);
                break;

            case 2:
                deletion();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

