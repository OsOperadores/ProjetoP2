#include <string.h>
#include "zip.h"
#include "Tree.h"
#include "PriorityQueue.h"

void start_hash_table(unsigned char home[][256]){
  int a;
  for(a = 0; a < 256; a++){
    home[a][0] = '\0';
  }
}

int try_open_file(FILE* file){
  if(file == NULL){
    printf("I can't find the file\n");
    return 0;
  }
  return 1;
}

void priority_to_table(FILE* file, unsigned int* priority_array){
  unsigned char ch;
  while (fread(&ch,sizeof(unsigned char), 1, file) == 1) {
    priority_array[ch]++;
  }
  return ;
}

void create_huffman_header(FILE* file, Huffman* tree, int* size_tree){
  unsigned char ch = 0;
  fwrite(&ch, sizeof(unsigned char), 1, file);
  fwrite(&ch, sizeof(unsigned char), 1, file);

  print_tree_in_file(tree,size_tree, file);
}

unsigned char set_bit (unsigned char c, int i){
  return (c | (1 << (7-i)));
}
int is_bit_i_set(unsigned char c, int i){
  return (c & (1 << i));
}

void print_zip_at_file(FILE* normal_file, FILE* zip_File, unsigned char home[][256], int size_tree, int* trash){

  unsigned char ch = 0; // ch to print on file(00000000)
  unsigned char ch_help; // ch_help to read the zip_file
  int index = 0; // Control the position of bits to byte
  int str_index = 0; // Control a position of characters that have at hash table

  rewind(normal_file);  // Comeback to the initial position of file
  while(fread(&ch_help,sizeof(unsigned char),1,normal_file) == 1){
      str_index = 0;
      while(home[ch_help][str_index] != '\0'){

          if(index == 8){ // If byte is complete, write on zip_File
            fwrite(&ch, sizeof(unsigned char), 1, zip_File);
            ch = 0; // Reset byte
            index = 0; // Reset bits controller
          }

          if (home[ch_help][str_index] == '1') {
                ch = set_bit(ch,index); // Set the bit to byte
          }
          str_index++;
          index++;
    }
  }

  fwrite(&ch, sizeof(unsigned char), 1, zip_File); // Write last byte

  unsigned char size_trash = ((8 - index) << 5); // Get the size of trash
  unsigned char tree_size_to_file = size_tree; // Size of Huffman Tree in string

  rewind(zip_File);
  fwrite(&size_trash, sizeof(unsigned char), 1, zip_File); // Write the size of trash on file
  fwrite(&tree_size_to_file, sizeof(unsigned char), 1, zip_File); // Write the size of Huffman tree on file
  size_trash = (8 - index) >> 5;
  (*trash) = size_trash;
  
  return ;
}

void zip_file(){

  FILE* normal_file = NULL; // File that we want to compress
  FILE* zip_file = NULL;    // File compressed

  char normal_file_name[Max_string];  // String with the name of normal file
  char zip_file_name[Max_string];     // String with the name of compressed file
  char *pch = NULL;

  int i;

  unsigned int priority_array[Max_array]; // Array of normal file with priority of bytes

  for(i=0; i < Max_array; i++){
    priority_array[i] = 0;
  }
  printf("Enter the name of the file you want to compress (with the extension):\n\nLike this: example.txt\n > ");
  scanf("%[^\n]s", normal_file_name);
  getchar();

  normal_file = fopen(normal_file_name, "rb");

  while(!try_open_file(normal_file)){
    getchar();    //Clear buffer

    printf("Enter the name of the file you want to compress (with the extension):\n\n");
    printf("Like this: example.txt\n > ");
    scanf("%[^\n]s", normal_file_name);

    normal_file = fopen(normal_file_name, "rb");

  }

  //printf("%s\n", normal_file_name);
  strcpy(zip_file_name, normal_file_name);
  pch = strrchr(zip_file_name,'.'); // Returns a pointer to the last occurrence of character in the C string str.
  zip_file_name[(pch-zip_file_name+1)] = 'h' ;
  zip_file_name[(pch-zip_file_name+2)] = 'u' ;
  zip_file_name[(pch-zip_file_name+3)] = 'f' ;
  zip_file_name[(pch-zip_file_name+4)] = 'f' ;
  //zip_file_name[(pch-zip_file_name+5)] = '\n' ;
  zip_file_name[(pch-zip_file_name+5)] = '\0' ;
  //strcat(zip_file_name, ".huff");
  //printf("%s\n", zip_file_name);

  printf("Wait a minute...\n\n");

  priority_to_table(normal_file, priority_array);

  PriorityQueue* pq = (PriorityQueue*)create_priority_queue();

  create_queue_array(pq, priority_array);

  Huffman* tree = (Huffman*)Do_Huffman(pq);

  unsigned char home [Max_string][Max_string]; // Keep the ways
  unsigned char current[Max_string]; // Array keep temp ways

  start_hash_table(home); //begin the table with no way yet
  create_hash_table(home,current,tree,0); // Create a hash about Huffman Tree

  int* size_tree = (int*) malloc(sizeof(int)); //Pointer to get tree_size
  int* trash = (int*) malloc(sizeof(int));
  (*trash) = 0;
  (*size_tree) = altura(tree);
  
  zip_file = fopen(zip_file_name, "wb");   // Create the file with mode binary write

  create_huffman_header(zip_file,tree,size_tree); // Create header
  print_zip_at_file(normal_file,zip_file, home, *size_tree, trash); //Write the compress file

  printf("\n %s created!\n", zip_file_name);
  //print_preorder_tree(tree);
  printf("\n");
  printf("Size of tree: %d  ///", (*size_tree));
  printf("  Size of Trash: %d\n", (*trash));
  fclose(normal_file);
  fclose(zip_file);
  return ;
}
