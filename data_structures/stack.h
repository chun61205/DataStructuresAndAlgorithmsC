#ifndef POLY_H
#define POLY_H

typedef struct{
    int data; //The data type of data is modifiable.
}nodeStack;

typedef struct{
    nodeStack *node;
    size_t capacity;
    int top;
}stack;

stack *createStack(size_t); 
bool isFullStack(stack*);
bool isEmptyStack(stack*);
stack *reallocStack(stack*, size_t);
void pushStack(stack*, int);
void popStack(stack*);
//void printStack(stack*);

#endif