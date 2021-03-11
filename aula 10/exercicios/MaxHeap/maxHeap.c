#include <stdio.h>
#include <stdlib.h>

struct Heap {
    int tamanho;
    int *itens;
};

void constroiHeap(struct Heap *);
void peneirar(struct Heap *, int);
int ultimoPai(int);
int filhoEsquerda(int);
int filhoDireita(int);

int main() {

    int n;

    scanf("%d", &n);

    while (n != 0) {

        struct Heap heap;
        heap.tamanho = n;
        heap.itens = (int*)malloc(sizeof(int) * heap.tamanho);

        
        for (int i = 0; i < heap.tamanho; i++) {
            scanf("%d", &heap.itens[i]);
        }

        constroiHeap(&heap);
        
        for (int i = 0; i < heap.tamanho; i++) {
            printf("%d%s", heap.itens[i], (i < heap.tamanho - 1 ? " " : "\n"));
        }

        free(heap.itens);

        scanf("%d", &n);
    }

    return 0;
}

void constroiHeap(struct Heap *heap){

    for (int i = ultimoPai(heap->tamanho); i >= 0; i--) {
        peneirar(heap, i);
    }
}

void peneirar(struct Heap *heap, int pai) {

    int maior = pai;
    int fe = filhoEsquerda(pai);
    int fd = filhoDireita(pai);

    if (fe < heap->tamanho && heap->itens[fe] > heap->itens[maior]) {
        maior = fe;
    }

    if (fd < heap->tamanho && heap->itens[fd] > heap->itens[maior]) {
        maior = fd;
    }

    if(maior != pai) {
        int aux = heap->itens[pai];
        heap->itens[pai] = heap->itens[maior];
        heap->itens[maior] = aux;

        peneirar(heap, maior);
    }
}

int ultimoPai(int n) {
    return (n / 2) - 1;
}

int filhoEsquerda(int pai) {
    return (2 * pai) + 1;
}

int filhoDireita(int pai) {
    return (2 * pai) + 2;
}