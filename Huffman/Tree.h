/*#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED*/

#include "zip.h"

typedef struct tree Huffman;
typedef struct Priority_Queue PriorityQueue;

void* create_tree_node();
void* create_daddy_node(Huffman *one, Huffman *two);
int isLeaf(Huffman * tree);
void* Do_Huffman(PriorityQueue *pq);
int is_tree_empty(Huffman* tree);
void create_hash_table(unsigned char home[][256], unsigned char current[], Huffman* tree, int status);
void print_at_home(unsigned char home[][256], unsigned char current[], unsigned char ch, int status);
void print_tree_in_file(Huffman* tree,int* size_tree, FILE* file);
void* comeback_tree(FILE* zip_File, Huffman* tree);
void print_preorder_tree(Huffman * tree);
int maior(int a, int b);
int altura(Huffman *pRaiz);
//#endif
