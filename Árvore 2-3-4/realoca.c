//Realocar filhos
void realoca(arvore234 *A, arvore234 *pai){
    arvore234 *aux,*aux2;
    int pos,flag=1;
    for(int cont=0;cont <= pai->totalChaves;cont++){
        if(flag==1){
            aux=pai->filhos[cont];
        }else{
            aux=aux2;
            flag=1;
        }
        
        if(aux != A){
            pos=0;
            for(int cont2=0;cont2 < pai->totalChaves;cont2++){
                if(aux->chaves[0] < pai->chaves[cont2]){
                    break;
                }
                pos++;
            }
            if(pos != cont){
                if(pai->filhos[pos] != A){
                    aux2 = pai->filhos[pos];
                    flag=0;
                }
                pai->filhos[pos]=aux;
                pai->filhos[cont]=A;
            }
        }
    }
}
