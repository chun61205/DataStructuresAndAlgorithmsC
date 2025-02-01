#ifndef QUEUE_H
#define QUEUE_H

typedef struct{
    int data;
}nodeQueue;

typedef struct{
    nodeQueue *node;
    size_t capacity;
    int front, rear;
}linearQueue;

typedef struct{
    nodeQueue *node;
    size_t capacity;
    int front, rear;
}circularQueue;

linearQueue *createLinearQueue(size_t);
bool isFullLinearQueue(linearQueue*);
bool isEmptyLinearQueue(linearQueue*);
void addLinearQueue(linearQueue*, nodeQueue);
void deleteLinearQueue(linearQueue*);

circularQueue *createCircularQueue(size_t);
bool isFullCircularQueue(circularQueue*);
bool isEmptyCircularQueue(circularQueue*);
void addCircularQueue(circularQueue*, nodeQueue);
void deleteCircularQueue(circularQueue*);

#endif