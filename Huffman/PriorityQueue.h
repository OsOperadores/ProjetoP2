/*#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED*/

#include "zip.h"

typedef struct tree Huffman;

//Struct of Priority Queue
typedef struct Priority_Queue{
  Huffman *head;
  unsigned int size_node;
}PriorityQueue;


//Functions
void* create_priority_queue();
void* create_node_tree(unsigned char ch, unsigned int priority);
void enqueue_node(PriorityQueue *pq, unsigned char ch, unsigned int priority);
void enqueue_daddy_node(PriorityQueue *pq, Huffman * dadd_node);
void* dequeue(PriorityQueue *pq);
int is_empty(PriorityQueue *pq);
void  create_queue_array(PriorityQueue *new_queue, unsigned int str[]);

//#endif
