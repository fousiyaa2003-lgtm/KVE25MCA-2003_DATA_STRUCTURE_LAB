#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("\nMemory allocation failed\n");
        return;
    }

    newnode->data = value;
    newnode->next = top; // works for both empty and non-empty stack
    top = newnode;

    printf("\nNode is inserted\n");
}

void pop()
{
    if (top == NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        struct node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        printf("\nThe popped element is: %d\n", temp_data);
    }
}

void display()
{
    if (top == NULL)
    {
        printf("\nStack is empty\n");
    }
    else
    {
        struct node *temp = top;
        printf("\nThe stack is:\n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    printf("\nImplementation of Stack using Linked List\n");

    while (1)
    {
        printf("\nEnter your choice\n"
               "1 for push\n"
               "2 for pop\n"
               "3 for display\n"
               "4 for exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the value to be inserted: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf("\nWrong choice\n");
        }
    }

    return 0;
}


