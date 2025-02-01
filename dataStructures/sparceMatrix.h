#ifndef SM_H
#define SM_H

typedef struct{
    int row, col;
    double val;
}nodeSm;

typedef struct{
    nodeSm *node;
    int row, col;
    size_t capacity;
    size_t size;
}sm;

sm *createSm(int, int, int);
sm *reallocSm(sm*, size_t);
void insertSm(sm*, int, int, double);
sm *transposeSm(sm*);
sm *addSm(sm*, sm*);
sm *multSm(sm*, sm*);
void copySm(sm*, sm*);
//void *printSm(sm*);

#endif