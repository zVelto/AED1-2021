#include <stdio.h>
#include <stdlib.h>

struct Item {
    int chave;
};

struct Lista {
    struct Item *itens;
    int quantidade, tamanho;
};

struct Item criaItem(int);
struct Lista criaLista(int);
int listaCheia(struct Lista);
void inserirLista(struct Lista *, struct Item);
int removerLista(struct Lista *, struct Item);
void mostrarLista(struct Lista);
int buscarLista(struct Lista, struct Item);

int main() {
    struct Lista lista;
    int q, chave;
    char operacao;
    scanf("%d", &q);
    lista = criaLista(q);

    while(scanf("\n%c", &operacao) != EOF) {
        if(operacao == 'I') {
            scanf("%d", &chave);
            inserirLista(&lista, criaItem(chave));
        }
        else {
            scanf("%d", &chave);
            removerLista(&lista, criaItem(chave));
        }
    }
    mostrarLista(lista);

    free(lista.itens);
    return 0;
}

struct Item criaItem(int chave) {
    struct Item item;
    item.chave = chave;
    return item;
}

struct Lista criaLista(int n) {
    struct Lista l;
    l.itens = (struct Item*) malloc(n * sizeof(struct Item));

    if(l.itens != NULL) {
        l.quantidade = 0;
        l.tamanho = n;
    }
    return l;
}

void inserirLista(struct Lista *lista, struct Item novo) {
    int i, achei, j;

    if(lista->quantidade < lista->tamanho && buscarLista(*lista, novo) == -1) {

        achei = 0;
        i = 0;
        while(i < lista->quantidade && !achei) {

            if(lista->itens[i].chave > novo.chave) {
                achei = 1;

            }
            else {
                i++;
            }
        }
        
        for(j = lista->quantidade-1; j>=i; j--) {
            lista->itens[j+1] = lista->itens[j];
        }
        lista->itens[i] = novo;
        //printf("%d\n", lista->itens[i].chave);
        lista->quantidade++;
    }
}

void mostrarLista(struct Lista lista) {
    
    for(int i = 0; i < lista.quantidade; i++) {
        printf("%d\n", lista.itens[i].chave);
    }
}

int buscarLista(struct Lista lista, struct Item item) {
    int esq = 0, dir = lista.quantidade-1, meio;

    while(esq <= dir) {
        meio = (esq + dir) / 2;

        if(lista.itens[meio].chave == item.chave) {
            return meio;
        }
        else if(lista.itens[meio].chave > item.chave) {
            dir = meio - 1;
        }
        else {
            esq = meio + 1;
        }
    }
    return -1;
}

int removerLista(struct Lista *lista, struct Item rem) {

    int i = buscarLista(*lista, rem);

    if(i != -1) {
        for(int j = i; j < lista->quantidade - 1; j++) {
            lista->itens[j] = lista->itens[j + 1];
        }
        lista->quantidade--;
    }
    return i;
}
