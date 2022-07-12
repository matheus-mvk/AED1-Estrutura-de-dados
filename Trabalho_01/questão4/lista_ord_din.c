#include <stdio.h>
#include <stdlib.h>
#include "lista_ord_din.h"

struct no{
    int info;
    struct no *prox;
};

/*
Operação: criar_lista
    -Entrada: Nenhuma
    -Pré-condição: cabeçalho ser diferente de NULL
    -Processo: aloca um no cabeçalho
    -Saída: retorna o cabeçalho
    -Pós-condição: nenhuma
*/

Lista criar_lista(){
    Lista cab;
    cab = (Lista) malloc(sizeof(struct no));
    if(cab != NULL){
        cab->prox = NULL;
        cab->info = 0;
    }
    return cab;
}
/*
Operação: lista_vazia
    -Entrada: lst
    -Pré-condição: lst ser diferente de NULL
    -Processo: verificar se o tamanho da lista é 0
    -Saída: (1 sucesso)/(0 falha)
    -Pós-condição: nenhuma
*/
int lista_vazia(Lista lst){
    if(lst->info == 0)
        return 1;//lista vazia
    else
        return 0;//lista n vazia
}
/*
Operação: insere_elem_ord
    -Entrada: um ponteiro para lst e um elemento 
    -Pré-condição: alocação ser diferente de null
    -Processo: procura a posição do elemento na lista e realiza inserção
    -Saída: (1 sucesso)/(0 falaha)
    -Pós-condição: lista com elemento inserido
*/
int insere_elem_ord(Lista *lst, int elem){

    Lista N = (Lista) malloc(sizeof(struct no));

    if(N == NULL)
        return 0;//falha ao alocar

    N->info = elem;
    Lista aux = *lst; 
    
    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;

    N->prox = aux->prox;
    aux->prox = N;
    (*lst)->info++;
    return 1;
}
/*
Operação: remove_elem_ord
    -Entrada: um ponteiro para lst e um elemento 
    -Pré-condição: alocação ser diferente de null e a lista não ser vazia
    -Processo: procura a posição do elemento na lista e realiza remoção
    -Saída: (1 sucesso)/(0 falaha)
    -Pós-condição: lista com elemento inserido
*/
int remove_elem_ord(Lista *lst, int elem){
    if(lista_vazia(*lst) == 1)
        return 0; //falha ao remover

    Lista aux = (*lst)->prox;

    while(aux->prox != NULL && aux->prox->info < elem)
        aux = aux->prox;
    
    if(aux->prox == NULL || aux->prox->info > elem)
        return 0;

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    (*lst)->info--;
    return 1;
}
/*
Operação: obtem_valor_elem
    -Entrada: um ponteiro para lst
    -Pré-condição: nenhuma
    -Processo: imprime os elementos na tela
    -Saída: nenhuma
    -Pós-condição: nenhuma
*/

void obtem_valor_elem(Lista *lst){
    Lista aux = (*lst)->prox;
    printf("Lista: ");
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}
/*
Operação: tamanho
    -Entrada: uma lst
    -Pré-condição: nenhuma
    -Processo: retorna o tamanho da lista na tela
    -Saída: nenhuma
    -Pós-condição: nenhuma
*/
int tamanho(Lista lst){
    return lst->info;
}
/*
Operação: media
    -Entrada: uma lst
    -Pré-condição: nenhuma
    -Processo: realiza a soma dos elementos info da lista
    -Saída: nenhuma
    -Pós-condição: retorna a média dos elementos
*/

float media(Lista lst){
    

    Lista aux = lst->prox;
    
    float media = 0;
    
    for(int i = 0;i < lst->info; i++){
        media = media + aux->info;
        aux = aux->prox;
    }
    return media/lst->info;
}

/*
Operação: iguais
    -Entrada: Duas Listas
    -Pré-condição: Se a lista 2 não existir, não tem como comparar
    -Processo: Compara o conteúdo das listas para verificar a igualdade.
    -Saída: 1 se são iguais e 0 para diferentes
    -Pós-condição: nenhuma
*/

int iguais(Lista lst1, Lista lst2){
    if (lst2 == NULL || lst1 == NULL){
        return 0;
    }
    
    Lista aux = lst1;
    Lista aux2 = lst2;

    while (aux->prox != NULL && aux2->prox != NULL){
        if (aux->info != aux2->info){
            return 0;
        }
        aux = aux->prox;
        aux2 = aux2->prox;
    }

    return 1;  
}