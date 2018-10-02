#include <stdlib.h>
#include <stdio.h>
#include "zip.h"
#include "unzip.h"

int main()
{
   int op = 0;
  
   while(op!= 3 ){
     // Lembrar para colocar opção de comprimir e descomprimir vários arquivos.
        printf("\n--------Menu--------\n\n1 - Compress file\n2 - Decompress file\n3 - Exit\n--------------------\nOption:"); 
        scanf("%d", &op);
        getchar();
        if(op == 1){
            printf(" Welcome to File Compression of Operators!\n");
            zip_file();
        }
        if(op == 2){
            printf(" Welcome to the decompression of Operators files!\n");
            unzip_file();
        }

        if(op == 3)  return 0;        
    }
    return 0;
}
