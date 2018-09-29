#include <stdlib.h>
#include <stdio.h>
#include "zip.h"
#include "unzip.h"

int main()
{
   int op = 0;
  
   while(op!= 3 ){
     // Lembrar para colocar opção de comprimir e descomprimir vários arquivos.
        printf("\nMenu\n\n1 - Comprimir arquivo\n2 - Descomprimir arquivo\n3 - Sair\n\nOpcao: "); 
        scanf("%d", &op);
        getchar();
        if(op == 1){
            printf("Bem-Vindo à compressão de arquivos dos Operadores!\n");
            zip_file();
        }
        if(op == 2){
            printf("Bem-Vindo à compressão de arquivos dos Operadores!\n");
            unzip_file();
        }

        if(op == 3)  return 0;        
    }
    return 0;
}
