#include <stdio.h>
#include <string.h>
#include "zip.h"
#include "Tree.h"

struct tree{
    unsigned int size_node;
    unsigned int priority;
    unsigned char ch;
    Huffman *left;
    Huffman *right;
    Huffman *next;
};

int checking_file(char *name){

  char str[] = ".huff";
  int a, b = 0;

  for(a = strlen(name) - 5; a < strlen(name); a++, b++){
    if(name[a]!= str[b]){
      printf("[%c] ", name[a]);
      printf("[%c] ", str[b]);
      return 0;
    }
  }
  return 1;
}

void comeback_original(FILE* zip_file, FILE* o_original, Huffman* tree, int size_trash){

  Huffman* tree_temp;
  unsigned char ch, ch_temp;
  short int a;

  tree_temp = tree;

  fread(&ch, sizeof(unsigned char), 1, zip_file);
  ch_temp = ch;

  while(fread(&ch, sizeof(unsigned char), 1, zip_file) == 1){

    for(a = 7; a >= 0; a--){
      if (isLeaf(tree_temp)) {
        fwrite(&(tree_temp->ch), sizeof(unsigned char), 1, o_original);
        tree_temp = tree;
      }
      if(!(is_bit_i_set(ch_temp,a))){
        tree_temp = tree_temp->left;
      }
      else{
        tree_temp = tree_temp->right;
      }
    }
    ch_temp = ch;
  }

  for( a = 7; a >= size_trash - 1; a--){
    if(isLeaf(tree_temp)){
      fwrite(&(tree_temp->ch), sizeof(unsigned char), 1, o_original);
      tree_temp = tree;
    }
    if(!(is_bit_i_set(ch_temp, a))){
      tree_temp = tree_temp->left;
    }
    else{
      tree_temp = tree_temp->right;
    }
  }
}

void unzip_file(){

  FILE* zip_file = NULL;
  FILE* unzip_file = NULL;

  char zip_file_name[Max_string];
  char unzip_file_name[Max_string];

  printf(" Enter the name of the compressed file.\n\n Like this: filename.huff\n > ");
  scanf("%[^\n]s", zip_file_name);
  getchar();
  //printf("[%s]\n", zip_file_name);
  zip_file = fopen(zip_file_name, "rb");

  while((!try_open_file(zip_file)) || (!checking_file(zip_file_name))){
    printf("Error opening file!\n\n");

    if(!checking_file(zip_file_name)){
      printf(" The file you entered does not have a .huff extension.\nEnter a valid file.\n\n");
    }
    printf(" Enter the name of the compressed file.\n\n Like this: filename.huff\n > ");
       scanf("%[^\n]s", zip_file_name);
       getchar();

       zip_file = fopen(zip_file_name, "rb");

  }

  printf("\n Enter the name of the output file (with the extension):\n > ");
  scanf("%[^\n]s", unzip_file_name);
  getchar();

  printf(" Please wait ... the file is being unzipped ...\n\n");

  unsigned char size_trash;
  unsigned char size_tree;

  int* tree_temp = (int*) malloc(sizeof(int));
  int trash_temp = 0;

  fread(&size_trash, sizeof(unsigned char), 1, zip_file);
  fread(&size_tree, sizeof(unsigned char), 1, zip_file);

  size_trash = (size_trash >> 5);

  trash_temp = size_trash;

  Huffman* tree = (Huffman*)create_tree_node();
  tree = (Huffman*)comeback_tree(zip_file, tree);

  //print_preorder_tree(tree);
  (*tree_temp) = altura(tree);
  unzip_file = fopen(unzip_file_name, "wb");
  comeback_original( zip_file, unzip_file, tree, trash_temp);

  fclose(zip_file);
  fclose(unzip_file);

  printf("\n %s created, unzipped from %s\n\n", unzip_file_name, zip_file_name);
  printf("Size of Tree: %d  ////", (*tree_temp));
  printf("  Size of Trash: %d\n", trash_temp);

}
