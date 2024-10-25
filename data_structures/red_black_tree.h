#ifndef POLY_H
#define POLY_H

typedef enum{
    RED, BLACK
}Color;

typedef struct{
    int data; //The data type of data is modifiable.
    Color color;
    struct nodeRBT *left, *right, *parent;
}nodeRBT;

typedef struct{
    nodeRBT *root;
    nodeRBT *nil;
}rbt;

rbt *createRBT();
nodeRBT *createNodeRBT(rbt*, int);
void leftRotateRBT(rbt*, nodeRBT*);
void rightRotateRBT(rbt*, nodeRBT*);
void insertRBT(rbt*, int);
void deleteRBT(rbt*, int);
nodeRBT *searchRBT(rbt*, int);

#endif