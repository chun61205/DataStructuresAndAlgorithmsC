#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

stack *createStack(size_t capacity)
{
    stack *new_stack = (stack*)malloc(sizeof(stack));
    if(new_stack == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    new_stack->node = (nodeStack*)malloc(capacity * sizeof(nodeStack));
    if(new_stack->node == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        free(new_stack);
        exit(EXIT_FAILURE);
    }
    new_stack->capacity = capacity;
    new_stack->top = -1;
    return new_stack;
}
bool isFullStack(stack *s)
{
    return (s->top >= (s->capacity - 1));
}
bool isEmptyStack(stack *s)
{
    return (s->top == -1);
}
stack *reallocStack(stack *s, size_t newCapacity)
{
    if(s->top >= newCapacity){
        fprintf(stderr, "New capacity is less than current size!\n");
        exit(EXIT_FAILURE);
    }
    nodeStack *new_nodes = (nodeStack*)realloc(s->s, newCapacity * sizeof(nodeStack));
    if(new_nodes == NULL){
        fprintf(stderr, "Failed to reallocate memory for stack nodes.\n");
        exit(EXIT_FAILURE);
    }
    s->node = new_nodes;
    s->capacity = newCapacity;
    return s;
}
void pushStack(stack *s, int data)
{
    if (isFullStack(s))
        exit(EXIT_FAILURE);
    s->top++;
    s->node[s->top].data = data;
}
void popStack(stack *s)
{
    if (isEmptyStack(s))
        exit(EXIT_FAILURE);
    s->top--;
}