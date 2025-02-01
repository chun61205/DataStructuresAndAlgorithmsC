#ifndef BST_H
#define BST_H

typedef struct{
    int key;
    struct nodeBST *left, *right, *parent;
}nodeBST;

typedef struct{
    nodeBST *root;
}bst;

bst *createBST();
nodeBST *createNodeBST(int key);
nodeBST *findMinBST(bst*);
nodeBST *findMaxBST(bst*);
nodeBST *findSuccessorBST(nodeBST*);
void insertBST(bst*, int);
void deleteBST(bst*, int);
nodeBST *searchBST(bst*, int);

#endif