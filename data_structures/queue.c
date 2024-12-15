#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

linearQueue *createLinearQueue(size_t capacity){
    linearQueue *q = (linearQueue*)malloc(sizeof(linearQueue));
    if(q == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    q->node = (nodeQueue*)malloc(capacity * sizeof(nodeQueue));
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
bool isFullLinearQueue(linearQueue *q){
    return (q->rear >= (q->capacity - 1));
}
bool isEmptyLinearQueue(linearQueue *q){
    return (q->front == q->rear);
}
linearQueue *reallocLinearArrayQ(linearQueue *q, size_t newCapacity){
    if(newCapacity < (q->rear + q->capacity - q->front) % q->capacity){
        fprintf(stderr, "New capacity is less than current size!\n");
        exit(EXIT_FAILURE);
    }

    q->node = (nodeQueue *)realloc(q->node, newCapacity * sizeof(nodeQueue));

    if(q->node == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    q->capacity = newCapacity;

    return q;
}
void addLinearQueue(linearQueue *q, nodeQueue item){
    if (isFullLinearQueue(q)) {
        fprintf(stderr, "Queue is full!\n");
        exit(EXIT_FAILURE);
    }
    q->rear++;
    q->node[q->rear] = item;
}
void deleteLinearQueue(linearQueue *q){
    if (isEmptyLinearQueue(q)) {
        fprintf(stderr, "Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    q->front++;
}
circularQueue *createCircularQueue(size_t capacity){
    circularQueue *q = (circularQueue*)malloc(sizeof(circularQueue));
    if(q == NULL){
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    q->node = (nodeQueue*)malloc(capacity * sizeof(nodeQueue));
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
bool isFullCircularQueue(circularQueue *q){
    return ((q->rear + 1) % q->capacity == q->front);
}
bool isEmptyCircularQueue(circularQueue *q){
    return (q->front == q->rear);
}
circularQueue *reallocCircularArrayQ(circularQueue *q, size_t newCapacity){
    if(newCapacity < (q->rear + q->capacity - q->front) % q->capacity){
        fprintf(stderr, "New capacity is less than current size!\n");
        exit(EXIT_FAILURE);
    }
    nodeQueue *newNode = (nodeQueue *)malloc(newCapacity * sizeof(nodeQueue));
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
void addCircularQueue(circularQueue *q, nodeQueue item){
    if (isFullCircularQueue(q)){
        fprintf(stderr, "Queue is full!\n");
        exit(EXIT_FAILURE);
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->node[q->rear] = item;
}
void deleteCircularQueue(circularQueue *q){
    if (isEmptyCircularQueue(q)){
        fprintf(stderr, "Queue is empty!\n");
        exit(EXIT_FAILURE);
    }
    q->front = (q->front + 1) % q->capacity;
}