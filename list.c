#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List* create_list() {
  
  List* L = (List*)malloc(sizeof(List));
  L->current = NULL ;
  L->size = 0;
  return L;
}

 


void* first(List *L) {
  if(L->size == 0) {
    return NULL;
  }
  L->current = 0;
  return L->data[L->current];
}


void * nextList(List * list) {
  if(L->current < L->size - 1) {
    L->current++;
    return L->data[L->current];
  }
  return NULL;
   
}



void * lastList(List * list) {

    return NULL;
}

void * prevList(List * list) {
    return NULL;
}


void pushFront(List * list, void * data) {
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}





void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}



void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}