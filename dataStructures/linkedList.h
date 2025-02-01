#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct{
    int data;
    struct nodeSinglyLinearLinkedList *next;
}nodeSinglyLinearLinkedList;

typedef struct{
    nodeSinglyLinearLinkedList *head;
}singlyLinearLinkedList;

typedef struct{
    int data;
    struct nodeSinglyCircularLinkedList *next;
}nodeSinglyCircularLinkedList;

typedef struct{
    nodeSinglyCircularLinkedList *head;
}singlyCircularLinkedList;

typedef struct{
    int data;
    struct nodeDoublyLinearLinkedList *prev;
    struct nodeDoublyLinearLinkedList *next;
}nodeDoublyLinearLinkedList;

typedef struct{
    nodeDoublyLinearLinkedList *head;
    nodeDoublyLinearLinkedList *tail;
}doublyLinearLinkedList;

typedef struct{
    int data;
    struct nodeDoublyCircularLinkedList *prev;
    struct nodeDoublyCircularLinkedList *next;
}nodeDoublyCircularLinkedList;

typedef struct{
    nodeDoublyCircularLinkedList *head;
}doublyCircularLinkedList;

singlyLinearLinkedList *createSinglyLinearLinkedList();
nodeSinglyLinearLinkedList *createNodeSinglyLinearLinkedList(int);
void addToFrontSinglyLinearLinkedList(singlyLinearLinkedList*, int);
void addToRearSinglyLinearLinkedList(singlyLinearLinkedList*, int);
void deleteSinglyLinearLinkedList(singlyLinearLinkedList*, int);
void reverseSinglyLinearLinkedList(singlyLinearLinkedList*);
void printSinglyLinearLinkedList(singlyLinearLinkedList*);

singlyCircularLinkedList *createSinglyCircularLinkedList();
nodeSinglyCircularLinkedList *createNodeSinglyCircularLinkedList(int);
void addSinglyCircularLinkedList(singlyCircularLinkedList*, int);
void deleteSinglyCircularLinkedList(singlyCircularLinkedList*, int);
void printSinglyCircularLinkedList(singlyCircularLinkedList*);

doublyLinearLinkedList *createDoublyLinearLinkedList();
nodeDoublyLinearLinkedList *createNodeDoublyLinearLinkedList(int);
void addToFrontDoublyLinearLinkedList(doublyLinearLinkedList*, int);
void addToRearDoublyLinearLinkedList(doublyLinearLinkedList*, int);
void deleteDoublyLinearLinkedList(doublyLinearLinkedList*, int);
void printDoublyLinearLinkedList(doublyLinearLinkedList*);

doublyCircularLinkedList *createDoublyCircularLinkedList();
nodeDoublyCircularLinkedList *createNodeDoublyCircularLinkedList(int);
void addDoublyCircularLinkedList(doublyCircularLinkedList*, int);
void deleteDoublyCircularLinkedList(doublyCircularLinkedList*, int);
void printDoublyCircularLinkedList(doublyCircularLinkedList*);

#endif