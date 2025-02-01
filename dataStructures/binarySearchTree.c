#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"

bst *createBST(){
    bst *newTree = (bst*)malloc(sizeof(bst));
    newTree->root = NULL;
    return newTree;
}

nodeBST *createNodeBST(int key){
    nodeBST *newNode = (nodeBST*)malloc(sizeof(nodeBST));
    newNode->key = key;
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

nodeBST *findMinBST(bst *tree){
    if(tree == NULL || tree->root == NULL){
        return NULL;
    }
    nodeBST *node = tree->root;
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}

nodeBST *findMaxBST(bst *tree){
    if(tree == NULL || tree->root == NULL){
        return NULL;
    }
    nodeBST *node = tree->root;
    while(node->right != NULL){
        node = node->right;
    }
    return node;
}

nodeBST *findSuccessorBST(nodeBST *node){
    if (node->right != NULL){
        return findMinBST(node->right);
    }
    nodeBST *successor = node->parent;
    while (successor != NULL && node == successor->right){
        node = successor;
        successor = successor->parent;
    }
    return successor;
}

nodeBST *searchBST(bst *tree, int key){
    nodeBST *current = tree->root;
    while (current != NULL && current->key != key){
        if (key < current->key){
            current = current->left;
        }else{
            current = current->right;
        }
    }
    return current;
}

void insertBST(bst *tree, int key){
    nodeBST *newNode = createNodeBST(tree, key);
    nodeBST *parent = NULL;
    nodeBST *current = tree->root;

    while (current != NULL){
        parent = current;
        if(key < current->key){
            current = current->left;
        }else{
            current = current->right;
        }
    }

    newNode->parent = parent;

    if(parent == NULL){
        tree->root = newNode;
    }else if(key < parent->key){
        parent->left = newNode;
    }else{
        parent->right = newNode;
    }
}

void deleteBST(bst *tree, int key){
    nodeBST *node = searchBST(tree, key);
    if(node == NULL) 
        return;
    if(node->left == NULL && node->right == NULL){
        if(node->parent == NULL){
            tree->root = NULL;
        }else if(node == node->parent->left){
            node->parent->left = NULL;
        }else{
            node->parent->right = NULL;
        }
        free(node);
    }else if(node->left == NULL || node->right == NULL){
        nodeBST *child = (node->left != NULL) ? node->left : node->right;

        if(node->parent == NULL){
            tree->root = child;
        }else if(node == node->parent->left){
            node->parent->left = child;
        }else{
            node->parent->right = child;
        }
        child->parent = node->parent;
        free(node);
    }else{
        nodeBST *successor = findSuccessorBST(node);
        node->key = successor->key;
        deleteBST(tree, successor->key);
    }
}