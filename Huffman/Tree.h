#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "zip.h"
#include "struct.h"


void* create_tree_node();
void* create_daddy_node(Huffman *one, Huffman *two);
void* isLeaf(Huffman * tree);
void* Do_Huffman(PriorityQueue *pq);
void* is_tree_empty(Huffman* tree);
void create_hash_table(unsigned char home[][256], unsigned char current[], Huffman* tree, int status);
void print_at_home(unsigned char home[][256], unsigned char current[], unsigned char ch, int status);
void print_tree_in_file(Huffman* tree,int* size_tree, FILE* file);
void* comeback_tree(FILE* zip_File, Huffman* tree);

#endif
