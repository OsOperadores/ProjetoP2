#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

void* create_tree_node(){ //create one node of empty tree.
    Tree_Node * a = (Tree_Node*)malloc(sizeof(Tree_Node));
    a->left = NULL;
    a->right = NULL;
    a->priority = 0;
    a->isLeaf=0;
    return (Tree_Node*) a;
}

void* create_tree_node_ch(unsigned int ch){ //Create new node and inserting a char.
    Tree_Node * a = (Tree_Node*)malloc(sizeof(Tree_Node));
    a->ch = ch;
    a->left = NULL;
    a->right = NULL;
    a->isLeaf=0;
    a->priority = 0;
    return (Tree_Node*) a;
}

void* create_tree(){ //Create new tree.
    Tree *a = (Tree*)malloc(sizeof(Tree));
    a->size = 0;
    a->root = NULL;
    return (Tree*) a;
}

void* isLeaf(Tree_Node * tree){ //Checking if node of tree is a leaf
    return (int*) (tree->isLeaf); //BUG
}

void* size_tree(Tree_Node* tree){ //Counts the node size of the tree.
	if(tree==NULL)
        return (int*) 0;
      if(isLeaf(tree))
        if((tree->ch=='*' || tree->ch=='\\'))
          return (int*) (2 + size_tree(tree->left) + size_tree(tree->right)); //BUG void, motivo do 2 = o ch será um novo pai distanciando +1 no tamanho do nó
  return (int*) (1 + size_tree(tree->left) + size_tree(tree->right)); //  1 porque padrão kkk

}

void print_preorder_tree(Tree_Node * tree){ //Print the tree in pre-order at terminal
    if(tree!=NULL){
        if((tree->ch=='*' || tree->ch=='\\') && isLeaf(tree)) // Ari alterá o if - If the char type is a "*" or "\" it must print a "\" because it's a scape character
            printf("\\%c", tree->ch);
        else
            printf("%c", tree->ch);
        print_preorder_tree(tree->left);
        print_preorder_tree(tree->right);
    }
}

void print_preorder_tree_in_file(Tree_Node * tree, FILE *file){ //Print the tree in pre-order at file

    if(tree!=NULL){
        if((tree->ch=='*' || tree->ch=='\\') && isLeaf(tree)) // If the char type is a "*" or "\" it must print a "\" because it's a scape character
            fprintf(file, "\\%c", tree->ch);
        else
            fprintf(file, "%c", tree->ch);

        print_preorder_tree_in_file(tree->left, file);
        print_preorder_tree_in_file(tree->right,file);
    }

}

int main() {

  return 0;
}
