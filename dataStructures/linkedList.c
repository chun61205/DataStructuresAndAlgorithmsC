#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

singlyLinearLinkedList *createSinglyLinearLinkedList(){
    singlyLinearLinkedList *list = (singlyLinearLinkedList*)malloc(sizeof(singlyLinearLinkedList));
    if(!list){
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    return list;
}

nodeSinglyLinearLinkedList *createNodeSinglyLinearLinkedList(int data){
    nodeSinglyLinearLinkedList *newNode = (nodeSinglyLinearLinkedList*)malloc(sizeof(nodeSinglyLinearLinkedList));
    if(!newNode){
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addToFrontSinglyLinearLinkedList(singlyLinearLinkedList *list, int data){
    nodeSinglyLinearLinkedList *newNode = createNodeSinglyLinearLinkedList(data);
    newNode->next = list->head;
    list->head = newNode;
}

void addToRearSinglyLinearLinkedList(singlyLinearLinkedList *list, int data){
    nodeSinglyLinearLinkedList *newNode = createNodeSinglyLinearLinkedList(data);
    if(!list->head){
        list->head = newNode;
        return;
    }
    nodeSinglyLinearLinkedList *current = list->head;
    while(current->next){
        current = current->next;
    }
    current->next = newNode;
}

void deleteSinglyLinearLinkedList(singlyLinearLinkedList *list, int data) {
    if(!list->head){
        return;
    }

    nodeSinglyLinearLinkedList **current = &(list->head);
    while(*current && (*current)->data != data){
        current = &(*current)->next;
    }

    if(!*current){
        return;
    }

    nodeSinglyLinearLinkedList *target = *current;
    *current = (*current)->next;
    free(target);
}

void reverseSinglyLinearLinkedList(singlyLinearLinkedList *list){
    nodeSinglyLinearLinkedList *prev = NULL;
    nodeSinglyLinearLinkedList *current = list->head;
    nodeSinglyLinearLinkedList *next = NULL;

    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

void printSinglyLinearLinkedList(singlyLinearLinkedList *list){
    nodeSinglyLinearLinkedList *current = list->head;
    while(current){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

singlyCircularLinkedList *createSinglyCircularLinkedList(){
    singlyCircularLinkedList *list = (SinglyCircularLinkedList*)malloc(sizeof(SinglyCircularLinkedList));
    if(!list){
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    list->head = NULL;
    return list;
}

nodeSinglyCircularLinkedList *createNodeSinglyCircularLinkedList(int data){
    nodeSinglyCircularLinkedList *newNode = (nodeSinglyCircularLinkedList*)malloc(sizeof(nodeSinglyCircularLinkedList));
    if(!newNode){
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addSinglyCircularLinkedList(singlyCircularLinkedList *list, int data){
    nodeSinglyCircularLinkedList *newNode = createNode(data);

    if(!list->head){
        list->head = newNode;
        newNode->next = newNode;
    }else{
        newNode->next = list->head->next;
        list->head->next = newNode;
        list->head = newNode;
    }
}

void deleteSinglyCircularLinkedList(singlyCircularLinkedList *list, int data){
    if(!list->head){
        return;
    }

    nodeSinglyCircularLinkedList *current = list->head->next;
    nodeSinglyCircularLinkedList *prev = list->head;

    do{
        if(current->data == data){
            if(current == list->head && current->next == list->head){
                list->head = NULL;
            }else{
                if(current == list->head){
                    list->head = prev;
                }
                prev->next = current->next;
            }
            free(current);
            printf("Deleted node with data %d\n", data);
            return;
        }
        prev = current;
        current = current->next;
    }while (current != list->head->next);
}

void printSinglyCircularLinkedList(singlyCircularLinkedList *list) {
    if (!list->head) {
        printf("\n");
        return;
    }

    nodeSinglyCircularLinkedList *current = list->head->next;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != list->head->next);
    printf("(head)\n");
}

doublyLinearLinkedList *createDoublyLinearLinkedList(){
    doublyLinearLinkedList *list = (doublyLinearLinkedList*)malloc(sizeof(doublyLinearLinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

nodeDoublyLinearLinkedList *createNodeDoublyLinearLinkedList(int data){
    nodeDoublyLinearLinkedList *newNode = (nodeDoublyLinearLinkedList*)malloc(sizeof(nodeDoublyLinearLinkedList));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addToFrontDoublyLinearLinkedList(doublyLinearLinkedList *list, int data){
    nodeDoublyLinearLinkedList *newNode = createNode(data);

    if(!list->head){
        list->head = list->tail = newNode;
    }else{
        newNode->next = list->head;
        list->head->prev = newNode;
        list->head = newNode;
    }
}

void addToRearDoublyLinearLinkedList(doublyLinearLinkedList *list, int data){
    nodeDoublyLinearLinkedList *newNode = createNode(data);

    if(!list->tail){
        list->head = list->tail = newNode;
    }else{
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void deleteDoublyLinearLinkedList(doublyLinearLinkedList *list, int data){
    if(!list->head){
        return;
    }

    nodeDoublyLinearLinkedList *current = list->head;

    while(current && current->data != data){
        current = current->next;
    }

    if(!current){
        return;
    }

    if(current == list->head && current == list->tail){
        list->head = list->tail = NULL;
    }else if(current == list->head){
        list->head = current->next;
        list->head->prev = NULL;
    }else if(current == list->tail){
        list->tail = current->prev;
        list->tail->next = NULL;
    }else{
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    free(current);
}

void printDoublyLinearLinkedList(doublyLinearLinkedList *list){
    if(!list->head){
        printf("\n");
        return;
    }

    print("NULL <->");

    nodeDoublyLinearLinkedList *current = list->head;
    while(current){
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

doublyCircularLinkedList *createDoublyCircularLinkedList(){
    doublyCircularLinkedList *list = (doublyCircularLinkedList*)malloc(sizeof(doublyCircularLinkedList));
    list->head = NULL;
    return list;
}

nodeDoublyCircularLinkedList *createNodeDoublyCircularLinkedList(int data){
    nodeDoublyCircularLinkedList *newNode = (nodeDoublyCircularLinkedList*)malloc(sizeof(nodeDoublyCircularLinkedList));
    newNode->data = data;
    newNode->prev = newNode->next = newNode;
    return newNode;
}

void addDoublyCircularLinkedList(doublyCircularLinkedList *list, int data){
    nodeDoublyCircularLinkedList *newNode = createNode(data);
    if(list->head == NULL){
        list->head = newNode;
        return;
    }
    nodeDoublyCircularLinkedList *tail = list->head->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = list->head;
    list->head->prev = newNode;
}

void deleteDoublyCircularLinkedList(doublyCircularLinkedList *list, int data){
    if(list->head == NULL)
        return;

    nodeDoublyCircularLinkedList *current = list->head;
    do{
        if(current->data == data){
            if(current->next == current){
                free(current);
                list->head = NULL;
                return;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            if (list->head == current) list->head = current->next;
            free(current);
            return;
        }
        current = current->next;
    }while (current != list->head);
}

void printDoublyCircularLinkedList(doublyCircularLinkedList *list){
    if(list->head == NULL){
        printf("\n");
        return;
    }
    nodeDoublyCircularLinkedList *current = list->head;
    do{
        printf("%d <-> ", current->data);
        current = current->next;
    }while(current != list->head);
    printf("(head)\n");
}