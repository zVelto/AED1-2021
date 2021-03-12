#include <stdio.h>
#include <stdlib.h>

void quickSort(int *, int, int, int);
int particiona(int *, int, int, int);

int main() {

    int n;

    scanf("%d", &n);

    int *v = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
    }

    quickSort(v, 0, n - 1, n);

    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
    }

    free(v);
    return 0;
}

void quickSort(int *v, int primeiraPosicao, int ultimaPosicao, int n) {

    if (primeiraPosicao < ultimaPosicao) {
        int p = particiona(v, primeiraPosicao, ultimaPosicao, n);
        quickSort(v, primeiraPosicao, p - 1, n);
        quickSort(v, p + 1, ultimaPosicao, n);
    }
}

int particiona(int *v, int primeiraPosicao, int ultimaPosicao, int n) {

    int posicaoAtual = primeiraPosicao;
    int posicaoMenor = primeiraPosicao - 1;

    for(posicaoAtual, posicaoMenor; posicaoAtual < ultimaPosicao; posicaoAtual++){

        if(v[posicaoAtual] < v[ultimaPosicao]) {
            posicaoMenor++;
            int aux = v[posicaoMenor];
            v[posicaoMenor] = v[posicaoAtual];
            v[posicaoAtual] = aux;
        }

        for (int i = 0; i < n; i++) {
            printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
        }
    }

    int aux = v[posicaoMenor + 1];
    v[posicaoMenor + 1] = v[ultimaPosicao];
    v[ultimaPosicao] = aux;

    for (int i = 0; i < n; i++) {
        printf("%d%s", v[i], (i < n - 1 ? " " : "\n"));
    }

    return posicaoMenor + 1;
}