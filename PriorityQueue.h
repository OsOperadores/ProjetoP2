#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int item;
  int priority;
  struct node *next;
}node;

typedef struct priority_queue {
  node *head;
}priority_queue;

//FUNCOES
void* create_priority_queue();
void enqueue(priority_queue *pq, int i, int p);
void* dequeue(priority_queue *pq);
//int maximum(priority_queue *pq);
void* is_empty(priority_queue *pq);
void print_priority_queue(priority_queue *pq);
