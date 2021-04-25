#include <stdio.h>
#include <stdlib.h>

struct Item {
    int chave;
    struct Item *anterior, *proximo;
};

struct Lista {
    struct Item *primeiro, *ultimo;
};

struct Lista * criaLista();
struct Item * criaItem(int);
int listaVazia(struct Lista *);
void inserir(struct Lista *, struct Item *);
struct Item * remover(struct Lista *, int);
struct Item * buscar(struct Lista *, int);
void mostrarListaPrimeiroUltimo(struct Lista *);
void mostrarListaUltimoPrimeiro(struct Lista *);

int main() {
    struct Lista *lista = criaLista();
    struct Item *it;
    int chave;
    char op;

    while(scanf("\n%c", &op) != EOF) {

        if(op == 'I') {
            scanf("%d", &chave);
            inserir(lista, criaItem(chave));
        }

        else if(op == 'E') {
            scanf("%d", &chave);
            it = remover(lista, chave);

            free(it);
        }

        else if(op == 'M') {
            mostrarListaPrimeiroUltimo(lista);
        }

        else { // U 
            mostrarListaUltimoPrimeiro(lista);
        }
    }
    return 0;
}

struct Lista * criaLista() {
    struct Lista *l = (struct Lista *) malloc(sizeof(struct Lista));

    if(l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

struct Item * criaItem(int chave) {
    struct Item *it = (struct Item *) malloc(sizeof(struct Item));

    if(it != NULL) {
        it->chave = chave;
        it->anterior = NULL;
        it->proximo = NULL;
    }
    return it;
}

int listaVazia(struct Lista *l) {
    return l->primeiro == NULL && l->ultimo == NULL;
}

void inserir(struct Lista *l, struct Item *novo) {
    struct Item *atual = l->primeiro;

    if(buscar(l, novo->chave) == NULL) {
        while(atual != NULL && atual->chave < novo->chave) {
            atual = atual->proximo;
        }

        if(atual != NULL) { // meio ou inicio nao vazia
            novo->anterior = atual->anterior;
            novo->proximo = atual;

            if(atual->anterior != NULL) { // meio
                atual->anterior->proximo = novo;
            }

            else { //inicio
                l->primeiro = novo;
            }

            atual->anterior = novo;
        }
        else if(listaVazia(l)) { // inicio lista vazia
            l->primeiro = novo;
            l->ultimo = novo;
        }
        else { // ultimo
            l->ultimo->proximo = novo;
            novo->anterior = l->ultimo;
            l->ultimo = novo;
        }
    }
}

/*  VERIFICAR ERRO NA PROXIMA AULA:
    SEGMENTATION FAULT AO REMOVER O UNICO ELEMENTO DA LISTA */

struct Item * remover(struct Lista *l, int chave) {
    struct Item *atual = buscar(l, chave);

    if(atual != NULL) {

        if(atual->anterior != NULL) { // eh meio
            atual->anterior->proximo = atual->proximo;
        }

        else { // eh primeiro
            l->primeiro = atual->proximo;
        }

        if(atual->proximo != NULL) { // eh meio
            atual->proximo->anterior = atual->anterior;
        }

        else { // eh ultimo
            l->ultimo = atual->anterior;
        }
    }
    return atual;
}

struct Item * buscar(struct Lista *l, int chave) {
    struct Item *it = l->primeiro;

    while(it != NULL && it->chave < chave) {
        it = it->proximo;
    }

    if(it != NULL && it->chave != chave) {
        it = NULL;
    }
    return it;
}

void mostrarListaPrimeiroUltimo(struct Lista *l) {
    struct Item *it = l->primeiro;

    while(it != NULL) {
        printf("%d ", it->chave);
        it = it->proximo;
    }

    printf("\n");
}

void mostrarListaUltimoPrimeiro(struct Lista *l) {
    struct Item *it = l->ultimo;

    while(it != NULL) {
        printf("%d ", it->chave);
        it = it->anterior;
    }

    printf("\n");
}