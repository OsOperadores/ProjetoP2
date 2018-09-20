#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "PriorityQueue.h"
#include "tree.h"

//Make only one new priority queue
void* create_priority_queue()
{
  priority_queue *new_queue = (priority_queue*) malloc(sizeof(priority_queue));
  new_queue->head = NULL;
  new_queue->size = 0;
  return (priority_queue*) new_queue;
}

// Putting item on queue
void* enqueue(priority_queue *pq, Tree_Node *aux1)
{
  pq_node *new_node = (pq_node*) malloc(sizeof(pq_node));
  pq->size++;
  new_node->item = aux1;
  new_node->priority = aux1->priority;
    if ((is_empty(pq)) || (pq->head->priority >= aux1->priority)) {
      new_node->next = pq->head;
      pq->head = new_node;
      return (priority_queue*) pq;
  }
  pq_node *aux2 = pq->head;

  while(aux2->next!= NULL && aux2->next->priority < aux1->priority){
    aux2 = aux2->next;
  }
  new_node->next = aux2->next;
  aux2->next = new_node;
  return (priority_queue*) pq;
}

//Remove the last in the queue
void* dequeue(priority_queue *pq)
{
  if (is_empty(pq)) {
    printf("Priority Queue underflow");
    return NULL;
  } else {
    pq->size--;
    Tree_Node *aux = pq->head->item;
    pq->head = pq->head->next;
    return (Tree_Node*)aux;
  }
}

//Verifying that the queue is empty
void* is_empty(priority_queue *pq){
  return (pq->head == NULL) ? ((int*)0) : ((int*)1);
}

//Checking the size of the priority queue
void* size_pq(priority_queue *pq){
  return &(pq->size); //caso eu queira passar passar o valor será por exemplo: printf("%d\n",*(int*)size_pq(pq));
}

//Printing the last item queue to the first
void print_priority_queue(priority_queue *pq){
  if(!is_empty(pq)){
    printf("Não está vazia\n");
    printf("prioridade: %d ", pq->head->priority);
    printf("\n");
    pq->head = pq->head->next;
    print_priority_queue(pq);
  }
}
