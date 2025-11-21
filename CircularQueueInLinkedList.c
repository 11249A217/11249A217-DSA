Aim:

To implement a Circular Queue using a Linked List in C and perform basic operations such as Enqueue, Dequeue, and Display.

Algorithm (Circular Queue Using Linked List):

In a circular queue linked list, the last node points to the first node.
We use two pointers:
front
rear

1. ENQUEUE (Insertion)

Algorithm:

Start

Create a new node.

Store data in newNode->data.

Set newNode->next = NULL.

If front == NULL (queue is empty):

Set front = rear = newNode

Set rear->next = front

Else:

Set rear->next = newNode

Update rear = newNode

Set rear->next = front

Stop

2. DEQUEUE (Deletion)

Algorithm:

Start

If front == NULL, display “Queue Underflow” and stop

If front == rear (only one node):

Free front

Set front = rear = NULL

Else:

Store front in temp

Update front = front->next

Set rear->next = front

Free temp

Stop

3. DISPLAY Operation

Algorithm:

Start

If front == NULL, display “Queue is empty”

Else:

Set temp = front

Do:

Print temp->data

Move temp = temp->next

While temp != front

Stop

Program:

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue operation
void enqueue(int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = item;

    if (front == NULL && rear == NULL) //Queue empty
    {
        front = rear = newNode;
        newNode->next = front; //Circular link
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Maintain circular link
    }

    printf("%d inserted into circular queue.\n", item);
}

// Dequeue operation
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }

    struct Node *temp = front;

    if (front == rear) // Only one node
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front; // Maintain circular link
    }

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

// Display operation
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;

    printf("Circular Queue elements: ");
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("\n");
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n--- Queue Using Linked List Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            enqueue(data);
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
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
