#include <stdio.h>

int stack[100], top = -1, n, x, i;

void push()
{
    if (top >= n - 1)
        printf("Stack is full\n");
    else
    {
        printf("Enter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}

void pop()
{
    if (top <= -1)
        printf("Stack is empty\n");
    else
    {
        printf("The element popped is: %d\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top >= 0)
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
            printf("%d\n", stack[i]);

        printf("Enter the next choice\n");
    }
    else
    {
        printf("The stack is empty\n");
    }
}

