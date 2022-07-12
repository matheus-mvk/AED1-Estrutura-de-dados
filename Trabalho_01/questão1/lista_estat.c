#include <stdio.h>
#include <stdlib.h>
#include "lista_estat.h"

#define max 20
struct lista{
    int no[max];
    int fim;
};

/*
Operação: cria_lista()
    -Entrada: nenhuma.
    -Pré-condição: nenhuma.
    -Processo: Instancia uma lista.
    -Saída: Lista com memória alocada.
    -Pós-condição: nenhuma.
*/
lista* criar_lista(){
    lista *lst;

    lst = (lista *) malloc(sizeof(struct lista));

    if(lst != NULL)
        lst->fim = 0;
    return lst;
}
/*
Operação: lista_vazia
    -Entrada: Uma lista.
    -Pré-condição: Lista precisa ser instanciada.
    -Processo: Verifica se a lista está vazia.
    -Saída: 1 se é vazia e 0 se não.
    -Pós-condição: nenhuma
*/

int lista_vazia(lista *lst){
    if(lst->fim == 0)
        return 1; //lista vazia
    else
        return 0; //lista não vazia
}
/*
Operação: lista_cheia
    -Entrada: Uma lista.
    -Pré-condição: Lista precisa ser instanciada.
    -Processo: Verifica se a lista está cheia.
    -Saída: 1 se é cheia e 0 se não.
    -Pós-condição: nenhuma.
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
    Entrada:precissar que a lista exista 
    Pré-condição: lista tem que ser difetente de null 
    Processo: vai inserir o elemento na lista
    Saída: retorna a lista se sucesso e 1 se falhar 
    Pós-Condições: retornar a lista com o valores inseridos 
*/
int insere_elem(lista *lst, int elem){
    
    if(lst == NULL || lista_cheia(lst) == 1)
        return 0; //Elemento não foi inserido

    lst->no[lst->fim] = elem;
    lst->fim++;

    return 1;
}
/*
    Especificações
    --------------
    Entrada: precissar que a lista exista 
    Pré-condição:lista tem que ser difetente de null 
    Processo:vai remover o elemento na lista
    Saída: retorna a lista se sucesso e 0 se falhar
    Pós-Condições:retorna a lista com os elementos removidos 
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
/*
Operação: obtem_valor_elem
    -Entrada: um ponteiro para lst
    -Pré-condição: lista ser diferente de Null e não vazia
    -Processo: imprime os elementos na tela
    -Saída: nenhuma
    -Pós-condição: nenhuma
*/

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
Operação: remove_impares
    -Entrada: um ponteiro para lst
    -Pré-condição: lista ser diferente de null
    -Processo: procura pelos elementos impares e realiza a remoção enquanto aux menor que lista->fim
    -Saída: (1 sucesso)/(0 falha)
    -Pós-condição: elementos removidos
*/

int remove_impares(lista *lst){
    if(lst == NULL)
        return  0;

    int i, cont = 0, aux=0;

    do{
        if(lst->no[aux]%2 != 0){
            for(i = aux+1; i < lst->fim; i++)
                lst->no[i-1] = lst->no[i];
            lst->fim--;
            cont++;
        }
        aux++;
    }while(aux < lst->fim);
    if(cont != 0)
        return 0;
    return 1;
}
/*
Operação: devolve_menor
    -Entrada: um ponteiro para lst e um ponteiro para elem
    -Pré-condição: lst difeente de NULL e lista não ser vazia
    -Processo: realiza uma verificação de qual elemento é menor
    -Saída: (1 sucesso)/ (0 falha)
    -Pós-condição: elemento retorna no ponteiro elem
*/
int devolve_menor(lista *lst, int *elem){
    if(lst == NULL || lista_vazia(lst) == 1)
        return  0;
    
    int aux=0;
    *elem = lst->no[aux];

    do{
        aux++;
        if(*elem > lst->no[aux])
           *elem = lst->no[aux];
        
    }while(aux < lst->fim-1);
    
    return 1;
}
/*
    Especificações
    --------------
    Entrada: 
    Pré-condição:
    Processo:
    Saída: 
    Pós-Condições:
*/
int ordena_lista(lista *lst){
    if(lst == NULL || lista_vazia(lst) == 1)
        return 0;
    int aux;
    for (int i = 0; i < lst->fim; i++)
            {
                for (int j = 0; j < lst->fim; j++)
                {
                    if (lst->no[i] < lst->no[j])
                    {
                        aux = lst->no[i];
                        lst->no[i] = lst->no[j];
                        lst->no[j] = aux;
                    }
                }
            }
    return 1;
}
/*
    Especificações
    --------------
    Entrada: precisa do endereço da lista 
    Pré-condição: precisa que a lista exista 
    Processo: retorna o tamanho da lista
    Saída: 0 para erro e o tamanho da lista para sucesso 
    Pós-Condições: retorno do tamanho da lista 
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
    
    return lst3;
}