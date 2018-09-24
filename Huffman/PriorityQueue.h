#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "zip.h"
#include "struct.h"

//FUNCOES
void* create_priority_queue();
void* create_node_tree(unsigned char ch, unsigned int priority);
void enqueue_node(PriorityQueue *pq, unsigned char ch, unsigned int priority);
void enqueue_daddy_node(PriorityQueue *pq, Huffman * dadd_node);
void* dequeue_node(PriorityQueue *pq);
void* is_empty(PriorityQueue *pq);
void  create_queue_array(PriorityQueue *new_queue, unsigned int str[]);

#endif
