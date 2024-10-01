#ifndef SM_H
#define SM_H

typedef struct
{
    int row,col;
    double val;
}sm;

sm *create_sm(int, size_t, size_t);
sm *realloc_sm(sm*, size_t, size_t);
void *insert_sm(sm*, size_t, int, int, double);
sm *transpose_sm(sm*,size_t);
sm *add_sm(sm*, size_t, sm*, size_t);
sm *mult_sm(sm*, size_t, sm*, size_t);
void copy_sm(sm*, size_t, sm*, size_t);
//void *print_sm(sm*);

#endif