#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

linearQueueArray *createLinearQueueArray(size_t capacity){
    linearQueueArray *q = (linearQueueArray*)malloc(sizeof(linearQueueArray));
    if(q == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    q->node = (nodeLinearQueueArray*)malloc(capacity * sizeof(nodeLinearQueueArray));
    if(q->node == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        free(q);
        exit(EXIT_FAILURE);
    }
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFullLinearQueueArray(linearQueueArray *q){
    return (q->rear >= (q->capacity - 1));
}

bool isEmptyLinearQueueArray(linearQueueArray *q){
    return (q->front == q->rear);
}

linearQueueArray *reallocLinearQueueArray(linearQueueArray *q, size_t newCapacity){
    if(newCapacity < (q->rear + q->capacity - q->front) % q->capacity){
        fprintf(stderr, "New capacity is less than current size!\n");
        exit(EXIT_FAILURE);
    }

    q->node = (nodeLinearQueueArray*)realloc(q->node, newCapacity * sizeof(nodeLinearQueueArray));

    if(q->node == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    q->capacity = newCapacity;

    return q;
}

void addLinearQueueArray(linearQueueArray *q, nodeLinearQueueArray item){
    if (isFullLinearQueueArray(q)) {
        fprintf(stderr, "Queue is full!\n");
        exit(EXIT_FAILURE);
    }
    q->rear++;
    q->node[q->rear] = item;
}

void deleteLinearQueueArray(linearQueueArray *q){
    if (isEmptyLinearQueueArray(q)) {
        fprintf(stderr, "Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    q->front++;
}

circularQueueArray *createCircularQueueArray(size_t capacity){
    circularQueueArray *q = (circularQueueArray*)malloc(sizeof(circularQueueArray));
    if(q == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    q->node = (nodeCircularQueueArray*)malloc(capacity * sizeof(nodeCircularQueueArray));
    if(q->node == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        free(q);
        exit(EXIT_FAILURE);
    }
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isFullCircularQueueArray(circularQueueArray *q){
    return ((q->rear + 1) % q->capacity == q->front);
}

bool isEmptyCircularQueueArray(circularQueueArray *q){
    return (q->front == q->rear);
}

circularQueueArray *reallocCircularQueueArray(circularQueueArray *q, size_t newCapacity){
    if(newCapacity < (q->rear + q->capacity - q->front) % q->capacity){
        fprintf(stderr, "New capacity is less than current size!\n");
        exit(EXIT_FAILURE);
    }
    nodeCircularQueueArray *newNode = (nodeCircularQueueArray*)malloc(newCapacity * sizeof(nodeCircularQueueArray));
    if(newNode == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    int current = (q->front + 1) % q->capacity;

    while(current != (q->rear + 1) % q->capacity){
        newNode[i] = q->node[current];
        current = (current + 1) % q->capacity;
        i++;
    }

    free(q->node);

    q->node = newNode;
    q->capacity = newCapacity;
    if(i == 0){
        q->front = -1;
        q->rear = -1;
    }else{
        q->front = newCapacity - 1;
        q->rear = i - 1;
    }

    return q;
}

void addCircularQueueArray(circularQueueArray *q, nodeCircularQueueArray item){
    if (isFullCircularQueueArray(q)){
        fprintf(stderr, "Queue is full!\n");
        exit(EXIT_FAILURE);
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->node[q->rear] = item;
}

void deleteCircularQueueArray(circularQueueArray *q){
    if (isEmptyCircularQueueArray(q)){
        fprintf(stderr, "Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    q->front = (q->front + 1) % q->capacity;
}

linearQueueLinkedList *createLinearQueueLinkedList(){
    linearQueueLinkedList *q = (linearQueueLinkedList*)malloc(sizeof(linearQueueLinkedList));
    if(!q){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL;
    return q;
}

nodeLinearQueueLinkedList *createNodeLinearQueueLinkedList(int data){
    nodeLinearQueueLinkedList *newNode = (nodeLinearQueueLinkedList*)malloc(sizeof(nodeLinearQueueLinkedList));
    if(!newNode){
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool isEmptyLinearQueueLinkedList(linearQueueLinkedList *queue){
    return q->front == NULL;
}

void addLinearQueueLinkedList(linearQueueLinkedList *q, int data){
    nodeLinearQueueLinkedList *newNode = createNodeLinearQueueLinkedList(data);
    
    if(isEmptyLinearQueueLinkedList(q)){
        q->front = q->rear = newNode;
    }else{
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void deleteLinearQueueLinkedList(linearQueueLinkedList *q){
    if(isEmptyLinearQueueLinkedList(q)){
        return;
    }
    
    nodeLinearQueueLinkedList *temp = q->front;
    q->front = q->front->next;
    
    if(q->front == NULL){
        q->rear = NULL;
    }
    
    free(temp);
}

circularQueueLinkedList *createCircularQueueLinkedList(){
    circularQueueLinkedList *q = (circularQueueLinkedList*)malloc(sizeof(circularQueueLinkedList));
    if(!q){
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    q->rear = NULL;
    return q;
}

nodeCircularQueueLinkedList *createNodeCircularQueueArray(int data){
    nodeCircularQueueLinkedList *newNode = (nodeCircularQueueLinkedList*)malloc(sizeof(nodeCircularQueueLinkedList));
    if(newNode == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool isEmptyCircularQueueLinkedList(circularQueueLinkedList *q){
    return (q->rear == NULL);
}

void addCircularQueueLinkedList(circularQueueLinkedList *q, int data){
    nodeCircularQueueLinkedList *newNode = createNodeCircularQueueArray(data);
    newNode->data = data;
    
    if(q->rear == NULL){
        newNode->next = newNode;
        q->rear = newNode;
    }else{
        newNode->next = q->rear->next;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void deleteCircularQueueLinkedList(circularQueueLinkedList *q){
    if(isEmptyCircularQueueLinkedList(q)){
        return;
    }

    nodeCircularQueueLinkedList *front = q->rear->next;
    int data = front->data;
    
    if(q->rear == front){
        q->rear = NULL;
    }else{
        q->rear->next = front->next;
    }
    free(front);
}