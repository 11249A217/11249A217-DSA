Aim:

To implement and perform basic stack operations such as Push, Pop, Peek, and Display using an array in C.

Algorithm for Stack Operations

Let stack[MAX] be an array and top = -1.

1. PUSH Operation

Algorithm:

Start

If top == MAX - 1, print “Stack Overflow” and stop

Else:

Increment top

Insert the element into stack[top]

Stop

2. POP Operation

Algorithm:

Start

If top == -1, print “Stack Underflow” and stop

Else:

Store stack[top] in a variable

Decrement top

Stop

3. PEEK Operation (View Top Element)

Algorithm:

Start

If top == -1, print “Stack is empty”

Else, print stack[top]

Stop

4. DISPLAY Operation

Algorithm:

Start

If top == -1, print “Stack is empty”

Else:

For i = top down to 0

Print stack[i]

Stop

Program:

#include <stdio.h>
#include <stdlib.h>

int top = -1;
int size;
char *STACK; // Dynamic Array

void push(char item)
{
    if (top == (size - 1))
    {
        printf("Stack is already full, no additional push allowed - Overflow");
    }
    else
    {
        top = top + 1;
        STACK[top] = item;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack is underflow");
    }
    else
    {
        char temp = STACK[top];
        top = top - 1;
        printf("Element popped %c", temp);
    }
}

void DisplayStack()
{
    if (top == -1)
    {
        printf("Stack is underflow");
        return;
    }
    printf("[Top] \n");
    for (int i = top; i >= 0; i--)
    {
        printf("%c \n", STACK[i]);
    }
}

int main()
{
    int choice;
    char data;

    printf("Enter size of stack: ");
    scanf("%d", &size);
    STACK = (char *)malloc(size * sizeof(char));

    while (1)
    {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf(" %c", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            DisplayStack();
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
