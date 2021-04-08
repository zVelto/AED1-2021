#include <stdio.h>
#include <stdlib.h>

struct Item {
    int chave;
};

struct FilaEstaticaCircular {
    struct Item *itens;
    int tamanho;
    int inicio, fim;
};

struct FilaEstaticaCircular criaFilaEstaticaCircular(int);
struct Item criaItem(int);
void enfileirarCirculando(struct FilaEstaticaCircular *, struct Item);
struct Item desenfileirarCirculando(struct FilaEstaticaCircular *);
int filaCircularVazia(struct FilaEstaticaCircular);
int filaCircularCheia(struct FilaEstaticaCircular);
//void mostrarFilaCircular(struct FilaEstaticaCircular);

int main() {
    struct FilaEstaticaCircular fila;
    int n, chave;
    char op;

    scanf("%d", &n);
    fila = criaFilaEstaticaCircular(n);

    while(scanf("\n%c", &op) != EOF) {

        if(op == 'E') {
            scanf("%d", &chave);
            enfileirarCirculando(&fila, criaItem(chave));
        }

        else {
            if(!filaCircularVazia(fila)) {
                printf("%d\n", desenfileirarCirculando(&fila).chave);
            }
        }
    }

    return 0;
}

struct FilaEstaticaCircular criaFilaEstaticaCircular(int n) {
    struct FilaEstaticaCircular fila;
    fila.itens = (struct Item*) malloc(n * sizeof(struct Item));
    fila.tamanho = n;
    fila.inicio = 0;
    fila.fim = 0;
    return fila;
}

struct Item criaItem(int chave) {
    struct Item item;
    item.chave = chave;
    return item;
}

void enfileirarCirculando(struct FilaEstaticaCircular *fila, struct Item novo) {
    if(!filaCircularCheia(*fila)) {
        fila->itens[fila->fim] = novo;
        fila->fim = (fila->fim + 1) % fila->tamanho;
    }
}

struct Item desenfileirarCirculando(struct FilaEstaticaCircular *fila) {
    struct Item item;

    if(!filaCircularVazia(*fila)) {
        item = fila->itens[fila->inicio];
        fila->inicio = (fila->inicio + 1) % fila->tamanho;
    }
    return item;
}

int filaCircularVazia(struct FilaEstaticaCircular fila) {
    return fila.inicio == fila.fim;
}

int filaCircularCheia(struct FilaEstaticaCircular fila) {
    return (fila.fim + 1) % fila.tamanho == fila.inicio;
}

/*
void mostrarFilaCircular(struct FilaEstaticaCircular fila) {

    if(!filaCircularVazia(fila)) {
        for(int i = fila.inicio; i != fila.fim; i = (i+1) % fila.tamanho) {
            printf("%d%s", fila.itens[i].chave, (i+1)%fila.tamanho!=fila.fim?" ":"\n");
        }
    }
}
*/