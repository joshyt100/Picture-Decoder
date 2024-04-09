#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

// Function to create a new stack
Stack *createStack() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Memory allocation error\n");
    }
    stack->head = NULL;
    return stack;
}

// Function to push a value onto the stack
void push(Stack *stack, char *val) {
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error\n");
    }
    newNode->value = strdup(val);
    newNode->next = stack->head;
    stack->head = newNode;
}

// Function to pop a value from the stack
char *pop(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Error: can't pop an empty stack'\n");
    }
    StackNode *temp = stack->head;
    char *value = temp->value;
    stack->head = temp->next;
    free(temp);
    return value;
}

// Function to check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->head == NULL;
}

// Function to free memory allocated to the stack
void destroyStack(Stack *stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

