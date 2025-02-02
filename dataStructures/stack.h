#ifndef STACK_H
#define STACK_H

typedef struct{
    int data;
}nodeStackArray;

typedef struct{
    nodeStackArray *node;
    size_t capacity;
    int top;
}stackArray;

typedef struct{
    int data;
    struct nodeStackLinkedList *next;
}nodeStackLinkedList;

typedef struct{
    nodeStackLinkedList *top;
}stackLinkedList;

stackArray *createStackArray(size_t); 
bool isFullStackArray(stackArray*);
bool isEmptyStackArray(stackArray*);
stackArray *reallocStackArray(stackArray*, size_t);
void pushStackArray(stackArray*, int);
void popStackArray(stackArray*);

stackLinkedList *createStackLinkedList();
nodeStackLinkedList *createNodeStackLinkedList(int);
int isEmptyStackLinkedList(stackLinkedList*);
void pushStackLinkedList(stackLinkedList*, int);
void popStackLinkedList(stackLinkedList*);
int topStackLinkedList(stackLinkedList*);

#endif