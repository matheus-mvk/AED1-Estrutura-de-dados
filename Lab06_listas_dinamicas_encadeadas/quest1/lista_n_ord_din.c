#include <stdio.h>
#include <stdlib.h>
#include "lista_n_ord_din.h"

struct no{
    int info;
    struct no *prox;
};

Lista criar_lista(){
    return NULL;
}

int lista_vazia(Lista *lst){
    if(lst == NULL)
        return 1;//lista vazia
    else
        return 0;//lista n vazia
}

int insere_elem(Lista *lst, int elem){

    Lista N = (Lista) malloc(sizeof(struct no));

    if(N == NULL)
        return 0;//falha ao alocar

    N->info = elem;
    N->prox = *lst;

    *lst = N;
    return 1;
}

int remove_elem(Lista *lst, int elem){
    if(lista_vazia(lst) == 1)
        return 0; //falha ao remover

    Lista aux = *lst;

    if(elem == (*lst)->info){
        *lst = aux->prox;
        free(aux);
        return 1;
    }

    while(aux->prox != NULL && aux->prox->info != elem)
        aux = aux->prox;
    if(aux->prox == NULL)
        return 0;

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;

    free(aux2);
    return 1;
}

void obtem_valor_elem(Lista *lst){
    Lista aux = *lst;
    printf("Lista: ");
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}
