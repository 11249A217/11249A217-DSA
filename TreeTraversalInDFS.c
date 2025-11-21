Aim:

To perform Depth First Search (DFS) traversal of a binary tree in C.

Algorithm (DFS Tree Traversal)

DFS can be performed in three ways:

1. Inorder Traversal (Left – Root – Right)

Algorithm:

Start

If the node is NULL, return.

Traverse the left subtree recursively.

Visit (print) the node data.

Traverse the right subtree recursively.

Stop

2. Preorder Traversal (Root – Left – Right)

Algorithm:

Start

If the node is NULL, return.

Visit (print) the node data.

Traverse the left subtree recursively.

Traverse the right subtree recursively.

Stop

3. Postorder Traversal (Left – Right – Root)

Algorithm:

Start

If the node is NULL, return.

Traverse the left subtree recursively.

Traverse the right subtree recursively.

Visit (print) the node data.

Stop

Program:

#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
// Data, Pointer to left child and Pointer to right child
struct Node
{
    int data;
    struct Node *left, *right;
};

// Node creation
struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert the new node and returns root node of the updated tree
struct Node *insert(struct Node *root, int value)
{
    // First node will be root node
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Preorder - Root -> Left -> Right
void preorder(struct Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Inorder - Left -> Root -> Right
void inorder(struct Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Postorder - Left -> Right -> Root
void postorder(struct Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{

    int n, value;
    struct Node *root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        root = insert(root, value); // Insert dynamically into BST
    }

    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);
    return 0;
}
