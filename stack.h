#pragma once

// Define a structure for a node in the stack
typedef struct StackNode {
    char *value;
    struct StackNode *next;
} StackNode;

// Define a structure for the stack
typedef struct {
    StackNode *head;
} Stack;

// Function declarations
Stack *createStack();
void push(Stack *stack, char *value);
char *pop(Stack *stack);
void destroyStack(Stack *stack);
int isEmpty(Stack *stack);


