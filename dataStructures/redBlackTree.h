#ifndef RBT_H
#define RBT_H

typedef enum{
    RED, BLACK
}Color;

typedef struct{
    int key;
    Color color;
    struct nodeRBT *left, *right, *parent;
}nodeRBT;

typedef struct{
    nodeRBT *root;
    nodeRBT *nil;
}rbt;

rbt *createRBT();
nodeRBT *createNodeRBT(rbt*, int);
nodeRBT *findMinRBT(rbt*);
nodeRBT *findMaxRBT(rbt*);
nodeRBT *findSuccessorRBT(nodeRBT*);
void leftRotateRBT(rbt*, nodeRBT*);
void rightRotateRBT(rbt*, nodeRBT*);
void insertRBT(rbt*, int);
void deleteRBT(rbt*, int);
nodeRBT *searchRBT(rbt*, int);

#endif