#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

struct deque{
    char info[max][tam];
    int ini,fim;
};

Deque cria_deque(){
    Deque d;
    d=(Deque)malloc(sizeof(struct deque));

    if(d!=NULL){
        d->ini=max-1;
        d->fim=max-1;
        int i;
        for(i=0;i<max;i++)
            strcpy(d->info[i],"\0");
    }

    return d;
}

int deque_vazia(Deque d){
    if(d==NULL||d->ini==d->fim)
        return 1;
    return 0;
}

int deque_cheia(Deque d){
    if(d==NULL)
        return 0;
    if(d->ini==(d->fim+1)%max)
        return 1;
    return 0;
}

int insere_fim(Deque d, char elem[tam]){
    if(d==NULL||deque_cheia(d))
        return 0;

    d->fim=(d->fim+1)%max;
    strcpy(d->info[d->fim],elem);

    return 1;
}

int remove_ini(Deque d, char elem[]){
    if(d==NULL||deque_vazia(d))
        return 0;

    d->ini=(d->ini+1)%max;
    strcpy(elem,d->info[d->ini]);
    strcpy(d->info[d->ini],"\0");

    return 1;
}

int insere_ini(Deque d, char elem[tam]){
    if(d==NULL||deque_cheia(d))
        return 0;

    strcpy(d->info[d->ini],elem);
    d->ini=(d->ini-1)%max;

    return 1;
}

int remove_fim(Deque d, char elem[]){
    if(d==NULL||deque_vazia(d))
        return 0;

    strcpy(elem,d->info[d->fim]);
    strcpy(d->info[d->fim],"\0");
    d->fim=(d->fim-1)%max;

    return 1;
}

void mostra_deque(Deque d){
    if(d==NULL||deque_vazia(d))
        printf("\nO deque esta vazio.");
    else{
        int i;
        for(i=0;i<max;i++)
            printf("\n%s",d->info[i]);
    }
}

void exclui_deque(Deque *d){
    free(*d);
    *d=NULL;
}

Deque apaga_deque(Deque *d){
    exclui_deque(d);
    return cria_deque();
}
