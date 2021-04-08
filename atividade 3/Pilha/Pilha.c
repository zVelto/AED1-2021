#include <stdio.h>
#include <stdlib.h>

struct Item {
    int chave;
};

struct PilhaEstatica {
    struct Item *itens;
    int tamanho;
    int topo;
};

struct PilhaEstatica criaPilhaEstatica(int);
struct Item criaItem(int);
int pilhaVazia(struct PilhaEstatica);
int pilhaCheia(struct PilhaEstatica);
void empilhar(struct PilhaEstatica *, struct Item);
struct Item desempilhar(struct PilhaEstatica *);
void mostrarPilhaBaseTopo(struct PilhaEstatica);
void mostrarPilhaTopoBase(struct PilhaEstatica);

int main() {
    struct PilhaEstatica pilha;
    int n, chave;
    char operador;

    scanf("%d", &n);
    pilha = criaPilhaEstatica(n);

    while(scanf("\n%c", &operador) != EOF) {

        if(operador == 'E') {
            scanf("%d", &chave);
            empilhar(&pilha, criaItem(chave));
        }
        else if(operador == 'D') {
            if(!pilhaVazia(pilha)) {
                desempilhar(&pilha);
            }
        }
        else if(operador == 'B') {
            mostrarPilhaBaseTopo(pilha);
        }
        else { // T
            mostrarPilhaTopoBase(pilha);
        }
    }
    free(pilha.itens);
    return 0;
}

struct PilhaEstatica criaPilhaEstatica(int n) {
    struct PilhaEstatica pilha;
    pilha.itens = (struct Item*) malloc(n*sizeof(struct Item));
    pilha.tamanho = n;
    pilha.topo = -1;
    return pilha;
}

struct Item criaItem(int chave) {
    struct Item item;
    item.chave = chave;
    return item;
}

int pilhaVazia(struct PilhaEstatica pilha) {
    return pilha.topo == -1;
}

int pilhaCheia(struct PilhaEstatica pilha) {
    return pilha.topo == pilha.tamanho - 1;
}

void empilhar(struct PilhaEstatica *pilha, struct Item novo) {
    
    if(!pilhaCheia(*pilha)) {
        pilha->topo++;
        pilha->itens[pilha->topo] = novo;
    }
}

struct Item desempilhar(struct PilhaEstatica *pilha) {
    struct Item item;

    if(!pilhaVazia(*pilha)) {
        item = pilha->itens[pilha->topo];
        pilha->topo--;
    }
    return item;
}

void mostrarPilhaBaseTopo(struct PilhaEstatica pilha) {

    for(int i = 0; i <= pilha.topo; i++) {
        printf("%d\n", pilha.itens[i].chave);
    }
}

void mostrarPilhaTopoBase(struct PilhaEstatica pilha) {

    for(int i = pilha.topo; i >= 0; i--) {
        printf("%d\n", pilha.itens[i].chave);
    }
}