void inserir234(arvore234 *A, arvore234 *pagina ,int num){
    // Árvore vazia
    if (A->filhos[0] == NULL){
        arvore234 *novoNo = (arvore234*)calloc(1,sizeof(arvore234));
        novoNo->chaves[0]=num;
        novoNo->totalChaves=1;
        A->filhos[0]=novoNo;
        novoNo->filhos[0]=A;
        novoNo->filhos[1]=A;
        novoNo->filhos[2]=A;
        novoNo->filhos[3]=A;
        novoNo->pai = A;
        return;
    // Árvore não vazia
    }else{
        // Página folha
        if(pagina->filhos[0] == A && pagina->filhos[1] == A && pagina->filhos[2] == A && pagina->filhos[3] == A){
            // Número de chaves no maximo
            if(pagina->totalChaves == 3){
                while(1){
                    // Página não é raiz
                    if(pagina->pai != A){
                        // Situação 2
                        if(pagina->pai->totalChaves != 3){
                            
                            // Passar elemento mediano para seu pai
                            pagina->pai->chaves[pagina->pai->totalChaves]=pagina->chaves[1];
                            pagina->pai->totalChaves++;
                            BubbleSort(pagina->pai->chaves,pagina->pai->totalChaves);
                            
                            // Realocar filhos
                            realoca(A,pagina->pai);
                          
                            // Subdividir em dois nós
                 
                            arvore234 *novoNo1 = (arvore234*)calloc(1,sizeof(arvore234));
                            novoNo1->chaves[0]=pagina->chaves[0];
                            novoNo1->totalChaves=1;
                            novoNo1->filhos[0]=pagina->filhos[0];
                            novoNo1->filhos[0]->pai=novoNo1;
                            novoNo1->filhos[1]=pagina->filhos[1];
                            novoNo1->filhos[1]->pai=novoNo1;
                            novoNo1->filhos[2]=A;
                            novoNo1->filhos[3]=A;
                            novoNo1->pai = pagina->pai;
                            posiciona(novoNo1);
                            
                            arvore234 *novoNo2 = (arvore234*)calloc(1,sizeof(arvore234));
                            novoNo2->chaves[0]=pagina->chaves[2];
                            novoNo2->totalChaves=1;
                            novoNo2->filhos[0]=pagina->filhos[2];
                            novoNo2->filhos[0]->pai=novoNo2;
                            novoNo2->filhos[1]=pagina->filhos[3];
                            novoNo2->filhos[1]->pai=novoNo2;
                            novoNo2->filhos[2]=A;
                            novoNo2->filhos[3]=A;
                            novoNo2->pai = pagina->pai;
                            posiciona(novoNo2);
                            
                            // Inserir nova chave
                            inserir234(A,pagina->pai,num);
                    
                            break;
                        // Situação 3
                        }else{
                            // repetir recursivamennte
                            pagina=pagina->pai;
                            continue;
                        }
                    // Página é raiz
                    // Aumentar altura da árvore
                    }else{
                        // Subdividir em dois nós
                        arvore234 *novoNo1 = (arvore234*)calloc(1,sizeof(arvore234));
                        novoNo1->chaves[0]=pagina->chaves[0];
                        novoNo1->totalChaves=1;
                        novoNo1->filhos[0]=pagina->filhos[0];
                        novoNo1->filhos[0]->pai=novoNo1;
                        novoNo1->filhos[1]=pagina->filhos[1];
                        novoNo1->filhos[1]->pai=novoNo1;
                        novoNo1->filhos[2]=A;
                        novoNo1->filhos[3]=A;
                        novoNo1->pai = pagina;
                    
                        arvore234 *novoNo2 = (arvore234*)calloc(1,sizeof(arvore234));
                        novoNo2->chaves[0]=pagina->chaves[2];
                        novoNo2->totalChaves=1;
                        novoNo2->filhos[0]=pagina->filhos[2];
                        novoNo2->filhos[0]->pai=novoNo2;
                        novoNo2->filhos[1]=pagina->filhos[3];
                        novoNo2->filhos[1]->pai=novoNo2;
                        novoNo2->filhos[2]=A;
                        novoNo2->filhos[3]=A;
                        novoNo2->pai = pagina;
                        
                        pagina->chaves[0]=pagina->chaves[1];
                        pagina->totalChaves=1;
                        
                        // Deifinir novos filhos
                        pagina->filhos[0]=novoNo1;
                        pagina->filhos[1]=novoNo2;
                        pagina->filhos[2]=A;
                        pagina->filhos[3]=A;
                        
                        // Inserir nova chave
                        inserir234(A,pagina,num);
                        
                        break;
                    }
                }   
            // Número de chaves não no maximo
            }else{
                // Situação 1
                pagina->chaves[pagina->totalChaves]=num;
                pagina->totalChaves++;
                BubbleSort(pagina->chaves,pagina->totalChaves);
            }
        // Página não folha
        }else{
            int pos=0;
            for(int cont=0;cont < pagina->totalChaves;cont++){
                if(num < pagina->chaves[cont]){
                    break;
                }
                pos++;
            }
            inserir234(A,pagina->filhos[pos],num);
        }
    }
}
