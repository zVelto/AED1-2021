#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct No {
    int chave;
    struct No *pai;
    struct No *direita;
    struct No *esquerda;
};

struct Arvore {
    struct No *raiz;
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

int main() {

    struct Arvore *arvore = criaArvore();
    int n, m;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        inserir(arvore, criaNo(num));
    }

    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
        int num;
        scanf("%d", &num);
        remover(arvore, num);
    }

    preOrder(arvore->raiz);

    return 0;
}

struct Arvore * criaArvore() {
    struct Arvore *t = (struct Arvore*) malloc(sizeof(struct Arvore));

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
    }

    if(achei == 0) {
        if(pai != NULL) { // inserindo no folha
            novo->pai = pai;

            if(pai->chave > novo->chave) {// filho da esquerda
                pai->esquerda = novo;
            }
            else { // filho da direita
                pai->direita = novo;
            }
        }
        else { // inserindo no raiz
            t->raiz = novo;
        }
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

struct No * remover(struct Arvore *t, int chave) {
    struct No *anterior = NULL, *filho = t->raiz, *subs;

    while(filho != NULL && filho->chave != chave) {
        anterior = filho;

        if(filho->chave < chave) {
            filho = filho->direita;
        }

        else {
            filho = filho->esquerda;
        }
    }

    if(filho != NULL) {
        if(filho->esquerda == NULL && filho->direita == NULL) // eh folha!
        {
            if(anterior != NULL) // nao eh raiz
            {
                if(anterior->esquerda == filho) // eh filho da esquerda do pai
                {
                    anterior->esquerda = NULL;
                }
                else // eh filho da direita do pai
                {
                    anterior->direita = NULL;
                }
            }
            else // eh raiz
            {
                t->raiz = NULL;
            }
        }
        else if(filho->esquerda != NULL && filho->direita != NULL) // eh pai de dois filhos
        {
            subs = antecessor(filho->esquerda);

            if(anterior != NULL) // nao eh raiz
            {
                if(anterior->esquerda == filho) // filho eh filho da esquerda de seu pai (anterior)
                {
                    anterior->esquerda = subs;
                }
                else // filho eh filho da direita de seu pai (anterior)
                {
                    anterior->direita = subs;
                }
            }
            else // eh raiz
            {
                t->raiz = subs;
            }
            subs->pai = anterior;

            subs->esquerda = filho->esquerda;
            if(filho->esquerda != NULL)
            {
                filho->esquerda->pai = subs;
            }

            subs->direita = filho->direita;
            if(filho->direita != NULL)
            {
                filho->direita->pai = subs;
            }
        }
        else // pai de filho unico
        {
            if(anterior != NULL) // nao eh raiz
            {
                if(anterior->esquerda == filho) // eh filho do lado esquerdo do pai
                {
                    if(filho->esquerda != NULL) // tem filho na esquerda
                    {
                        anterior->esquerda = filho->esquerda; // avo na subarvore esquerda assume o neto da esquerda
                        filho->esquerda->pai = anterior;
                    }
                    else // tem filho na direita
                    {
                        anterior->esquerda = filho->direita; // avo na subarvore esquerda assume o neto da direita
                        filho->direita->pai = anterior;
                    }
                }
                else // eh filho do lado direito
                {
                    if(filho->esquerda != NULL)
                    {
                        anterior->direita = filho->esquerda;
                        filho->esquerda->pai = anterior;
                    }
                    else
                    {
                        anterior->direita = filho->direita;
                        filho->direita->pai = anterior;
                    }
                }
            }
            else // eh raiz
            {
                if(filho->esquerda != NULL) // raiz tem filho na esquerda
                {
                    t->raiz = filho->esquerda;
                }
                else // raiz tem filho na direita
                {
                    t->raiz = filho->direita;
                }
                t->raiz->pai = NULL;
            }
        }
    }
    return filho;
}

struct No * sucessor(struct No *filho)
{
    struct No * anterior = NULL;

    while(filho != NULL)
    {
        anterior = filho;
        filho = filho->esquerda;
    }

    if(anterior->pai->esquerda == anterior) // anterior (sucessor) eh filho esquerdo de seu pai
    {
        anterior->pai->esquerda = anterior->direita;
    }
    else // anterior (sucessor) eh filho direito de seu pai
    {
        anterior->pai->direita = anterior->direita;
    }
    if(anterior->direita != NULL)
    {
        anterior->direita->pai = anterior->pai;
    }
    return anterior;
}

struct No * antecessor(struct No *filho)
{
    struct No * anterior = NULL;

    while(filho != NULL)
    {
        anterior = filho;
        filho = filho->direita;
    }

    if(anterior->pai->esquerda == anterior) // anterior (antecessor) eh filho esquerdo de seu pai
    {
        anterior->pai->esquerda = anterior->esquerda;
    }
    else // anterior (sucessor) eh filho direito de seu pai
    {
        anterior->pai->direita = anterior->esquerda;
    }
    if(anterior->esquerda != NULL)
    {
        anterior->esquerda->pai = anterior->pai;
    }
    return anterior;
}