#include <stdio.h>
#include <stdlib.h>
#include "red_black_tree.h"

rbt *createRBT(){
    rbt *tree = (rbt*)malloc(sizeof(rbt));
    nodeRBT *nil = (nodeRBT*)malloc(sizeof(nodeRBT));
    
    nil->color = BLACK;
    nil->left = NULL;
    nil->right = NULL;
    nil->parent = NULL;

    tree->root = nil;

    return tree;
}
nodeRBT *createNodeRBT(rbt *tree, int data){
    nodeRBT *node = (nodeRBT*)malloc(sizeof(nodeRBT));
    node->data = data;
    node->color = RED;
    node->left = tree->nil;
    node->right = tree->nil;
    node->parent = NULL;
    return node;
}
void leftRotateRBT(rbt *tree, nodeRBT *x){
    rbtNode *y = x->right;
    x->right = y->left;
    if (y->left != tree->nil)
        y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == NULL)
        tree->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    
    y->left = x;
    x->parent = y;
}
void rightRotateRBT(rbt *tree, nodeRBT *y){
    nodeRBT *x = y->left;
    y->left = x->right;
    if (x->right != tree->nil)
        x->right->parent = y;
    
    x->parent = y->parent;
    if (y->parent == NULL)
        tree->root = x;
    else if (y == y->parent->right)
        y->parent->right = x;
    else
        y->parent->left = x;
    
    x->right = y;
    y->parent = x;
}
void insertRBT(rbt *tree, int data){
    // Node creation
    nodeRBT *newNode = createNode(data, tree);
    nodeRBT *parent = NULL;
    nodeRBT *current = tree->root;

    // Node insertion in binary search trees
    while(current != tree->nil){
        parent = current;
        if (newNode->data < current->data)
            current = current->left;
        else
            current = current->right;
    }
    newNode->parent = parent;

    if(parent == NULL){
        tree->root = newNode;
    }else if(newNode->data < parent->data){
        parent->left = newNode;
    }else{
        parent->right = newNode;
    }

    // Fixup
    while(newNode != tree->root && newNode->parent->color == RED){
        if(newNode->parent == newNode->parent->parent->left){
            nodeRBT *uncle = newNode->parent->parent->right;

            // Case 1: Uncle is red
            if(uncle->color == RED){
                newNode->parent->color = BLACK;
                uncle->color = BLACK;
                newNode->parent->parent->color = RED; 
                newNode = newNode->parent->parent;
            }else{
                // Case 2: New node is a right child
                if(newNode == newNode->parent->right){
                    newNode = newNode->parent;
                    leftRotateRBT(tree, newNode);
                }
                
                // Case 3: New node is a left child
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                rightRotateRBT(tree, newNode->parent->parent);
            }
        }else{
            nodeRBT *uncle = newNode->parent->parent->left;

            // Case 1: Uncle is red
            if(uncle->color == RED){
                newNode->parent->color = BLACK;
                uncle->color = BLACK;
                newNode->parent->parent->color = RED;
                newNode = newNode->parent->parent;
            }else{
                // Case 2: New node is a left child
                if(newNode == newNode->parent->left){
                    newNode = newNode->parent;
                    rightRotateRBT(tree, newNode);
                }

                // Case 3: New node is a right child
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                leftRotateRBT(tree, newNode->parent->parent);
            }
        }
    }
    tree->root->color = BLACK;
}
void deleteRBT(rbt *tree, int data){
    // Search for the target node
    nodeRBT *target = searchRBT(data);
    if (target == tree->nil) {
        fprintf(stderr, "The target node is not found.\n");
        exit(EXIT_FAILURE);
    }

    nodeRBT *curr = tree->nil, *child = tree->nil;

    if(target->left == tree->nil || target->right == tree->nil){
        curr = target;
    }else{
        curr = target->right;

        while(curr->left != tree->nil){
            curr = curr->left;
        }
    }

    if(curr->left != tree->nil){
        child = curr->left;
    }else{
        child = curr->right;
    }

    child->parent = curr->parent;

    if(curr->parent == tree->nil){
        tree = child;
    }else if(curr == curr->parent->left){
        curr->parent->left = child;
    }else{
        curr->parent->right = child;
    }

    if(curr != target){
        target->data = curr->data;
    }
    // Fixup
    if(curr->color == BLACK){
        while(child != tree->root && child->color == BLACK){
            if(child == child->parent->left){  
                nodeRBT *childSibling = child->parent->right;
                // Case 1: The childSibling is red
                if(childSibling->color == RED){
                    childSibling->color = BLACK;
                    child->parent->color = RED;
                    leftRotateRBT(child->parent);
                    childSibling = child->parent->right;
                }
                // Case 2/3/4: The childSibling is black
                // Case 2: Two children of the childSibling are both black 
                if(childSibling->left->color == BLACK && childSibling->right->color == BLACK){
                    childSibling->color = RED;
                    child = child->parent;
                }else{
                    // Case 3: The right child of the childSibling is black and the left child of the childSibling is red
                    if(childSibling->right->color == BLACK){
                        childSibling->left->color = BLACK;
                        childSibling->color = RED;
                        rightRotateRBT(childSibling);
                        childSibling = current->parent->right;
                    }
                    // Case 4: The right child of the childSibling is red and the left child of the childSibling is black
                    childSibling->color = current->parent->color;
                    current->parent->color = BLACK;
                    childSibling->right->color = BLACK;
                    leftRotateRBT(current->parent);
                    child = tree->root;
                }
            }else{  
                nodeRBT *childSibling = child->parent->left;
                // Case 1: The childSibling is red
                if(childSibling->color == RED){
                    childSibling->color = BLACK;
                    child->parent->color = RED;
                    rightRotateRBT(child->parent);
                    childSibling = child->parent->left;
                }
                // Case 2/3/4: The childSibling of the child is black
                // Case 2: Two children of the childSibling are both black 
                if(childSibling->left->color == BLACK && childSibling->right->color == BLACK) {
                    childSibling->color = RED;
                    child = child->parent;
                }else{
                    // Case 3: The right child of the childSibling is black and the left child of the childSibling is red
                    if(childSibling->left->color == BLACK){
                        childSibling->right->color = BLACK;
                        childSibling->color = RED;
                        leftRotateRBT(childSibling);
                        childSibling = child->parent->left;
                    }
                    // Case 4: The right child of the childSibling is red and the left child of the childSibling is black
                    childSibling->color = current->parent->color;
                    current->parent->color = BLACK;
                    childSibling->left->color = BLACK;
                    rightRotateRBT(child->parent);
                    child = tree->root;
                }
            }
        }
        child->color = BLACK;
    }
}
nodeRBT *searchRBT(rbt *tree, int data){
    nodeRBT *current = tree->root;

    while(current != tree->nil && current->data != data){
        if(data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    return current;
}