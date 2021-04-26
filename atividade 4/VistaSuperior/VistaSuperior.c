#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void vistaSuperior(struct No *);
void vistaEsquerda(struct No *);
void vistaDireita(struct No *);

int main() {

    struct Arvore *arvore = criaArvore();
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        inserir(arvore, criaNo(num));
    }

    vistaSuperior(arvore->raiz);

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

void vistaSuperior(struct No *r) {

    if(r != NULL) {
        vistaEsquerda(r->esquerda);
        printf("%d\n", r->chave);
        vistaDireita(r->direita);
    }
}

void vistaEsquerda(struct No *r) {

    if(r != NULL) {
        vistaEsquerda(r->esquerda);
        printf("%d\n", r->chave);
    }
}

void vistaDireita(struct No *r) {

    if(r != NULL) {
        printf("%d\n", r->chave);
        vistaDireita(r->direita);
    }
}