#include <stdlib.h>
#include "PriorityQueue.h"
#include "Tree.h"

//Struct of Huffman Tree with nodes
struct tree{
    unsigned int size_node; // Size of node
    unsigned int priority;  // Frequency of char in the text
    unsigned char ch;       // Character
    Huffman *left;
    Huffman *right;
    Huffman *next;
};

//Create only one Priority Pointer for a Queue
void* create_priority_queue()
{
  PriorityQueue *new_queue = (PriorityQueue*) calloc(1,sizeof(PriorityQueue));
  new_queue->size_node = 0;
  new_queue->head = NULL;
  return new_queue;
}

//Create Node Huffman Tree
void* create_node_tree(unsigned char ch, unsigned int priority){
  Huffman* node = (Huffman*) calloc(1,sizeof(Huffman));
  node->priority = priority;
  node->ch = ch;
  node->left = node->right = node->next = NULL;
  return node;
}

//Checking if the Priority Queue is empty
int is_empty(PriorityQueue *pq){
  return (pq->head == NULL);
}

// Put item in the Priority Queue
void enqueue_node(PriorityQueue *pq, unsigned char ch, unsigned int priority){
  Huffman *new_node = create_node_tree(ch,priority);

    if (is_empty(pq) || pq->head->priority >= priority) {
      new_node->next = pq->head;
      pq->head = new_node;

  } else {
      Huffman *current = pq->head;
    while (current->next != NULL && current->next->priority < priority) {
      current = current->next;
    }
      new_node->next = current->next;
      current->next = new_node;
  }
  pq->size_node++;
}

// Enqueue a new dad(like a tree) for the Priority Queue
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

// Withdraw the last in the Priority Queue
void* dequeue(PriorityQueue *pq){

  if (!(is_empty(pq))) {
    Huffman* node = pq->head;
    pq->head = pq->head->next;
    node->next = NULL;
    return node;
  }
  return NULL;
}

// Create Queue with the type Array
void  create_queue_array(PriorityQueue *new_queue, unsigned int str[]){
  int a;
  for(a=0; a < 256; a++){
    if(str[a] != 0){
      enqueue_node(new_queue,a,str[a]);
    }
  }
}
