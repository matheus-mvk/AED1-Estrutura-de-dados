#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no{
    int info;
    struct no *prox;
};

struct fila{
    struct no *ini;
    struct no *fim;
};

/*
Fila cria_fila()
    Entrada: nenhuma
    Pré Condição: nenhuma
    Processo: cria uma fila vazia
    Pós Condição: nenhuma
    Saída: uma fila vazia criada
*/

Fila cria_fila(){
    Fila f;
    f = (Fila)malloc(sizeof(struct fila));
    if (f != NULL){
    f->ini = NULL;
    f->fim = NULL;
    }
        return f;
}

/*
int fila_vazia(Fila f)
    Entrada: endereço da fila
    Pré Condição: nenhuma
    Processo: verificar se a fila esta vazia
    Pós Condição: retorna 1 se fila vazia, 0 caso contrario
    Saída: nenhuma
*/

int fila_vazia(Fila f){
    if(f->ini == NULL)
        return 1;
    else
        return 0;
}

/*
int insere_fim(Fila f, int elem)
    Entrada: endereço da fila e elemento a ser inserido
    Pré Condição: ter uma fila criada
    Processo: inserir elemento no final da fila
    Pós Condição: retorna 1 se sucesso, 0 se falha
    Saída: fila com um elemento a mais no final
*/

int insere_fim(Fila f, int elem){
    struct no *N;
    N = (struct no *)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->info = elem; // preenche o campo info
    N->prox = NULL; // preenche o campo prox
    if(fila_vazia(f) == 1)
        f->ini = N; // caso fila vazia
    else
        (f->fim)->prox = N;     // se fila com elementos (não vazia)
    f->fim = N; // campo fim aponta para N
        return 1;
}

/*
int remove_ini(Fila f, int *elem)
    Entrada: endereço da fila e elemento a ser removido
    Pré Condição: fila nao estar vazia
    Processo: remover elemento no inicio da fila
    Pós Condição: retorna 1 se sucesso, 0 se falha
    Saída: fila com um elemento a menos no inicio
*/

int remove_ini (Fila f, int *elem){
    if(fila_vazia(f) == 1)
        return 0;
    struct no *aux = f->ini;  // aux aponta para o primeiro nó
    *elem = aux->info;      // retorna o valor do elem

    //verifica se a fila tem um unico nó
    if(f->ini == f->fim)
        f->fim = NULL;

    f->ini = aux->prox;     // retira o primeiro nó da fila
    free(aux);      // libera a memoria alocada
        return 1;  
}

/*
int le_final(Fila f, int elem)
    Entrada: endereço da fila e o elemento do final
    Pré-condição: a fila nao estar vazia
    Processo: ler o elemento informado no final da fila
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-condição: variavel de retorno com o elemento final da fila
*/

int le_final(Fila f, int elem){
    if(fila_vazia(f) == 1)
        return 0;

    struct no *aux = f->ini;
    elem = aux->info;
        return 1;
}

/*
void imprime_fila(Fila f)
    Entrada: endereço da fila 
    Pré-condição: a fila nao estar vazia
    Processo: inserir o elemento informado no final da fila
    Saída: nenhuma
    Pós-condição: a fila de entrada com um elemento a mais
*/

void imprime_fila(Fila f){
    if(fila_vazia(f) == 1)
        printf("A fila esta vazia\n");
    struct no *aux = f->ini;
    for(aux; aux != NULL; aux = aux->prox){
        printf((aux->prox != NULL)? "%d" : "%d", aux->info);
        printf("\n");
    }
}