#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct tree Huffman;
typedef struct Priority_Queue PriorityQueue;

struct tree{
    unsigned int size_node;
    unsigned int priority;
    unsigned char ch;
    Huffman *left;
    Huffman *right;
    Huffman *next;
};

struct Priority_Queue{
  Huffman *head;
  unsigned int size_node;
};


#endif
