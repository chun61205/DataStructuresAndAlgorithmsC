#ifndef POLY_H
#define POLY_H

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

#endif