#include <stdio.h>
#include <stdlib.h>

struct Heap {
    int tamanho;
    int *itens;
    int quantidade;
};

void constroiHeap(struct Heap *);
void peneirar(struct Heap *, int);
int ultimoPai(int);
int filhoEsquerda(int);
int filhoDireita(int);
void inserirHeap(struct Heap *, int);
int removerHeap(struct Heap *);

int main() {

    int n, valor;
    char operacao;

    scanf("%d", &n);

    struct Heap heap;
    heap.tamanho = n;
    heap.itens = (int*)malloc(sizeof(int) * heap.tamanho);
    heap.quantidade = 0;

    while(scanf("\n%c", &operacao) != EOF) {

        if(operacao == 'I') {

            scanf("%d", &valor);

            if(heap.quantidade < heap.tamanho) {
                inserirHeap(&heap, valor);
            }
        }
        else if(operacao == 'R') {

            if(heap.quantidade > 0) {
                int removido = removerHeap(&heap);
                printf("%d\n", removido);
            }
        }
        else {

            for (int i = 0; i < heap.quantidade; i++) {
                printf("%d%s", heap.itens[i], (i < heap.quantidade - 1 ? " " : "\n"));
            }
        }

    }

    return 0;
}

void constroiHeap(struct Heap *heap){

    for (int i = ultimoPai(heap->quantidade); i >= 0; i--) {
        peneirar(heap, i);
    }
}

void peneirar(struct Heap *heap, int pai) {

    int menor = pai;
    int fe = filhoEsquerda(pai);
    int fd = filhoDireita(pai);

    if (fe < heap->quantidade && heap->itens[fe] <= heap->itens[menor]) {
        menor = fe;
    }

    if (fd < heap->quantidade && heap->itens[fd] <= heap->itens[menor]) {
        menor = fd;
    }

    if(menor != pai) {
        int aux = heap->itens[pai];
        heap->itens[pai] = heap->itens[menor];
        heap->itens[menor] = aux;

        peneirar(heap, menor);
    }
}

int ultimoPai(int n) {
    return (n / 2) - 1;
}

int filhoEsquerda(int pai) {
    return 2 * pai + 1;
}

int filhoDireita(int pai) {
    return 2 * pai + 2;
}

void inserirHeap(struct Heap *heap, int valor) {
    
    heap->itens[heap->quantidade] = valor;
    heap->quantidade++;
    constroiHeap(heap);   
}

int removerHeap(struct Heap *heap) {
    
    int removido = heap->itens[0];

    int aux = heap->itens[0];
    heap->itens[0] = heap->itens[heap->quantidade-1];
    heap->itens[heap->quantidade-1] = aux;

    heap->quantidade--;
    peneirar(heap, 0);

    return removido;
}