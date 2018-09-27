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
  int a;

  tree_temp = tree;

  fread(&ch, sizeof(unsigned char), 1, zip_file);
  ch_temp = ch;

  while(fread(&ch, sizeof(unsigned char), 1, zip_file) == 1){

    for(a = 8; a > 0; a--){
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

  for( a = 8; a > size_trash - 1; a--){
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

  printf(" Digite o nome do arquivo compactado.\n\n Exemplo: arquivo.huff\n > ");
  scanf("%[^\n]s", zip_file_name);
  getchar();
  //printf("[%s]\n", zip_file_name);
  zip_file = fopen(zip_file_name, "rb");

  while((!try_open_file(zip_file)) || (!checking_file(zip_file_name))){
    printf(" Erro na abertura do arquivo!\n\n");

    if(!checking_file(zip_file_name)){
      printf(" O arquivo digitado não possui extensão .huff\nEntre com um arquivo válido.\n\n");
    }
    printf(" Digite o nome do arquivo compactado:\n\n Exemplo: arquivo.huff\n > ");
       scanf("%[^\n]s", zip_file_name);
       getchar();

       zip_file = fopen(zip_file_name, "rb");

  }

  printf("\n Digite o nome do arquivo de saída:\n > ");
  scanf("%[^\n]s", unzip_file_name);
  getchar();

  printf(" Aguarde... o arquivo está sendo descompactado... \n\n");

  unsigned char size_trash;
  unsigned char size_tree;

  int tree_temp = 0;
  int trash_temp = 0;

  fread(&size_trash, sizeof(unsigned char), 1, zip_file);
  fread(&size_tree, sizeof(unsigned char), 1, zip_file);

  size_trash = (size_trash >> 5);

  trash_temp = size_trash;
  tree_temp = size_tree;
  //printf("Trash_temp: %d\n", trash_temp);
  //printf("Tree_temp: %d\n", tree_temp);

  Huffman* tree = create_tree_node();
  tree = comeback_tree(zip_file, tree);

  unzip_file = fopen(unzip_file_name, "wb");
  comeback_original( zip_file, unzip_file, tree, trash_temp);

  fclose(zip_file);
  fclose(unzip_file);

  printf(" Arquivo descompactado!\n\n");

}
