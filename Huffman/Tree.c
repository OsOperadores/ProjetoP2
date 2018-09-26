#include "Tree.h"
#include "PriorityQueue.h"

struct tree{
    unsigned int size_node;
    unsigned int priority;
    unsigned char ch;
    Huffman *left;
    Huffman *right;
    Huffman *next;
};

//create one node of empty tree.
Huffman* create_tree_node(){
    Huffman * a = (Huffman*)malloc(sizeof(Huffman));
    a->left = NULL;
    a->right = NULL;
    a->next = NULL;
    a->priority = 0;
    a->size_node = 0;
    return a;
}

Huffman* create_daddy_node(Huffman *one, Huffman *two){
  Huffman *daddy_node = create_node_tree('\\', one->priority + two->priority);
  daddy_node->left = two;
  daddy_node->right = one;
  daddy_node->next = NULL;
  return daddy_node;
}

Huffman* Do_Huffman(PriorityQueue *pq){
  Huffman* daddy_node = create_tree_node();
  while(pq->head->next != NULL){

    daddy_node = create_daddy_node(dequeue(pq),dequeue(pq));
    enqueue_daddy_node(pq,daddy_node);
  }
  return pq->head;
}

int is_tree_empty(Huffman* tree){
  return (tree->size_node == 0);
}

//Checking if node of tree is a leaf.
int isLeaf(Huffman * tree){
    return ((tree->right == NULL) && (tree->left == NULL));
}

void print_at_home(unsigned char home[][256], unsigned char current[], unsigned char ch, int status){
  int a;
  for(a = 0; a < status; a++){
    home[ch][a] = current[a];
  }
  home[ch][a] = '\0';
}

void create_hash_table(unsigned char home[][256], unsigned char current[], Huffman* tree, int status){
  if(tree->left == NULL && tree->right ==NULL){
    print_at_home(home,current,tree->ch,status);
    return ;
  }
  if (tree->left != NULL) {
    current[status] = '0';
    create_hash_table(home,current,tree->left,status+1);
  }
  if (tree->right != NULL) {
    current[status] = '1';
    create_hash_table(home,current,tree->right,status+1);
  }
}

void print_tree_in_file(Huffman* tree,int* size_tree, FILE* file){
  if (isLeaf(tree)) {
    if (tree->ch == '\\' || tree->ch == '*') {
      unsigned char ch = '\\';
      (*size_tree)++;
      fwrite(&ch, sizeof(unsigned char),1,file);
    }
    (*size_tree)++;
    fwrite(&tree->ch, sizeof(unsigned char), 1, file);

    return ;
  }

  (*size_tree)++;
  fwrite(&tree->ch, sizeof(unsigned char), 1, file);
  if(tree->left != NULL){
    print_tree_in_file(tree->left, size_tree, file);
  }
  if(tree->right != NULL){
    print_tree_in_file(tree->right, size_tree, file);
  }
}

Huffman* comeback_tree(FILE* zip_File, Huffman* tree){
  unsigned char ch;
  fread(&ch,sizeof(unsigned char), 1 , zip_File);

  if(ch == '*'){
    tree = create_node_tree(ch,0);
    tree->left = comeback_tree(zip_File, tree->left);
    tree->right = comeback_tree(zip_File, tree->right);
  }
  else{
    if (ch == '\\') {
      fread(&ch,sizeof(unsigned char), 1,zip_File);
      tree = create_node_tree(ch,0);
    }
    else{
      tree = create_node_tree(ch,0);
    }
  }
  return tree;
}
