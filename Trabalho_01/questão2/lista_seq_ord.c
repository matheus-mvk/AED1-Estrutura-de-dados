#include <stdio.h>
#include <stdlib.h>
#include "estat_seq_ord.h"

#define max 20
struct lista{
    int no[max];
    int fim;
};


/*
    Especificações
    --------------
    Entrada: precisa do endereço da lista
    Pré-condição: precisa que a lista exista 
    Processo: retorna o tamanho da lista
    Saída: 0 para erro e o tamanho da lista para sucesso 
    Pós-Condições:retorno do tamanho da lista 
*/
lista* criar_lista(){
    lista *lst;

    lst = (lista *) malloc(sizeof(struct lista));

    if(lst != NULL)
        lst->fim = 0;
    return lst;
}
/*
    Especificações
    --------------
    Entrada: precisa do endereço da lista
    Pré-condição: precisa que a lista exista 
    Processo: retorna o tamanho da lista
    Saída: 0 para erro e o tamanho da lista para sucesso 
    Pós-Condições:retorno do tamanho da lista 
*/
int lista_vazia(lista *lst){
    if(lst->fim == 0)
        return 1; //lista vazia
    else
        return 0; //lista não vazia
}
/*
    Especificações
    --------------
    Entrada: precisa do endereço da lista
    Pré-condição: precisa que a lista exista 
    Processo: retorna o tamanho da lista
    Saída: 0 para erro e o tamanho da lista para sucesso 
    Pós-Condições:retorno do tamanho da lista 
*/
int lista_cheia(lista *lst){
    if(lst->fim == max)
        return 1;
    else
        return 0;
}
/*
    Especificações
    --------------
    Entrada: precisa do endereço da lista
    Pré-condição: precisa que a lista exista 
    Processo: retorna o tamanho da lista
    Saída: 0 para erro e o tamanho da lista para sucesso 
    Pós-Condições:retorno do tamanho da lista 
*/
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
/*
    Especificações
    --------------
    Entrada: precisa do endereço da lista
    Pré-condição: precisa que a lista exista 
    Processo: retorna o tamanho da lista
    Saída: 0 para erro e o tamanho da lista para sucesso 
    Pós-Condições:retorno do tamanho da lista 
*/
int remove_elem(lista *lst, int elem){
    if(lst == NULL)
        return  0;

    int i, aux=0;

    while(aux < lst->fim && lst->no[aux] != elem)
        aux++;
    if(aux == lst->fim)
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
/*
    Especificações
    --------------
    Entrada: precisa do endereço da lista
    Pré-condição: precisa que a lista exista 
    Processo: retorna o tamanho da lista
    Saída: 0 para erro e o tamanho da lista para sucesso 
    Pós-Condições:retorno do tamanho da lista 
*/
int remove_impares(lista *lst){
    if(lst == NULL || lista_vazia(lst) == 1)
        return  0;

    int i, cont = 0, aux=0;

    while(aux <= lst->fim){
        if(lst->no[aux]%2 != 0){
            for(i = aux; i <= lst->fim; i++)
                lst->no[i] = lst->no[i+1];
            
            lst->fim--;
            cont++;
        }
        aux++;
    }
    if(cont == 0)
        return 0;
    return 1;
}
/*
    Especificações
    --------------
    Entrada: precisa do endereço da lista
    Pré-condição: precisa que a lista exista 
    Processo: retorna o tamanho da lista
    Saída: 0 para erro e o tamanho da lista para sucesso 
    Pós-Condições:retorno do tamanho da lista 
*/
int devolve_menor(lista *lst, int *elem){
    if(lst == NULL || lista_vazia(lst) == 1)
        return  0;
    
    *elem = lst->no[0];
    return 1;
}
/*
    Especificações
    --------------
    Entrada: precisa do endereço da lista
    Pré-condição: precisa que a lista exista 
    Processo: retorna o tamanho da lista
    Saída: 0 para erro e o tamanho da lista para sucesso 
    Pós-Condições:retorno do tamanho da lista 
*/
int tamanho(lista *lst){
    if( lista_vazia(lst) == 1)
        return 0;
    return lst->fim;
}
lista* concatena(lista *lst1, lista *lst2){
    
    lista *lst3 = (lista *) malloc(sizeof(struct lista));
    
    if(lst1 == NULL || lst2 == NULL || lst3 == NULL)
        return 0;
    if((lst1->fim + lst2->fim) > max)
        return 0;

    for(int i = 0; i < lst1->fim; i++){
        lst3->no[i] = lst1->no[i];
    }
    for(int i = lst1->fim; i < lst1->fim + lst2->fim; i++){
        lst3->no[i] = lst2->no[i];
    }
    int aux;
    for (int i = 0; i < lst3->fim; i++)
    {
        for (int j = 0; j < lst3->fim; j++)
        {
            if (lst3->no[i] < lst3->no[j])
            {
                aux = lst3->no[i];
                lst3->no[i] = lst3->no[j];
                lst3->no[j] = aux;
            }
        }
    }
    return lst3;
}
