#include <stdio.h>
#include <stdlib.h>

int buscaBin(int*, int, int, int);

int main() {

    int N, M;

    scanf("%d", &N);

    int *v1 = (int*)malloc(sizeof(int*) * N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &v1[i]);
    }

    scanf("%d", &M);

    int *v2 = (int*)malloc(sizeof(int*) * M);

    for (int i = 0; i < M; i++) {
        scanf("%d", &v2[i]);
    }

    for (int i = 0; i < M; i++) {
        int posicao;

        posicao = buscaBin(v1, 0, N, v2[i]);

        if(posicao == -1) {
            printf("NAO ACHEI\n");
        } else {
            printf("ACHEI\n");
        }
    }

    free(v1);
    free(v2);

    return 0;
}

int buscaBin(int* v, int esq, int dir, int x) {
    int meio;

    if(esq <= dir) {
        meio = (esq + dir) / 2;

        if (v[meio] == x) {
            return meio;

        } else if (v[meio] > x) {
            return buscaBin(v, esq, meio - 1, x);

        } else {
            return buscaBin(v, meio + 1, dir, x);

        }
    }
    return -1;
}