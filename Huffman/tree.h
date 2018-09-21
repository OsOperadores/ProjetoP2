#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int priority;
    int isLeaf;
    char ch;
    struct node * left;
    struct node * right;
}Tree_Node;

typedef struct tree{
    Tree_Node * root;
    int size;
}Tree;

void* create_tree_node();
void* create_tree_node_ch(unsigned int ch);
void* create_tree();
void* isLeaf(Tree_Node * tree);
void print_preorder_tree(Tree_Node * tree);
void print_preorder_tree_in_file(Tree_Node * tree, FILE *file);
void print_content_in_file(char * hash[256], FILE *arq,FILE *file);
void printf_first_bits_in_file(char first[16],FILE * file);
void* size_tree(Tree_Node* tree);
void* catch_trash_size(FILE *input_file);
void* catch_tree_size(FILE *input_file);
void* catch_tree_array(FILE *input_file, unsigned int * tree_size);
Tree_Node* fill_tree(Tree_Node * tree, unsigned int * vetor,int *atual,int tamanho);
Tree_Node* get_tree(FILE *input_file);
