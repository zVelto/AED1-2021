#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct No {
    int chave;
    struct No *pai;
    struct No *direita;
    struct No *esquerda;
    int altura;
};

struct Arvore {
    struct No *raiz;
    int quantidade;
};

struct Arvore * criaArvore();
struct No * criaNo(int);
void inserir(struct Arvore *, struct No *);
void preOrder(struct No *);
void inOrder(struct No *);
void postOrder(struct No *);
struct No * remover(struct Arvore *, int);
struct No * sucessor(struct No *);
struct No * antecessor(struct No *);
int altura(struct No *);

int main() {

    struct Arvore *arvore = criaArvore();
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        inserir(arvore, criaNo(num));
    }

    printf("%d\n", altura(arvore->raiz));

    return 0;
}

struct Arvore * criaArvore() {
    struct Arvore *t = (struct Arvore*) malloc(sizeof(struct Arvore));

    t->quantidade = 0;

    if(t != NULL) {
        t->raiz = NULL;
    }
    return t;
}

struct No * criaNo(int chave) {
    struct No * no = (struct No*) malloc(sizeof(struct No));

    if(no != NULL) {
        no->chave = chave;
        no->esquerda = NULL;
        no->direita = NULL;
        no->pai = NULL;
    }
    return no;
}

void inserir(struct Arvore *t, struct No *novo) {
    struct No *pai = NULL, *filho = t->raiz;

    int achei = 0;
    int altura = 0;

    while(filho != NULL) {

        pai = filho;

        if(filho->chave == novo->chave) {
            achei = 1;
        }

        if(filho->chave < novo->chave) {
            filho = filho->direita;
        }

        else {
            filho = filho->esquerda;
        }
        altura++;
    }

    if(achei == 0) {
        if(pai != NULL) { // inserindo no folha
            novo->pai = pai;

            if(pai->chave > novo->chave) { // filho da esquerda
                pai->esquerda = novo;
            }
            else { // filho da direita
                pai->direita = novo;
            }
        }
        else { // inserindo no raiz
            t->raiz = novo;
        }
        t->quantidade++;
        novo->altura = altura;
    }
}

void preOrder(struct No *r) {

    if(r != NULL) {
        printf("%d\n", r->chave);
        preOrder(r->esquerda);
        preOrder(r->direita);
    }
}

void postOrder(struct No *r) {

    if(r != NULL) {
        postOrder(r->esquerda);
        postOrder(r->direita);
        printf("%d ", r->chave);
    }
}

void inOrder(struct No *r) {

    if(r != NULL) {
        inOrder(r->esquerda);
        printf("%d ", r->chave);
        inOrder(r->direita);
    }
}

int altura(struct No *r) {

    int maiorAltura = r->altura;
    int alturaFilho1 = 0;
    int alturaFilho2 = 0;

    if(r->esquerda != NULL) {
        alturaFilho1 = altura(r->esquerda);
    }

    if(r->direita != NULL) {
        alturaFilho2 = altura(r->direita);
    }

    if(alturaFilho1 > maiorAltura) {
        maiorAltura = alturaFilho1;
    }

    if(alturaFilho2 > maiorAltura) {
        maiorAltura = alturaFilho2;
    }

    return maiorAltura;
}