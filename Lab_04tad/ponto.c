#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto{
    int x;
    int y;
};

/*
    Especificações
    --------------
    Entrada: nenhuma
    Pré-condição: ponto != NULL
    Processo: Alocar espaço na memória
    Saída: retornar ponto do tipo struct
    Pós-Condições: nenhuma
*/

p* gera_pto(){
    p *ponto;
    ponto = (p*) malloc(sizeof(ponto));
    if(ponto == NULL)
        return 0;
    return ponto;
}

/*
    Especificações
    --------------
    Entrada: Dois inteiros X e Y
    Pré-condição: ponto ser diferente de NULL
    Processo: atribuir os valores de x e y ao ponto
    Saída: 1(sucesso) / 0(falha)
    Pós-Condições: retorna os valores de x e y em ponto
*/

int set_pto(p *ponto, int x, int y){
    if(ponto == NULL)
        return 0;
    ponto->x = x;
    ponto->y = y;
    return 1;
}

/*
    Especificações
    --------------
    Entrada: 1 ponteiro ponto do tipo p e dois ponteiros x e y do tipo inteiro
    Pré-condição: ponto ser diferente de NULL
    Processo: atribuir os valores do ponto(X e Y) aos ponteiros X e Y
    Saída: 1(sucesso)/0(falha)
    Pós-Condições: Retorna os valores do ponto em X e Y
*/

 int get_ponto(p *ponto, int *x, int *y){
    if(ponto == NULL)
        return 0;
    *x = ponto->x;
    *y = ponto->y;
     return 1;
 }

/*
    Especificações
    --------------
    Entrada: ponteiro ponto
    Pré-condição: nenhuma
    Processo: libera ponto
    Saída: 1(sucesso) / 0(falha)
    Pós-Condições: liberação da memória do ponto alocado
*/

void libera_pto(p **ponto){
    free(ponto);  
    *ponto = NULL;
}

/*
    Especificações
    --------------
    Entrada: 2 pontos e um ponto vazio
    Pré-condição: os pontos devem ser diferente de 
    Processo: atribui o calculo da distancia entre os pontos em um ponto
    Saída: 0(falha)
    Pós-Condições: retorna um ponto, sendo ele a distancia entre os dois pontos         informados
*/
//dAB² = (xB – xA)² + (yB – yA)².

p* distancia_pto(p *ponto1, p *ponto2, p *ponto3){
    if(ponto1 == NULL || ponto2 == NULL || ponto3 == NULL)
        return 0;
    ponto3->x = pow(ponto2->x - ponto1->x,2);
    ponto3->y = pow(ponto2->y - ponto1->y,2);

    return ponto3;
}
