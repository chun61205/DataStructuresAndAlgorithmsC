#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

stackArray *createStackArray(size_t capacity){
    stackArray *newStack = (stackArray*)malloc(sizeof(stackArray));
    if(newStack == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newStack->node = (nodeStackArray*)malloc(capacity * sizeof(nodeStackArray));
    if(newStack->node == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        free(newStack);
        exit(EXIT_FAILURE);
    }
    newStack->capacity = capacity;
    newStack->top = -1;
    return newStack;
}

bool isFullStackArray(stackArray *s){
    return (s->top >= (s->capacity - 1));
}

bool isEmptyStackArray(stackArray *s){
    return (s->top == -1);
}

stackArray *reallocStackArray(stackArray *s, size_t newCapacity){
    if(s->top >= newCapacity){
        fprintf(stderr, "New capacity is less than current size!\n");
        exit(EXIT_FAILURE);
    }
    nodeStackArray *newNodes = (nodeStackArray*)realloc(s->s, newCapacity * sizeof(nodeStackArray));
    if(newNodes == NULL){
        fprintf(stderr, "Failed to reallocate memory for stack nodes.\n");
        exit(EXIT_FAILURE);
    }
    s->node = newNodes;
    s->capacity = newCapacity;
    return s;
}

void pushStackArray(stackArray *s, int data){
    if(isFullStackArray(s))
        exit(EXIT_FAILURE);
    s->top++;
    s->node[s->top].data = data;
}

void popStackArray(stackArray *s){
    if(isEmptyStackArray(s))
        exit(EXIT_FAILURE);
    s->top--;
}

stackLinkedList *createStackLinkedList(){
    stackLinkedList *s = (stackLinkedList*)malloc(sizeof(stackLinkedList));
    if(s == NULL){
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    s->top = NULL;
    return s;
}

nodeStackLinkedList *createNodeStackLinkedList(int data){
    nodeStackLinkedList *newNode = (nodeStackLinkedList*)malloc(sizeof(nodeStackLinkedList));
    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool isEmptyStackLinkedList(stackLinkedList *s){
    return (s->top == NULL);
}

void pushStackLinkedList(stackLinkedList *s, int data){
    nodeStackLinkedList *newNode = (nodeStackLinkedList*)malloc(sizeof(nodeStackLinkedList));
    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = s->top;
    s->top = newNode;
}

void popStackLinkedList(stackLinkedList *s){
    if(isEmpty(s)){
        return;
    }
    nodeStackLinkedList *temp = s->top;
    s->top = temp->next;
    free(temp);
}

int topStackLinkedList(stackLinkedList *s){
    if(isEmpty(s)){
        printf("The stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return s->top->data;
}