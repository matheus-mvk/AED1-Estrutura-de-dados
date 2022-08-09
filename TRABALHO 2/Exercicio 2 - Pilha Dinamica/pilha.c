#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

struct no{
    int info;
    struct no *prox;
};

/*
Pilha cria_pilha()
    Entrada: nenhuma
    Pré-Condição: nenhuma
    Processo: cria uma pilha e a coloca no estado de pilha vazia
    Saída: endereço da pilha criada
    Pós-Condição: nenhuma
*/

Pilha cria_pilha(){
    return NULL;
}

/*
int pilha_vazia(Pilha p)
    Entrada: uma pilha
    Pré-Condição: nenhuma
    Processo: verifica se a pilha está vazia
    Saída: retorna 1 se pilha vazia, 0 caso contrario
    Pós-Condição: nenhuma
*/


int pilha_vazia(Pilha p){
    if(p == NULL)
        return 1;
    else
        return 0;
}

/*
int push(Pilha *p, int elem)
    Entrada: ponteiro pra pilha e o elem a ser inserido
    Pré-Condição: pilha estar alocada
    Processo: inserir o elemento informado no topo da pilha
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-Condição: a pilha de entrada com um elem a mais
*/

int push(Pilha *p, int elem){
    Pilha N = (Pilha)malloc(sizeof(struct no));
    if(N == NULL)
        return 0;
    N->info = elem;
    N->prox = *p;
    *p = N;
        return 1;
}

/*
int pop(Pilha p, int *elem)
    Entrada: ponteiro pra pilha e o elem de retorno do elem do topo da pilha
    Pré-Condição: pilha nao estar vazia
    Processo: remover o elem que esta no topo da pilha e retorna-lo
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-Condição: a pilha de entrada com um elem a menos e a variavel de retorno com o elem removido
*/

int pop(Pilha *p, int *elem){
    if(pilha_vazia(*p) == 1)
        return 0;
    Pilha aux = *p;
    *elem = aux->info;
    *p = aux->prox;
    free(aux);
        return 1;
}

/*
int le_topo(Pilha p, int *elem)
    Entrada: ponteiro pra pilha e o elem de retorno do elem do topo da pilha
    Pré-Condição: pilha nao estar vazia
    Processo: retornar o elem que esta no topo da pilha SEM remove-lo
    Saída: retorna 1 se sucesso, 0 se falha
    Pós-Condição: variavel de retorno com o elemento do topo
*/

int le_topo(Pilha *p, int *elem){
    if(pilha_vazia(*p) == 1)
        return 0;
    *elem = (*p)->info;
        return 1;
}

/*
void imprime_pilha(Pilha p)
    Entrada: recebe a pilha
    Pré-Condição: pilha nao estar vazia e estar alocada
    Processo: percorre a pilha e a imprime
    Pós-Condição: nenhuma
    Saída: pilha mostrada na tela para o usuario
*/

void imprime_pilha(Pilha p){
    int elem_removido;
    Pilha p2;
    p2 = cria_pilha();

    while(p != NULL){
        printf("%d ", p->info);
        push(&p2, p->info);
        pop(&p, &elem_removido);
    }

    if(pilha_vazia(p2) == 0){
        while(p2 != NULL){
            push(&p, p2->info); 
            pop(&p2, &elem_removido); 
        }
    }
}

/*
int eh_palindromo(char *vet)
    Entrada: ponteiro pra um vetor
    Pré-Condição: nenhuma
    Processo: verifica se uma string de entrada é uma palíndromo
    Pós-Condição: retorna 1 caso for, 0 se não
    Saída: nenhuma
*/

int eh_palindromo(char *vet){
    int len, mid, ele;
    int i;
    Pilha p;
    p = cria_pilha();

    len = strlen(vet);  // tamanho da string
    mid = len/2;
    for(i = 0; i < mid; i++){
        push(&p, vet[i]);   // empilha o elem até a metade
    }      
    i = ((len%2) != 0) ? i+1:i;
        while(vet[i] != '\0'){
            pop(&p, &ele);
            
            if(ele != vet[i]){
                return 0;
            }
            i++;
        }
    return 1;
}

/*
int libera_pilha(Pilha p)
    Entrada: endereço da Pilha
    Pré-condições: pilha ser válida e não estar vazia
    Processo: libera todos os elementos da pilha
    Saída: 1 caso tenha liberado ou 0 caso o contrário
    Pós-condição: pilha sem nenhum elemento
*/

int libera_pilha(Pilha* p)
{
    
    if (*p == NULL)
        return 0;

    while (*p != NULL)
    {
        Pilha aux = *p;
        *p = aux -> prox;
        free(aux);
    }
    
    return 1;
}

/*
void pares_impares(Pilha p)
    Entrada: endereço da pilha
    Pré Condição: pilha nao estar vazia e estar alocada
    Processo: imprime os pares e os impares da pilha de forma separada
    Pós Condição: nenhuma
    Saída: elementos pares e impares mostrados na tela pro usuario
*/

void pares_impares(Pilha p){
    if(p == NULL ||pilha_vazia(p))
        printf("Pilha vazia");
    else{
        int x;  // variavel auxiliar
        Pilha p_par = cria_pilha();
        Pilha p_impar= cria_pilha();
        while(p != NULL){
            if(p->info% 2 == 0){
                push(&p_par, p->info);
            }
            else{
                push(&p_impar, p->info);
            }
            pop(&p,&x);
         }
        printf("---Elementos pares da pilha:---\n");
        imprime_pilha(p_par);
        printf("\n---Elementos impares da pilha:---\n");
        imprime_pilha(p_impar);
    }
}

/*
int elimina(Pilha p, int elem)
    Entrada: endereço da pilha e elemento a ser eliminado
    Pré Condição: pilha nao estar vazia e estar alocada
    Processo: elimina o elemento desejado
    Pós Condição: retorna 1 se sucesso, 0 se falha
    Saída: fila com um elemento a menos
*/

int elimina(Pilha *p, int elem){
    if(pilha_vazia(*p))
        return 0;
    int elem_removido;
    Pilha p2;
    p2 = cria_pilha(); // criando pilha auxiliar

    while((*p) != NULL){
        if((*p)->info == elem){
            pop(p, &elem_removido);
            break;
        }
        push(&p2, (*p)->info);
        pop(p, &elem_removido);
    }

    
    if(pilha_vazia(p2) == 0){
        while(p2 != NULL){
            push(p, p2->info);
            pop(&p2, &elem_removido);
        }
    }
    return 1;
}
