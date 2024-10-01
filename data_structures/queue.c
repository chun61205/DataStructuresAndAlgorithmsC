#include<stdlib.h>
#include<stdbool.h>
#include"queue.h"

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
    return (front==rear);
}
bool isEmptyCircularArrayQ(queue *q, size_t capacity, int front, int rear)
{
    return (front == rear);
}
queue *reallocArrayQ(queue *q, size_t capacity, int front, int rear, size_t newCapacity)
{
    if((rear - front) >= newCapacity)
        exit(EXIT_FAILURE);
    queue *result = (queue*)malloc(newCapacity * sizeof(queue));
    for(int i = 0, j = ((front+1)%capacity); j!=rear; i++, j++, j%=capacity)
        (result+i)->data = (q+j)->data;
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
    rear%=capacity;
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