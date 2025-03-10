#ifndef QUEUE_H
#define QUEUE_H

typedef struct{
    int data;
}nodeLinearQueueArray;

typedef struct{
    nodeLinearQueueArray *node;
    size_t capacity;
    int front, rear;
}linearQueueArray;

typedef struct{
    int data;
}nodeCircularQueueArray;

typedef struct{
    nodeCircularQueueArray *node;
    size_t capacity;
    int front, rear;
}circularQueueArray;

typedef struct nodeLinearQueueLinkedList{
    int data;
    struct nodeLinearQueueLinkedList *next;
}nodeLinearQueueLinkedList;

typedef struct{
    nodeLinearQueueLinkedList *front, *rear;
}linearQueueLinkedList;

typedef struct nodeCircularQueueLinkedList{
    int data;
    struct nodeCircularQueueLinkedList *next;
}nodeCircularQueueLinkedList;

typedef struct{
    nodeCircularQueueLinkedList *rear;
}circularQueueLinkedList;

linearQueueArray *createLinearQueueArray(size_t);
bool isFullLinearQueueArray(linearQueueArray*);
bool isEmptyLinearQueueArray(linearQueueArray*);
void addLinearQueueArray(linearQueueArray*, nodeLinearQueueArray);
void deleteLinearQueueArray(linearQueueArray*);

circularQueueArray *createCircularQueueArray(size_t);
bool isFullCircularQueueArray(circularQueueArray*);
bool isEmptyCircularQueueArray(circularQueueArray*);
void addCircularQueueArray(circularQueueArray*, nodeCircularQueueArray);
void deleteCircularQueueArray(circularQueueArray*);

linearQueueLinkedList *createLinearQueueLinkedList();
nodeLinearQueueLinkedList *createNodeLinearQueueLinkedList(int);
bool isEmptyLinearQueueLinkedList(linearQueueLinkedList*);
void addLinearQueueLinkedList(linearQueueLinkedList*, int);
void deleteLinearQueueLinkedList(linearQueueLinkedList*);

circularQueueLinkedList *createCircularQueueArray();
nodeCircularQueueLinkedList *createNodeCircularQueueArray(int);
bool isEmptyCircularQueueLinkedList(circularQueueLinkedList*);
void addCircularQueueLinkedList(circularQueueLinkedList*, int);
void deleteCircularQueueLinkedList(circularQueueLinkedList*);

#endif