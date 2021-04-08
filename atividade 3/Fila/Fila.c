#include <stdio.h>
#include <stdlib.h>

struct Item {
    int chave;
};

struct FilaEstatica {
    struct Item *itens;
    int tamanho;
    int inicio, fim;
};

struct FilaEstatica criaFilaEstatica(int);
struct Item criaItem(int);
void enfileirar(struct FilaEstatica *, struct Item);
struct Item desenfileirar(struct FilaEstatica *);
int filaVazia(struct FilaEstatica);
int filaCheia(struct FilaEstatica);
void mostrarFila(struct FilaEstatica);

int main() {
    struct FilaEstatica fila;
    int n, chave;
    char operacao;

    scanf("%d", &n);
    fila = criaFilaEstatica(n);

    while(scanf("\n%c", &operacao) != EOF) {
        if(operacao == 'E') {
            scanf("%d", &chave);
            enfileirar(&fila, criaItem(chave));

        }
        else if(operacao == 'D') {
            if(!filaVazia(fila)) {
                printf("%d\n", desenfileirar(&fila).chave);
            }
        }
    }

    return 0;
}

struct FilaEstatica criaFilaEstatica(int n) {
    struct FilaEstatica fila;
    fila.itens = (struct Item*) malloc(n * sizeof(struct Item));
    fila.tamanho = n;
    fila.inicio = -1;
    fila.fim = -1;
    return fila;
}

struct Item criaItem(int chave) {
    struct Item item;
    item.chave = chave;
    return item;
}

void enfileirar(struct FilaEstatica *fila, struct Item novo) {

    if(!filaCheia(*fila)) {
        if(filaVazia(*fila)) {
            fila->inicio++;
        }

        fila->fim++;
        fila->itens[fila->fim] = novo;
    }
}

struct Item desenfileirar(struct FilaEstatica *fila) {
    struct Item item;

    if(!filaVazia(*fila)) {
        item = fila->itens[fila->inicio];

        if(fila->inicio != fila->fim) {
            fila->inicio++;
        }
        else {
            fila->inicio = -1;
            fila->fim = -1;
        }
    }
    return item;
}

int filaVazia(struct FilaEstatica fila) {
    return fila.inicio == -1 && fila.fim == -1 || fila.inicio > fila.fim;
}

int filaCheia(struct FilaEstatica fila) {
    return fila.fim == fila.tamanho - 1;
}

void mostrarFila(struct FilaEstatica f) {
    int i;
    if(!filaVazia(f)) {
        for(i=f.inicio; i<=f.fim; i++) {
            printf("%d%s", f.itens[i].chave, i<f.fim?" ":"\n");
        }
    }
}