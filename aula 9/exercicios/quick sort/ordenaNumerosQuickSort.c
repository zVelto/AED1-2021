#include <stdio.h>
#include <stdlib.h>

void quickSort(int *, int, int);
int particiona(int *, int, int);

int main() {

    int N;

    scanf("%d", &N);

    int *v = (int*)malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    quickSort(v, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d%s", v[i], (i < N - 1 ? " " : "\n"));
    }

    free(v);
    return 0;
}

void quickSort(int *v, int primeiraPosicao, int ultimaPosicao) {

    if (primeiraPosicao < ultimaPosicao) {
        int p = particiona(v, primeiraPosicao, ultimaPosicao);
        quickSort(v, primeiraPosicao, p - 1);
        quickSort(v, p + 1, ultimaPosicao);
    }
}

int particiona(int *v, int primeiraPosicao, int ultimaPosicao) {

    int posicaoAtual = primeiraPosicao;
    int posicaoMenor = primeiraPosicao - 1;

    for(posicaoAtual, posicaoMenor; posicaoAtual < ultimaPosicao; posicaoAtual++){

        if(v[posicaoAtual] < v[ultimaPosicao]) {
            posicaoMenor++;
            int aux = v[posicaoMenor];
            v[posicaoMenor] = v[posicaoAtual];
            v[posicaoAtual] = aux;
        }
    }

    int aux = v[posicaoMenor + 1];
    v[posicaoMenor + 1] = v[ultimaPosicao];
    v[ultimaPosicao] = aux;
    return posicaoMenor + 1;
}