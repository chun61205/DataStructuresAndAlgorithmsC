#ifndef POLY_H
#define POLY_H

typedef struct
{
    int data; //The data type of data is modifiable.
}stack;

stack *createStack(size_t); 
bool isFullStack(stack*, size_t, int);
bool isEmptyStack(stack*, size_t, int);
stack *reallocStack(stack*, size_t, int, size_t);
void pushStack(stack*, size_t, int, stack);
void popStack(stack*, size_t, int);
//void printStack(stack*);

#endif