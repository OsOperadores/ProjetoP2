/*#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED*/

#include "zip.h"

typedef struct tree Huffman;
typedef struct Priority_Queue PriorityQueue;

Huffman* create_tree_node();
Huffman* create_daddy_node(Huffman *one, Huffman *two);
int isLeaf(Huffman * tree);
Huffman* Do_Huffman(PriorityQueue *pq);
int is_tree_empty(Huffman* tree);
void create_hash_table(unsigned char home[][256], unsigned char current[], Huffman* tree, int status);
void print_at_home(unsigned char home[][256], unsigned char current[], unsigned char ch, int status);
void print_tree_in_file(Huffman* tree,int* size_tree, FILE* file);
Huffman* comeback_tree(FILE* zip_File, Huffman* tree);

//#endif
