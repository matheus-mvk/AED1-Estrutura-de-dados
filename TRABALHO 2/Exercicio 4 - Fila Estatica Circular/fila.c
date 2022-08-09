#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define max 20

struct fila{
    int no[max];
    int ini, fim;
};

/*
Fila cria_fila()
    Entrada: nenhuma
    Pré-condição: nenhuma
    Processo: cria uma fila e a coloca no estado de fila vazia
    Saída: endereço da fila criada
    Pós-condição: nenhuma
*/

Fila cria_fila(){
    Fila f;
    f = (Fila)malloc(sizeof(struct fila));
    if(f!=NULL){
        f->ini = 0;
        f->fim = 0;
    }
    return f;
}

/*
int fila_vazia(Fila f)
    Entrada: endereço da fila
    Pré-condição: nenhuma
    Processo: verifica se a lista esta vazia
    Saída: retorna 1 se vazia ou 0 caso contrario
    Pós-condição: nenhuma
*/

int fila_vazia(Fila f){
    if(f->ini == f-> fim)
        return 1;
    else
        return 0;
}


/*
int fila_cheia(Fila f)
    Entrada: endereço da fila
    Pré-condição: nenhuma
    Processo: verifica se a fila esta cheia
    Saída: retorna 1 se cheia ou 0 caso contrario
    Pós-condição: nenhuma
*/

int fila_cheia(Fila f){
    if(f->ini == (f->fim+1)%max)
        return 1;
    else
        return 0;
}

/*
int insere_fim(Fila f, int elem)
    Entrada: endereço da fila e o elemento a ser inserido 
    Pré-condição: fila não estar cheia
    Processo: inserir o elemento informado no final da fila
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-condição: a fila de entrada com um elemento a mais
*/

int insere_fim(Fila f, int elem){
    if(fila_cheia(f) == 1)
        return 0;
    // insere elem no final
    f->no[f->fim] = elem;
    f->fim = (f->fim+1)%max;    // incremento circular
        return 1;
}


/*
int remove_ini(Fila f, int *elem)
    Entrada: endereço da fila e o ponteiro do elemento a ser inserido 
    Pré-condição: fila não estar vazia
    Processo: remover o elemento no inicio da fila
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-condição: a fila de entradacom um elemento a menos
*/

int remove_ini(Fila f, int *elem){
    if(fila_vazia(f) == 1)
        return 0;
    // remove o elem do inicio
    *elem = f->no[f->ini];
    f->ini = (f->ini+1)%max;    // incremento circular
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
    else{
        for(int i = f->ini; i != f->fim; i = (i+1)%max){
            printf("%d\n", f->no[i]);
        }
    }
    

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
    elem = f->no[f->fim];   // retorna ao elem final
        return 1;
}



