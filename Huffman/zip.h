#ifndef ZIP_H_INCLUDED // guardas de cabeçalho, impedem inclusões cíclicas
#define ZIP_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "Tree.h"

#define Max_array 256
#define Max_string 256

typedef struct tree Huffman;

void start_hash_table(unsigned char home[][256]);
int try_open_file(FILE* file);
void priority_to_table(FILE* file, unsigned int* priority_array);
void zip_file();
void create_huffman_header(FILE* file,Huffman* tree,int* size_tree);
void print_zip_at_file(FILE* normal_file, FILE* zip_File, unsigned char home[][256], int size_tree, int* trash);
unsigned char set_bit (unsigned char c, int i);
int is_bit_i_set(unsigned char c, int i);

#endif
