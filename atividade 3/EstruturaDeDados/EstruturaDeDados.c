#include <stdio.h>
#include <stdlib.h>

struct Item {
    int chave;
};

struct LES {
    struct Item *itens;
    int quantidade, tamanho;
};

struct FilaEstatica {
    struct Item *itens;
    int tamanho;
    int inicio, fim;
};

struct PilhaEstatica {
    struct Item *itens;
    int tamanho;
    int topo;
};

struct FilaEstaticaCircular {
    struct Item *itens;
    int tamanho;
    int inicio, fim;
};

struct Estrutura {
    struct LES *les;
    struct FilaEstatica *filaEstatica;
    struct PilhaEstatica *pilhaEstatica;
    struct FilaEstaticaCircular *circular;
};

struct Estrutura criaLES(int);
struct Estrutura criaFILA(int);
struct Estrutura criaPILHA(int);
struct Estrutura criaCIRCULAR(int); 

int main() {

    struct FilaEstaticaCircular fila;
    int n;

    scanf("%d", &n);

    struct Estrutura *v = (struct Estrutura *)malloc(sizeof(struct Estrutura) * n);

    char estrutura[9];
    int tamanho;

    for(int i = 0; i < n; i++) {
        scanf("\n%c", estrutura);

        if(estrutura[0] == 'L') {
            //printf("LES cuzinho\n");
            scanf("%d", &tamanho);
            v[i] = criaLES(tamanho);

        } else if(estrutura[0] == 'F') {
            //printf("FILA cuzinho\n");
            scanf("%d", &tamanho);
            v[i] = criaFILA(tamanho);

        } else if(estrutura[0] == 'P') {
            //printf("PILHA cuzinho\n");
            scanf("%d", &tamanho);
            v[i] = criaPILHA(tamanho);

        } else {
            //printf("CIRCULAR cuzinho\n");
            scanf("%d", &tamanho);
            v[i] = criaCIRCULAR(tamanho);

        }
    }

    return 0;
}

struct Estrutura criaLES(int n) {
    
    struct Estrutura LES;

    LES.circular = NULL;
    LES.filaEstatica = NULL;
    LES.pilhaEstatica = NULL;

    LES.les->quantidade = 0;
    LES.les->tamanho = n;
    LES.les->itens = (struct Item*) malloc(n * sizeof(struct Item));

    printf("%d\n", LES.les->tamanho);

    return LES;
}

struct Estrutura criaFILA(int n) {

    struct Estrutura FILA;
    
    FILA.circular = NULL;
    FILA.les = NULL;
    FILA.pilhaEstatica = NULL;

    FILA.filaEstatica->tamanho = n;
    FILA.filaEstatica->inicio = -1;
    FILA.filaEstatica->fim = -1;
    FILA.filaEstatica->itens = (struct Item*) malloc(n * sizeof(struct Item));

    printf("%d\n", FILA.filaEstatica->tamanho);

    return FILA;
}

struct Estrutura criaPILHA(int n) {
    
    struct Estrutura PILHA;
    
    PILHA.circular = NULL;
    PILHA.les = NULL;
    PILHA.filaEstatica = NULL;

    PILHA.pilhaEstatica->tamanho = n;
    PILHA.pilhaEstatica->topo = -1;
    PILHA.pilhaEstatica->itens = (struct Item*) malloc(n * sizeof(struct Item));

    printf("%d\n", PILHA.pilhaEstatica->tamanho);

    return PILHA;
}

struct Estrutura criaCIRCULAR(int n) {
    
    struct Estrutura CIRCULAR;

    CIRCULAR.pilhaEstatica = NULL;
    CIRCULAR.les = NULL;
    CIRCULAR.filaEstatica = NULL;

    CIRCULAR.circular->tamanho = n;
    CIRCULAR.circular->inicio = 0;
    CIRCULAR.circular->fim = 0;
    CIRCULAR.circular->itens = (struct Item*) malloc(n * sizeof(struct Item));

    printf("%d\n", CIRCULAR.circular->tamanho);

    return CIRCULAR;
}