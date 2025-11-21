Aim

To convert a given infix expression into its equivalent postfix expression using a stack in C.

Algorithm (Infix to Postfix Conversion using Stack)

Start

Declare a stack and initialize top = -1.

Read the infix expression.

Scan the infix expression from left to right:

If the symbol is an operand (letter/number), add it to postfix expression.

If the symbol is ‘(’, push it onto the stack.

If the symbol is ‘)’, pop and add operators from the stack to postfix until ‘(’ is found. Then discard the ‘(’.

If the symbol is an operator (+, -, *, /, ^):

While the stack is not empty and precedence of the stack top is greater than or equal to current operator, pop from stack and add to postfix.

Push the current operator onto the stack.

After scanning the entire infix expression, pop all remaining operators from the stack and append to postfix.

Display the postfix expression.

  Program:
  #include <stdio.h>
#include <stdlib.h>

int TOP = -1, MAX;
char *STACK;

void Display()
{
    printf("Current Stack elements are -");
    for (int i = 0; i <= TOP; i++)
    {
        printf("[%c,]", STACK[i]);
    }
    printf("\n");
}

void Push(char item)
{
    if (TOP == MAX - 1)
    {
        printf("Stack is overflow");
    }
    else
    {
        TOP = TOP + 1;
        STACK[TOP] = item;
    }
}

char Pop()
{
    if (TOP == -1)
    {
        printf("Stack is underflow / empty\n");
        return '\0';
    }
    else
    {
        char item = STACK[TOP];
        TOP = TOP - 1;
        return item;
    }
}

char Peek()
{
    if (TOP == -1)
    {
        // printf("Stack is underflow / empty\n");
        return '\0';
    }
    else
    {
        return STACK[TOP];
    }
}

int GetPrecedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1; // lowest precedence
    case '*':
    case '/':
        return 2;
    case '^':
        return 3; // highest precedence
    default:
        return 0; // consider it as operand
    }
}

int main()
{
    printf("Enter the size of infix expression: ");
    scanf("%d", &MAX);

    STACK = (char *)malloc(MAX * sizeof(char));
    char infix[MAX];
    char postfix[MAX];

    printf("Please enter the infix string of size %d: ", MAX);
    scanf("%s", infix);

    int TokenPrecedence, j = 0, i = 0;
    char c, temp;

    // Reading one token at a time
    while ((c = infix[i]) != '\0')
    // for (int i = 0; i < MAX; i++)
    {
        // c = infix[i];
        TokenPrecedence = GetPrecedence(c); // Current token at a time
        if (TokenPrecedence > 0)            // Current token is Operator
        {
            while (TokenPrecedence <= GetPrecedence(Peek())) // Current Token <= Stack Top Token
            {
                postfix[j++] = Pop();
            }
            Push(c);
        }
        else // Current token is operand or '(' or ')'
        {
            switch (c)
            {
            case '(':
                Push(c);
                break;
            case ')':
                while (Peek() != '(')
                {
                    postfix[j++] = Pop();
                }
                Pop();
                break;
            default:
                postfix[j++] = c;
                break;
            }
        }
        i++;
    }

    // Pop All remaining tokens from stack
    while (Peek() != '\0')
    {
        char c = Pop();
        postfix[j++] = c;
    }
    postfix[j] = '\0';
    printf("Postfix notation is : %s", postfix);
    return 0;
}
Stop
