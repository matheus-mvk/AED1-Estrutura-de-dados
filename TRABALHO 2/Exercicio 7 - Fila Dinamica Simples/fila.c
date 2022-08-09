#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no{
    int info;
    struct no * prox;
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
    return NULL;
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
    if(f == NULL)
        return 1;
    else    
        return 0;
}

/*
int insere_fim(Fila *f, int elem)
    Entrada: ponteiro pra fila e elemento a ser inserido
    Pré Condição: ter uma fila criada
    Processo: inserir elemento no final da fila
    Pós Condição: retorna 1 se sucesso, 0 se falha
    Saída: fila com um elemento a mais no final
*/

int insere_fim(Fila *f, int elem){
    // Aloca um novo nó e preenche o campo info
    struct no *N;
    N = (Fila)malloc(sizeof(struct no));
    if(N==NULL){
        return 0; // falha, nó nao alocado
    }   
    N->info = elem; // insere o conteudo(valor do elem)

    // trata fila vazia
    if(fila_vazia(*f) == 1){
        N->prox = N;    // faz o novo nó apontar para ele mesmo
        *f = N; // faz a fila apontar para o novo nó(ultimo nó)           
    }
    else{   // trata fila com elementos(1 ou +)
        N->prox = (*f)->prox;   // faz o novo nó apontar o primeiro nó
        (*f)->prox = N; //faz o ultimo nó apontar para o novo nó
        *f = N; //faz a fila apontar para o novo nó(ultimo nó)
    }
        return 1;
}

/*
int remove_ini(Fila *f, int *elem)
    Entrada: ponteiro pra fila e elemento a ser removido
    Pré Condição: fila nao estar vazia
    Processo: remover elemento no inicio da fila
    Pós Condição: retorna 1 se sucesso, 0 se falha
    Saída: fila com um elemento a menos no inicio
*/

int remove_ini(Fila *f, int *elem){
    // trata fila vazia
    if(fila_vazia(*f) == 1)
        return 0;
    Fila aux =(*f)->prox;   //faz aux apontar para o primeiro no
    *elem = aux ->info; //  retorna o valor do nó a ser removido
    if (*f == (*f)->prox)       // trata fila como unico nó
        *f = NULL;
    else // trata fila com mais de 1 elem
        (*f)->prox = aux->prox;
    free(aux);
    return 1;
}

/*
int le_final(Fila *f, int elem)
    Entrada: ponteiro pra fila e o elemento do final
    Pré-condição: a fila nao estar vazia
    Processo: ler o elemento informado no final da fila
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-condição: variavel de retorno com o elemento final da fila
*/

int le_final(Fila f, int *elem){
    if(fila_vazia(f) == 1)
        return 0;
    *elem = f->info;
    return 1;
}

/*
void imprime_fila(Fila f)
    Entrada: ponteiro pra fila
    Pré-condição: a fila nao estar vazia
    Processo: inserir o elemento informado no final da fila
    Saída: nenhuma
    Pós-condição: a fila de entrada com um elemento a mais
*/

void imprime_fila(Fila f){
    if(fila_vazia(f) == 1)
        printf("A fila esta vazia\n");
    else{
        Fila aux=f->prox;
        do{
            printf("%d\n",aux->info);
            aux=aux->prox;
        }while(aux!=f->prox);
    }
}