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
List * createList() {
    List * new = (List *)malloc(sizeof(List));
    //assert(new != NULL);
    new->head = NULL;
    new->tail = NULL;
    new->current = NULL;
    
    return new;
}
   


void * firstList(List * list) {
    if (list == NULL) {
        return NULL;
    }
    if (list->head == NULL) {
        return NULL;
    }
    list->current = list->head;
    return list->head->data;
    
}

void * nextList(List * list) {
    if (list == NULL) {
        return NULL;
    }
    if (list->current == NULL)
    {
      return NULL;
    }
    if (list->current->next == NULL)
    {
      return NULL;
    }
    list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) {
    if (list == NULL) {
        return NULL;
    }
    if (list->tail == NULL) {
        return NULL;
    }
    list->current = list->tail;
    return list->tail->data;

}

void * prevList(List * list) {
    if (list == NULL) {
        return NULL;
    }
    if (list->current == NULL)
    {
      return NULL;
    }
    if (list->current->prev == NULL)
    {
      return  NULL;
    }
    list->current = list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {
    if (list == NULL) {
        return;
    }  
    Node *nuevoNodo = createNode(data);
  
    if (list->head == NULL)
    {
      list->head = nuevoNodo;
      list->tail = nuevoNodo;
    }
  else{
    nuevoNodo->next = list->head;
    list->head->prev = nuevoNodo;
    list->head= nuevoNodo;
    
  }

  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node *nuevoNodo = createNode(data);
    if (list == NULL)
    {
    pushFront(list, data);
    }
  else{
    nuevoNodo->next = list->current->prev;
    nuevoNodo->prev = list->current;
    list->current->prev = nuevoNodo;
    
  }
  if (list->current->next ==NULL)
  {
    list->tail = nuevoNodo;
    
  }
  list->current->next = nuevoNodo;
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
    if (list == NULL || list->current == NULL) {
        return NULL; 

    Node * current = list->current;
    void * data = current->data;

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    } else {
        list->tail = current->prev;
    }

    list->current = current->prev;

    free(current);

    return data;
}


void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}