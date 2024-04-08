#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
    int data; //The data type of data is modifiable.
}queue;

queue *createArrayQ(size_t);
bool isFullLinearArrayQ(queue*, size_t, int, int);
bool isFullCircularArrayQ(queue*, size_t, int, int);
bool isEmptyLinearArrayQ(queue*, size_t, int, int);
bool isEmptyCircularArrayQ(queue*, size_t, int, int);
queue *reallocArrayQ(queue*, size_t, int, int, size_t);
void addLinearArrayQ(queue*, size_t, int, int, queue);
void addCircularArrayQ(queue*, size_t, int, int, queue);
void deleteLinearArrayQ(queue*, size_t, int, int);
void deleteCircularArrayQ(queue*, size_t, int, int);

queue *createArrayQ(size_t capacity)
{
    return (queue*)malloc(capacity*sizeof(queue));
}

bool isFullLinearArrayQ(queue *q, size_t capacity, int front, int rear)
{
    return (rear >= (capacity-1));
}

bool isFullCircularArrayQ(queue *q, size_t capacity, int front, int rear)
{
    return ((rear % capacity) == front);
}

bool isEmptyLinearArrayQ(queue *q, size_t capacity, int front, int rear)
{
    return (front == rear);
}

bool isEmptyCircularArrayQ(queue *q, size_t capacity, int front, int rear)
{
    return (front == rear);
}

queue *reallocArrayQ(queue *q, size_t capacity, int front, int rear, size_t newCapacity)
{
    if((rear-front) >= newCapacity)
        exit(EXIT_FAILURE);
    queue *result = (queue*)malloc(newCapacity * sizeof(queue));
    for(int i = 0, j = ((front + 1) % capacity); j != rear; i++, j++, j %= capacity)
        (result + i)->data = (q + j)->data;
    free(q);
    return result;
}

void addLinearArrayQ(queue *q, size_t capacity, int front, int rear, queue item)
{
    if(isFullLinearArrayQ(q, capacity, front, rear))
        exit(EXIT_FAILURE);
    rear++;
    *(q + rear) = item;
    return;
}

void addCircularArrayQ(queue *q, size_t capacity, int front, int rear, queue item)
{
    if(isFullCircularArrayQ(q, capacity, front, rear))
        exit(EXIT_FAILURE);
    rear++;
    rear %= capacity;
    *(q + rear) = item;
    return;
}

void deleteLinearArrayQ(queue *q, size_t capacity, int front, int rear)
{
    if(isEmptyLinearArrayQ(q, capacity, front, rear));
        exit(EXIT_FAILURE);
    front++;
    return;
}

void deleteCircularArrayQ(queue *q, size_t capacity, int front, int rear)
{
    if(isEmptyCircularArrayQ(q, capacity, front, rear))
        exit(EXIT_FAILURE);
    front++;
    front%=capacity;
    return;
}