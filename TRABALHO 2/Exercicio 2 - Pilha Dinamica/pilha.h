#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct no * Pilha;

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int push(Pilha *p, int elem);
int pop(Pilha *p, int *elem);
int le_topo(Pilha *p, int *elem);
void imprime_pilha(Pilha p);
int libera_pilha(Pilha* p);
int eh_palindromo(char *vet);
void pares_impares(Pilha p);
int elimina(Pilha *p, int elem);

#endif