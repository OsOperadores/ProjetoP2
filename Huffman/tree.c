#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

//create one node of empty tree.
void* create_tree_node(){
    Tree_Node * a = (Tree_Node*)malloc(sizeof(Tree_Node));
    a->left = NULL;
    a->right = NULL;
    a->priority = 0;
    a->isLeaf=0;
    return (Tree_Node*) a;
}

//Create new node and inserting a char.
void* create_tree_node_ch(unsigned int ch){
    Tree_Node * a = (Tree_Node*)malloc(sizeof(Tree_Node));
    a->ch = ch;
    a->left = NULL;
    a->right = NULL;
    a->isLeaf=0;
    a->priority = 0;
    return (Tree_Node*) a;
}

//Create new tree.
void* create_tree(){
    Tree *a = (Tree*)malloc(sizeof(Tree));
    a->size = 0;
    a->root = NULL;
    return (Tree*) a;
}

//Checking if node of tree is a leaf.
void* isLeaf(Tree_Node * tree){
    return (&(tree->isLeaf)); //BUG resolved, if I want to pass the value will be for example: printf("%d\n",*(int*)isLeaf(log));
}

//Counts the node size of the tree.
void* size_tree(Tree_Node* tree){
	if(tree==NULL)
        return (int*) 0;
      if(isLeaf(tree))
        if((tree->ch=='*' || tree->ch=='\\'))
          return (int*) (2 + size_tree(tree->left) + size_tree(tree->right)); //BUGcast, motivo do 2 = o ch será um novo pai distanciando +1 no tamanho do nó
  return (int*) (1 + size_tree(tree->left) + size_tree(tree->right)); //BUGcast,  1 porque padrão kkk

}

//Print the tree in pre-order at terminal.
void print_preorder_tree(Tree_Node * tree){
    if(tree!=NULL){
        if((tree->ch=='*' || tree->ch=='\\') && isLeaf(tree)) // Ari alterá o if - If the char type is a "*" or "\" it must print a "\" because it's a scape character
            printf("\\%c", tree->ch);
        else
            printf("%c", tree->ch);
        print_preorder_tree(tree->left);
        print_preorder_tree(tree->right);
    }
}

//Print the tree in pre-order at file.
void print_preorder_tree_in_file(Tree_Node * tree, FILE *file){

    if(tree!=NULL){
        //If the char type is a "*" or "\" it must print a "\" because it's a scape character.
        if((tree->ch=='*' || tree->ch=='\\') && isLeaf(tree))
            fprintf(file, "\\%c", tree->ch);
        else
            fprintf(file, "%c", tree->ch);

        print_preorder_tree_in_file(tree->left, file);
        print_preorder_tree_in_file(tree->right,file);
    }

}

//Print the first bytes referring to the trash size and size of the tree.
void printf_first_bits_in_file(char begin[16],FILE * file){

    char aux[8]; //Creates an auxiliary to store the 8 bits.
    strncpy (aux,begin,8);//Copy the first 8 bits of the begin string to the auxiliary.

    /*The function strtol converts string to a long integer,
        parameters: it receives a pointer to string, a pointer pointer to the string,
        and the base that the string is, and transforms to decimal.*/
    long long int trash_header = strtol(aux,NULL,2);

    /*Use the function strtol to get the size of the Huffman Tree in header
        in the last 8 bits of the string begin.*/
    long long int tree_size_header = strtol(begin+8,NULL,2);

    //Converts the bytes to char.
    unsigned char trash_char=(int)trash_header , tree_size_char=(int)tree_size_header;

    //Print on file.
    fprintf(file,"%c%c", trash_char,tree_size_char);
}

void* catch_trash_size(FILE *input_file) { // Take the size of the garbage in the first byte.

	unsigned int trash_size = 0;
	unsigned int first_byte;

  /*The function fseek sets the file position of the stream to the given offset,
      parameters: the pointer to a FILE, the number of bytes to offset,
      the position from where offset is added(in this case at the beginning of file).*/
  fseek(input_file, 0, SEEK_SET);

	first_byte = getc(input_file);

  /*Following the header, with 3 bits for the size of trash.*/
	trash_size = (unsigned int)(first_byte >> (5));

  return (unsigned int)(trash_size); //BUGcast
}

// Get the size of the tree by joining the first two bytes disregarding the first three bits.
void* catch_tree_size(FILE *input_file) {
	unsigned int tree_size;
	unsigned char first_byte;
	unsigned int second_byte;

	fseek(input_file, 0, SEEK_SET); // Back to the beginning of the file.

	// Receives the first two bytes of the file
	first_byte = getc(input_file);
	second_byte = getc(input_file);

	// Clears the first three bits of the first byte, following the header.
	first_byte = (first_byte << 3);
	first_byte = (first_byte >> 3);

	/*The size of the tree is the union between
      the last 5 bits of the first byte and the second byte.*/
	tree_size = ((first_byte << 8) | second_byte);

	return (unsigned int*)(tree_size);//BUGcast
}

//Read the tree and stores in array.
void* catch_tree_array(FILE *input_file, unsigned int * tree_size) {

  unsigned int i;

	//Creates an array with the size of the tree.
	unsigned int *tree_array;

  //Size of the tree including the nodes '\' and '*'.
  tree_array = (unsigned int *)malloc(sizeof(unsigned int)*(*tree_size));

	/*Goes to the third byte of the file to receive the characters
    (the third byte is the first byte of the tree).             */
	fseek(input_file, 2, 0);

	//Receive the characters in sequence tree_size times.
	for (i = 0; i < (*tree_size); i++) {
	   tree_array[i] = getc(input_file);
  }

  for (i = 0; i < (*tree_size); i++) {
      printf("%c",tree_array[i]);
  }

  //Returns the address for the created array.
	return (tree_array); //BUGcast (unsigned int*).
}
