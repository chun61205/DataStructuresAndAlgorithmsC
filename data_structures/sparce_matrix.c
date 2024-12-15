#include <stdlib.h>
#include "sparce_matrix.h"

sm *createSm(int row, int col, size_t capacity) {
    sm *A = (sm*)malloc(sizeof(sm));
    if (A == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    A->node = (nodeSm*)malloc(capacity * sizeof(nodeSm));
    if (A->node == NULL) {
        free(A);
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    A->capacity = capacity;
    A->size = 0;
    A->row = row;
    A->col = col;

    return A;
}
sm *reallocSm(sm *A, size_t newCapacity)
{
    if(newCapacity < A->size)
        exit(EXIT_FAILURE);
    A->node = (nodeSm*)realloc(A->node, newCapacity * sizeof(nodeSm));
    if(A->node == NULL){
        free(A);
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    A->capacity = newCapacity;
    return A;
}
void insertSm(sm *A, int row, int col, double val)
{
    if(val == 0){
        return;
    }
    if(A->size >= A->capacity){
        size_t newCapacity = A->capacity == 0 ? 1 : A->capacity * 2;
        A = reallocSm(A, newCapacity);
    }
    
    int pos = 0;
    while(pos < A->size && (A->node[pos].row < row || (A->node[pos].row == row && A->node[pos].col < col))){
        pos++;
    }

    if(pos < A->size && A->node[pos].row == row && A->node[pos].col == col){
        A->node[pos].val = val;
        return;
    }

    for(int i = A->size; i > pos; --i){
        A->node[i] = A->node[i - 1];
    }

    A->node[pos].row = row;
    A->node[pos].col = col;
    A->node[pos].val = val;
    A->size++;
    return;
}
sm *transposeSm(sm *A){
    sm *result = createSm(A->capacity);

    for(int i = 0; i < A->size; i++){
        insertSm(result, A->node[i].col, A->node[i].row, A->node[i].val);
    }

    return result;
}
sm *addSm(sm *A, sm *B){
    if(A->row != B->row || A->col != B->col){
        exit(EXIT_FAILURE);
    }

    sm *result = createSm(A->row, A->col, A->capacity);

    for(int i = 0; i < A->size; i++){
        insertSm(result, A->node[i].row, A->node[i].col, A->node[i].val);
    }

    for(int i = 0; i < B->size; i++){
        insertSm(result, B->node[i].row, B->node[i].col, B->node[i].val);
    }

    for(int i = 0; i < result->size; i++){
        for(int j = 0; j < A->size; j++){
            if(result->node[i].row == A->node[j].row && result->node[i].col == A->node[j].col){
                result->node[i].val += A->node[j].val;
            }
        }
    }

    return result;
}
sm *multSm(sm *A, sm *B){
    if(A->capacity != B->capacity){
        exit(EXIT_FAILURE);
    }

    sm *result = createSm(A->row, B->col, A->capacity);
    sm *transposedB = transposeSm(B);

    for(int i = 0; i < A->size; i++){
        for(int j = 0; j < transposedB->size; j++){
            if(A->node[i].col == transposedB->node[j].col){
                double val = A->node[i].val * transposedB->node[j].val;
                insertSm(result, A->node[i].row, transposedB->node[j].row, val);
            }
        }
    }

    free(transposedB->node);
    free(transposedB);
    return result;
}
void copySm(sm *A, sm *B) {
    if (B->capacity < A->size) {
        exit(EXIT_FAILURE);
    }

    B->size = A->size;
    B->row = A->row;
    B->col = A->col;
    for (size_t i = 0; i < A->size; i++) {
        B->node[i].row = A->node[i].row;
        B->node[i].col = A->node[i].col;
        B->node[i].val = A->node[i].val;
    }
}