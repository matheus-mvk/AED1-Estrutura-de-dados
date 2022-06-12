#include <stdio.h>
#include <stdlib.h>


typedef struct ponto p;

p* gera_pto();
int set_pto(p *ponto, int x, int y);
int get_ponto(p *ponto, int *x, int *y);
void libera_pto(p **ponto);
p* distancia_pto(p *ponto1, p *ponto2, p *ponto3);