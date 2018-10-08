#include "Tree.h"
#include "PriorityQueue.h"

// Struct of Huffman Tree with nodes
struct tree{
    unsigned int size_node;
    unsigned int priority;
    unsigned char ch;
    Huffman *left;
    Huffman *right;
    Huffman *next;
};

// Create one node of empty tree.
void* create_tree_node(){
    Huffman * a = (Huffman*)malloc(sizeof(Huffman));
    a->left = NULL;
    a->right = NULL;
    a->next = NULL;
    a->priority = 0;
    a->size_node = 0;
    return a;
}

// Create one node for new dad tree.
void* create_daddy_node(Huffman *one, Huffman *two){
  Huffman *daddy_node = (Huffman*)create_node_tree('*', one->priority + two->priority); // Save the dad sub-tree as "*"
  daddy_node->left = one;
  daddy_node->right = two;
  daddy_node->next = NULL;
  return daddy_node;
}

// Construct the Huffman Tree with Priority Queue
void* Do_Huffman(PriorityQueue *pq){
  Huffman* daddy_node = NULL;  //Create a new pointer for a node
  // While Priority Queue isn't empty
  while(pq->head->next != NULL){
    // Dequeue the first and second node and create a new dad for them
    daddy_node = (Huffman*)create_daddy_node((Huffman*)dequeue(pq),(Huffman*)dequeue(pq));
    // Enqueue the new dad to Priority Queue
    enqueue_daddy_node(pq,daddy_node);
  }
  //Return the root of Huffman Tree
  return pq->head;
}

// Checking if Huffman Tree is empty
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
  if(tree->left == NULL && tree->right == NULL){
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
            fwrite(&ch, sizeof(unsigned char), 1, file);
        }

        fwrite(&tree->ch, sizeof(unsigned char), 1, file);

        return;
    }

    fwrite(&tree->ch, sizeof(unsigned char), 1, file);

    if (tree->left != NULL) {
        print_tree_in_file(tree->left, size_tree, file);
    }

    if (tree->right != NULL) {
        print_tree_in_file(tree->right, size_tree, file);
    }
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int altura(Huffman *pRaiz){
   if((pRaiz == NULL) || (pRaiz->left == NULL && pRaiz->right == NULL))
       return 0;
   else
       return 1 + maior(altura(pRaiz->left), altura(pRaiz->right));
}

void print_preorder_tree(Huffman * tree){
    if(tree!=NULL){
        if((tree->ch=='*' || tree->ch=='\\'))
            printf("%c", tree->ch);
        else
            printf("[%c]", tree->ch);
        print_preorder_tree(tree->left);
        print_preorder_tree(tree->right);
    }
}

void* comeback_tree(FILE* zip_File, Huffman* tree){
  unsigned char ch;
  fread(&ch,sizeof(unsigned char), 1 , zip_File);

  if(ch == '*'){
    tree = (Huffman*)create_node_tree(ch,0);

    tree->left = (Huffman*)comeback_tree(zip_File, tree->left);
    tree->right = (Huffman*)comeback_tree(zip_File, tree->right);
  }
  else{
    if(ch == '\\'){
      fread(&ch, sizeof(unsigned char), 1, zip_File);
      tree = (Huffman*)create_node_tree(ch, 0);
    }
    else 
    tree = (Huffman*)create_node_tree(ch,0);
  }
    
  
  return tree;
}