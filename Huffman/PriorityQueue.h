#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct pq_node {
  Tree_Node * item;
  int priority;
  struct pq_node *next;
}pq_node;

typedef struct priority_queue {
  pq_node * head;
  int size;
}priority_queue;

//FUNCOES
void* create_priority_queue();
void* enqueue(priority_queue *pq, Tree_Node * aux);
void* dequeue(priority_queue *pq);
void* is_empty(priority_queue *pq);
void print_priority_queue(priority_queue *pq);
void* size_pq(priority_queue *pq);
