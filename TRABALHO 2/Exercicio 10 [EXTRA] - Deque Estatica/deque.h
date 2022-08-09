typedef struct deque * Deque;

#define max 10
#define tam 20

Deque cria_deque();
int deque_vazia(Deque d);
int deque_cheia(Deque d);
int insere_fim(Deque d, char elem[tam]);
int remove_ini(Deque d, char elem[]);
int insere_ini(Deque d, char elem[tam]);
int remove_fim(Deque d, char elem[]);
void mostra_deque(Deque d);
void exclui_deque(Deque *d);
Deque apaga_deque(Deque *d);
