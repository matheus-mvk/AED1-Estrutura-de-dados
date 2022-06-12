#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define max 20
struct lista{
    int no[max];
    int fim;
};


//criar_lista, 
//lista_vazia, 
//lista_cheia,
//insere_elem, 
//remove_elem
//obtem_valor_elem


lista* criar_lista(){
    lista *lst;

    lst = (lista *) malloc(sizeof(struct lista));

    if(lst != NULL)
        lst->fim = 0;
    return lst;
}

int lista_vazia(lista *lst){
    if(lst->fim == 0)
        return 1; //lista vazia
    else
        return 0; //lista não vazia
}

int lista_cheia(lista *lst){
    if(lst->fim == max)
        return 1;
    else
        return 0;
}

int insere_elem_ord(lista *lst, int elem){
    if(lst == NULL || lista_cheia(lst) == 1)
        return 0; //Elemento não foi inserido

    if(lista_vazia(lst) == 1 || elem >= lst->no[lst->fim-1])
        lst->no[lst->fim] = elem;
    else{
        int i,aux = 0;
        while(elem >= lst->no[aux])
            aux++;
        for(i = lst->fim;i > aux; i--)
            lst->no[i] = lst->no[i-1];
        lst->no[aux] = elem;
    }
    lst->fim++;
    return 1;
}
int remove_elem_ord(lista *lst, int elem){
    if(lst == NULL || lista_cheia(lst) == 1 ||
        elem < lst->no[0] || elem > lst->no[lst->fim-1])
        return  0;

    int i, aux=0;

    while(aux < lst->fim && lst->no[aux] < elem)
        aux++;
    if(aux == lst->fim || lst->no[aux] > elem)
        return 0;

    for(i = aux+1; i < lst->fim; i++)
        lst->no[i-1] = lst->no[i];
    
    lst->fim--;
    return 1;
}

void obtem_valor_elem(lista *lst){
    if(lst == NULL || lista_vazia(lst) == 1)
        return;
    printf("Lista: ");
    for(int i = 0; i < lst->fim; i++){
        printf("%d " ,lst->no[i]);
    }
    printf("\n");
}