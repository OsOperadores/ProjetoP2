#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "Tree.h"
#include "PriorityQueue.h"
#include "struct.h"

//criando somente uma fila nova
void* create_priority_queue()
{
  PriorityQueue *new_queue = (PriorityQueue*) calloc(1,sizeof(PriorityQueue));
  new_queue->size_node = 0;
  new_queue->head = NULL;
  return (void*) new_queue;
}

void* create_node_tree(unsigned char ch, unsigned int priority){
  Huffman* node = (Huffman*) calloc(1,sizeof(Huffman));
  node->priority = priority;
  node->ch = ch;
  node->left = node->right = node->next = NULL;
  return (void*) node;
}

// Colocar item na fila
void enqueue_node(PriorityQueue *pq, unsigned char ch, unsigned int priority){
  Huffman *new_node = create_node_tree(ch,priority);

    if ((is_empty(pq)) || (pq->head->priority) >= priority) {
      new_node->next = pq->head;
      pq->head = new_node;

  } else {
      Huffman *current = pq->head;
    while ((current->next != NULL) && (current->next->priority < priority)) {
      current = current->next;
    }
      new_node->next = current->next;
      current->next = new_node;
  }
  pq->size_node++;
}

void enqueue_daddy_node(PriorityQueue *pq, Huffman * daddy_node){
  if(is_empty(pq) || pq->head->priority >= daddy_node->priority){
    daddy_node->next = pq->head;
    pq->head = daddy_node;
  }
  else{
    Huffman* current = pq->head;
    while(current->next != NULL && current->next->priority < daddy_node->priority){
      current = current->next;
    }
    daddy_node->next = current->next;
    current->next = daddy_node;
  }
  pq->size_node++;
}

//retirar o ultimo da fila
void* dequeue(PriorityQueue *pq){

  if (!(is_empty(pq))) {
    Huffman* node = pq->head;
    pq->head = pq->head->next;
    node->next = NULL;
    return (void*) node;
  }
  return (void*)NULL;
}

//Verificando se a fila está vazia
void* is_empty(PriorityQueue *pq){
  return (pq->head == NULL) ? ((void*)1) : ((void*)0);
}

void  create_queue_array(PriorityQueue *new_queue, unsigned int str[]){
  int a;
  for(a=0; a < 256; a++){
    if(str[a] != 0){
      enqueue_node(new_queue,a,str[a]);
    }
  }
}
