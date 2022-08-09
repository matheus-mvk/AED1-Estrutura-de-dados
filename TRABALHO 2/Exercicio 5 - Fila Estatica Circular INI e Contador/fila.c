#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#define max 20

struct fila{
    int no[max];
    int ini, cont;
};

/*
Fila cria_fila()
    Entrada: nenhuma
    Pré condição: nenhuma
    Processo: cria uma fila e a coloca no estado de vazia
    Saída: endereço da fila criada
    Pós condição: nenhuma
*/

Fila cria_fila(){
    Fila f;
    f = (Fila)malloc(sizeof(struct fila));
    if(f != NULL){
        f->ini = 0;
        f->cont = 0;
    }
    return f;
}

/*
fila_vazia(Fila f)
    Entrada: endereço da fila
    Pré condição: nenhuma
    Processo: verifica se a fila está vazia
    Saída: retorna 1 se fila vazia, 0 se não
    Pós condição: nenhuma
*/

int fila_vazia(Fila f){
    if(f->cont == 0)
        return 1;
    else
        return 0;
}

/*
fila_cheia(Fila f)
    Entrada: endereço da fila
    Pré condição: nenhuma
    Processo: verifica se a fila está cheia
    Saída: retorna 1 se fila cheia, 0 se não
    Pós condição: nenhuma
*/

int fila_cheia(Fila f){
    if(f->cont == max)
        return 1;
    else
        return 0;
}

/*
insere_fim(Fila f, int elem)
    Entrada: endereço da fila e elemento a ser inserido
    Pré condição: fila nao estar cheia
    Processo: insere o elemento no final da fila
    Saída: retorna 1 se sucesso, 0 se falha
    Pós condição: uma fila com um elemento a mais
*/

int insere_fim(Fila f, int elem){
    if(fila_cheia(f) == 1)
        return 0;
    // insere elemento no final
    f->no[(f->ini+f->cont)%max] = elem;
    f->cont++;  // incremento normal
        return 1;
}

/*
remove_ini(Fila f, int *elem)
    Entrada: endereço da fila e ponteiro do elemento
    Pré condição: fila nao estar vazia
    Processo: remove um elemento no inicio da fila
    Saída: retorna 1 se sucesso, 0 se falha
    Pós condição: uma fila com um elemento a menos
*/

int remove_ini(Fila f, int *elem){
    if(fila_vazia(f) == 1)
        return 0;
    // remove o elemento do inicio
    *elem = f->no[f->ini];
    f->ini = (f->ini+1)%max;    // incremento circular
    f->cont--;  // decremento não circular
        return 1;
}

/*
void imprime_fila(Fila f)
    Entrada: endereço da fila
    Pré condição: fila não estar vazia
    Processo: percorre a fila e a imprime
    Saída: nenhuma
    Pós condição: nenhuma
*/

void imprime_fila(Fila f){
    if(fila_vazia(f) == 1)
        printf("A fila esta vazia\n");
    else{
        int i;
        for(i = 0; i < f->cont; i++){
            printf("%d\n", f->no[(f->ini+i)%max]);
        }
    }
}

/*
int le_final(Fila f, int *elem)
    Entrada: endereço da fila e ponteiro do elemento
    Pré condição: fila não estar vazia
    Processo: ler o elemento informado no final da fila
    Saída: 1 se sucesso, 0 se falha
    Pós condiçao: variavel de retorno com o elemento final da fila
*/

int le_final(Fila f, int elem){
    if(fila_vazia(f) == 1)
        return 0;
    elem = f->no[(f->ini+f->cont-1)%max];
        return 1;
}