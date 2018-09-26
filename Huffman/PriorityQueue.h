/*#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED*/

#include "zip.h"

typedef struct tree Huffman;

typedef struct Priority_Queue{
  Huffman *head;
  unsigned int size_node;
}PriorityQueue;


//FUNCOES
PriorityQueue* create_priority_queue();
Huffman* create_node_tree(unsigned char ch, unsigned int priority);
void enqueue_node(PriorityQueue *pq, unsigned char ch, unsigned int priority);
void enqueue_daddy_node(PriorityQueue *pq, Huffman * dadd_node);
Huffman* dequeue(PriorityQueue *pq);
int is_empty(PriorityQueue *pq);
void  create_queue_array(PriorityQueue *new_queue, unsigned int str[]);

//#endif
