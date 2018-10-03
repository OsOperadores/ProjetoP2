void remover234(arvore234 *A, arvore234 *pagina,int num){
    int flag=0;
    int pos;
    if(pagina != A){
        if (pagina == NULL){
            printf("Árvore vazia");
            return;
        }else{
            for(int cont=0;cont<pagina->totalChaves;cont++){
                if(pagina->chaves[cont] == num){
                    flag = 1;
                    pos=cont;
                    break;
                }
            }
            if(flag == 1){
                // página é folha
                if(pagina->filhos[0] == A && pagina->filhos[1] == A && pagina->filhos[2] == A && pagina->filhos[3] == A){
                    // Mais que o número minimo de chaves
                    if(pagina->totalChaves > 1){
                        pagina->chaves[pos]=20000;
                        BubbleSort(pagina->chaves,pagina->totalChaves);
                        pagina->totalChaves-=1;
                    // Menos ou igual ao número minimo de chaves
                    }else{
                        int posE=-1;
                        int posD=-1;
                        
                        // Verificar se a página tem irmãos
                        if(pagina->pai->filhos[0]==pagina){
                            posD=1;
                        }
                        
                        if(pagina->pai->filhos[1]==pagina){
                            posE=0;
                            posD=2;
                        }
                        
                        if(pagina->pai->filhos[2]==pagina){
                            posE=1;
                            posD=3;
                        }
                        
                        if(pagina->pai->filhos[3]==pagina){
                            posE=2;
                        }
                        
                        int emprestar=1;
                        
                        if(posD != -1){
                            // Verificar pagina tem irmão e pode emprestar
                            if(pagina->pai->filhos[posD] == A || pagina->pai->filhos[posD]->totalChaves == 1){
                                emprestar=0;
                            }else{
                                
                                
                            }
                        }
                        
                        
                    }
                }
               
            }else{
                int pos=0;
                for(int cont=0;cont < pagina->totalChaves;cont++){
                    if(num < pagina->chaves[cont]){
                        break;
                    }
                    pos++;
                }
                remover234(A,pagina->filhos[pos],num);
            }
        }
    }
    printf("Elemento não encontrado");
    return;
}
